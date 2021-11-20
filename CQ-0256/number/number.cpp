// take "offline" into account.
/*
  70pts:
    O(v ln(v))
  100pts:
*/
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
int T;
namespace Sub70 {
  constexpr int kInf=200000;
  bool is[200100];
  int dig[50],nxt[200100];
  bool Check(int x) {
    if(x%7==0) return true; // wtf is the statement.
    int tot=0;
    for(; x; x/=10) dig[tot++]=x%10;
    return static_cast<bool>(std::count(dig,dig+tot,7));
  }
  void Pre() {
    for(int i=1; i<=kInf; ++i) {
      if(Check(i)) {
        for(int j=i; j<=kInf; j+=i) is[j]=1;
      }
    }
    for(int i=1,j=1; j<=kInf+1; ++j)
      if(is[j]==0) {
        for(; i<j; ++i) nxt[i]=j;
      }
  }
  void MCase() {
    int x;
    Read(x);
    if(is[x]) {
      std::puts("-1");
      return;
    }
    std::printf("%d\n",nxt[x]);
  }
  void main() {
    for(Pre(); T--;) MCase();
  }
}
namespace SubX {
  constexpr int kInf=10000000;
  bool is[10000100];
  int dig[50],nxt[10000100];
  bool Check(int x) {
    if(x%7==0) return true; // wtf is the statement.
    int tot=0;
    for(; x; x/=10) dig[tot++]=x%10;
    return static_cast<bool>(std::count(dig,dig+tot,7));
  }
  void Pre() {
    for(int i=1; i<=kInf; ++i) {
      if(Check(i)) {
        for(int j=i; j<=kInf; j+=i) is[j]=1;
      }
    }
    for(int i=1,j=1; j<=kInf+1; ++j)
      if(is[j]==0) {
        for(; i<j; ++i) nxt[i]=j;
      }
    nxt[kInf]=kInf+1;
  }
  void MCase() {
    int x;
    Read(x);
    if(is[x]) {
      std::puts("-1");
      return;
    }
    std::printf("%d\n",nxt[x]);
  }
  void main() {
    for(Pre(); T--;) MCase();
  }
}
signed main() {
  std::freopen("number.in","r",stdin);
  std::freopen("number.out","w",stdout);
  Read(T);
  if(T<=10000) Sub70::main();
  else SubX::main();
  return 0;
}
