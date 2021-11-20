#include<bits/stdc++.h>
template<class I>
void Read(I& x) {
  x=0;
  char c=getchar();
  bool f=0;
  while(c<'0' || c>'9') {
    if(c=='-') f=1;
    c=getchar();
  }
  while(c>='0' && c<='9') {
    x=x*10+(c&15);
    c=getchar();
  }
  if(f) x=-x;
}
template<class I,class... Args>
void Read(I& x,Args&... args) {
  Read(x),Read(args...);
}
/*
  For m<=12 (50):
    fix a mask of at most m elements;
    if s[0]=1, p[0]%2=1
    if s[1]=1, (p[1]%2=1 and p[0]<=1) or (p[0]>1 and p[1]%2!=p[0]%2)
    if s[2]=1 ...
    observation: if the mask if fixed, then the number of every color in {a} is the same for some n,
      which means the contribution is the same.
    proof? which sb will do this.
    the rest of the problem is how to get the number of every color.
    my construction:
      1). for popcnt(mask)>n: {a} is sans response;
      2). for popcnt(mask)=n: {a} is the way the mask is;
      3). for popcnt(mask)<n: first take popcnt(mask) elements to fill {a} as the way the mask is.
        then take the left ones to construct this.
    eventually we get the number of every color, and it's easy to compute this with the trick "the permutations of MSets".
    wait a minute me smooth-talking son of bitch, how will this be if n>=2*popcnt(mask)?
    oh I come up with a way: we take a digit out like the frontest one, like:
      1000...1010110...
      take the frontest one out:
      0000...1010110... (now we have n-popcnt(mask)+1 resting ones)
      and put the rest like, and let H=n-popcnt(mask):
      0111  ...  1010110
      <- H 1s ->
      lastly put the only rest one:
      1000...1010110
    that's enough.
    time complexity: O(n^2*2^m)=3686400.
  For the entire problem:
*/
constexpr int kMod=998244353;
int n,m,k,v[200];
int norm(long long x) {
  return (x%=kMod)<0?x+kMod:x;
}
int add(int x,const int y) {
  assert(0<=y && y<kMod);
  if((x+=y)>=kMod) return x-kMod;
  return x;
}
void Add(int& x,const int y) {
  x=add(x,y);
}
int mul(const int x,const int y) {
  return norm(static_cast<long long>(x)*y);
}
void Mul(int& x,const int y) {
  x=mul(x,y);
}
int Binpw(int x,int y) {
  assert(y>=0);
  int res=1;
  for(; y; y>>=1,Mul(x,x))
    if(y&1) Mul(res,x);
  return res;
}
int fac[3100],ifac[3100];
namespace Sub12 {
  int a[100],res,cnt[200];
  int Calc() {
    int mask=0;
    for(int i=1; i<=n; ++i) mask+=(1<<a[i]);
    if(__builtin_popcount(mask)>k) return 0;
    int mx=0;
    std::fill(cnt,cnt+m+1,0);
    for(int i=1; i<=n; ++i) cnt[a[i]]++,mx=std::max(mx,a[i]);
    int res=1,coef=fac[std::accumulate(cnt,cnt+m,0)];
    for(int i=1; i<=n; ++i) Mul(res,v[a[i]]);
    for(int i=0; i<=mx; ++i) Mul(coef,ifac[cnt[i]]);
    return mul(res,coef);
  }
  void Dfs(int x,int last) {
    if(x>n) {
      Add(res,Calc());
      return;
    }
    for(int i=last; i<m; ++i) {
      a[x]=i;
      Dfs(x+1,i);
      a[x]=0;
    }
  }
  void main() {
    fac[0]=1;
    for(int i=1; i<3100; ++i) fac[i]=mul(fac[i-1],i);
    ifac[3099]=Binpw(fac[3099],kMod-2);
    for(int i=3098; ~i; --i) ifac[i]=mul(ifac[i+1],i+1);
    Dfs(1,0);
    std::printf("%d\n",res);
  }
}
namespace Sub50 {
  int cnt[200]; // the number of every color.
  void main() {
    const int kEntire=(1<<m);
    int res=0;
    for(int mask=n; mask<=n*kEntire; ++mask) {
      int pcnt=__builtin_popcount(mask);
      if(pcnt>k || pcnt>n) continue;
      if(pcnt==n) { // for popcnt(mask)=n.
        int prd=1;
        for(int i=0; i<30; ++i)
          if(mask&(1<<i)) Mul(prd,v[i]);
        Add(res,prd);
      } else { // for popcnt(mask)<n.
        int rst=n-pcnt,pos=-1;
        for(int i=30; ~i; --i)
          if(mask&(1<<i)) {
            pos=i;
            break;
          }
        assert(~pos);
        for(int i=0; i<30; ++i)
          if(mask&(1<<i)) cnt[i]++;
        int imas=mask;
        while(rst) {
          cnt[pos]--;
          rst++;
          for(int i=pos-1; rst>0 && i>=0; rst--,--i) {
            cnt[i]++;
            if(!(rst-1>0 && i-1>=0)) cnt[i]++,rst--;
          }
          imas=0;
          for(int i=0; i<m; ++i)
            if(cnt[i]) imas+=(1<<i)*cnt[i];
          if(rst==0) break;
          for(int i=pos-1; i>=0; --i)
            if(imas&(1<<i)) {
              pos=i;
              break;
            }
        }
        int prd=1;
        for(int i=0; i<m; ++i)
          if(cnt[i]) Mul(prd,Binpw(v[i],cnt[i]));
        auto Work=[&]() {
          int res=fac[std::accumulate(cnt,cnt+m+1,0)];
          for(int i=0; i<m; ++i) Mul(res,ifac[cnt[i]]);
          return res;
        };
        Add(res,mul(prd,/*something like*/Work()));
        for(int i=0; i<30; ++i) cnt[i]=0;
      }
    }
    std::printf("%d\n",res);
  }
}
namespace SubX {
  void main() {}
}
signed main() {
  std::freopen("sequence.in","r",stdin);
  std::freopen("sequence.out","w",stdout);
  Read(n,m,k);
  m++;
  for(int i=0; i<m; ++i) Read(v[i]);
  if(n<=8 && m<=10) Sub12::main();
  else if(m<=20) Sub50::main();
  else SubX::main();
  return 0;
}
