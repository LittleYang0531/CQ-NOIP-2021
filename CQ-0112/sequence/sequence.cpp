#include <iostream>
#include <cstdio>
using namespace std;
const int mod=998244353;
int n,m,k,v[303],p2[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192},s[303],tmp[303];
long long ans;
bool check(){
	int num=0,flag=0;tmp[0]=s[0];
	for(int i=0;flag<n||tmp[i]>0;++i){
		flag+=s[i];
		tmp[i+1]=s[i+1]+tmp[i]/2,tmp[i]%=2;
		if(tmp[i]==1) ++num;
	}
	if(num<=k) return 1;
	return 0;
}
int C(int n,int m){
	long long mul=1;
	for(int i=n;i>n-m;--i) mul*=i;
	for(int i=m;i;--i) mul/=i;
	return mul%mod;
}
void dfs(int x,int w,int lst){
	if(x==n+1){
		if(check()){
			int num=1,sy=n;
			for(int i=0;i<=m;++i) num=1ll*num*C(sy,s[i])%mod,sy-=s[i];
			ans=(ans+1ll*w*num%mod)%mod;
		}return;
	}for(int i=lst;i<=m;++i) s[i]++,dfs(x+1,1ll*w*v[i]%mod,i),s[i]--;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;++i) scanf("%d",&v[i]);
	dfs(1,1,0);cout<<ans<<'\n';
	return 0;
}
