#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
bool ST;
inline int f(int x){
	int fl=0;while(x&&!fl)fl|=(x%10==7),x/=10;return fl;
}
const int N=1e7+20,lim=1e7+10;
int stk[N],tp;
bool ban[N];
inline void mark(const int &x){
	int y=x;while(y<=lim)ban[y]=1,y+=x;
}
int st[30],tt;
void write(int x){
	if(!x)return putchar('0'),void();
	while(x)st[++tt]=x%10,x/=10;
	while(tt)putchar(st[tt--]^48);
}
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	For(i,1,lim)if(!ban[i]){
		if(f(i))mark(i);
		else stk[++tp]=i;
	}
	int T=read();while(T--){
		int x=read();
		if(!ban[x])write(*upper_bound(stk+1,stk+1+tp,x)),putchar('\n');
		else puts("-1");
	}
	return 0;
}
