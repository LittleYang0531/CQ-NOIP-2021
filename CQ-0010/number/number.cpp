#include<bits/stdc++.h>//JZM yyds!!
#define ll long long
#define MOD 
#define MAXN 10000015
#define INF 1e17
#define uns unsigned
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
int pt[30],lp;
inline void print(ll x,char c='\n'){
	if(x<0)putchar('-'),x=-x;
	pt[lp=1]=x%10;
	while(x>9)x/=10,pt[++lp]=x%10;
	while(lp)putchar(pt[lp--]^48);
	putchar(c);
}
inline ll lowbit(ll x){return x&-x;}
int n;
bool p[MAXN],no[MAXN];
int nxt[MAXN];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<MAXN-5;i++)p[i]=p[i/10]|(i%10==7);
	for(int i=1;i<MAXN-5;i++)if(p[i])
		for(int j=i;j<MAXN-5;j+=i)no[j]=1;
	for(int i=MAXN-7;i>=0;i--){
		nxt[i]=nxt[i+1];
		if(!no[i+1])nxt[i]=i+1;
	}
	for(int T=read();T--;){
		n=read();
		if(no[n])print(-1);
		else print(nxt[n]);
	}
	return 0;
}
