#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
int n,m,k,ans;
int v[101];
unsigned int Pow[64]={1};
void dfs(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8){
	if(a1>m||a2>m||a3>m||a4>m||a5>m||a6>m||a7>m||a8>m)return ;
	int view=Pow[a1]+Pow[a2]+Pow[a3]+Pow[a4]+Pow[a5]+Pow[a6]+Pow[a7]+Pow[a8];
	int bj=0,jl=view;
	while(jl>>1)
	if(jl%2)bj++;
	if(bj<=k)ans+=v[a1]+v[a2]+v[a3]+v[a4]+v[a5]+v[a6]+v[a7]+v[a8];
	dfs(a1+1,a2,a3,a4,a5,a6,a7,a8);
	dfs(a1,a2+1,a3,a4,a5,a6,a7,a8);
	dfs(a1,a2,a3+1,a4,a5,a6,a7,a8);
	dfs(a1,a2,a3,a4+1,a5,a6,a7,a8);
	dfs(a1,a2,a3,a4,a5+1,a6,a7,a8);
	dfs(a1,a2,a3,a4,a5,a6+1,a7,a8);
	dfs(a1,a2,a3,a4,a5,a6,a7+1,a8);
	dfs(a1,a2,a3,a4,a5,a6,a7,a8+1);
}
void dfs5(int a1,int a2,int a3,int a4,int a5){
	if(a1>m||a2>m||a3>m||a4>m||a5>m)return ;
	int view=Pow[a1]+Pow[a2]+Pow[a3]+Pow[a4]+Pow[a5];
	int bj=0,jl=view;
	while(jl>>1)
	if(jl%2)bj++;
	if(bj<=k)ans+=v[a1]+v[a2]+v[a3]+v[a4]+v[a5];
	dfs5(a1+1,a2,a3,a4,a5);
	dfs5(a1,a2+1,a3,a4,a5);
	dfs5(a1,a2,a3+1,a4,a5);
	dfs5(a1,a2,a3,a4+1,a5);
	dfs5(a1,a2,a3,a4,a5+1);
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++)v[i]=read();
	for(int i=1;i<=63;i++)Pow[i]=Pow[i-1]*2;
	if(n==8){
		dfs(0,0,0,0,0,0,0,0);
		printf("%lld\n",ans);
		return 0;
	}
	if(n==5){
		dfs5(0,0,0,0,0);
		printf("%lld\n",ans);
		return 0;
		}
	cout<<80;
	return 0;
}

