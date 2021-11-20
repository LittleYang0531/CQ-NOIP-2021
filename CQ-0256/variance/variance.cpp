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
int n,a[10100],mx,drip[10100];
signed main() {
  std::freopen("variance.in","r",stdin);
  std::freopen("variance.out","w",stdout);
  Read(n);
  for(int i=1; i<=n; ++i) {
    Read(a[i]);
    drip[a[i]]++;
    mx=std::max(mx,a[i]);
  }
  for(int i=mx; i; --i)
    if(drip[i]>=2 && drip[i-1]) drip[i-1]+=drip[i],drip[i]=0;
  for(int i=1; i<=mx; ++i)
    if(drip[i]>=2 && drip[i+1]) drip[i+1]+=drip[i],drip[i]=0;
  int s=0,res=0;
  for(int i=1; i<=mx; ++i) s+=drip[i]*i;
  for(int i=1; i<=mx; ++i) res+=drip[i]*(n*i*i-2*i*s);
  std::printf("%d\n",res+s*s);
  return 0;
}
