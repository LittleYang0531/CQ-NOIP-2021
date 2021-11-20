#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<ctime>
#include<unordered_map>
#define ll long long
const int N=10005;
using namespace std;
ll s,s2,ans=1145141919810114514ll;
int a[N];
int n,st;
unordered_map<unsigned ll,bool>mp;
inline char gc()
{
	static char buf[1<<16],*S,*T;
	if(S==T)
	{
		T=(S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}
	return *(S++);
}
#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
void dfs()
{
	unsigned ll x=0;
	for(int i=2;i<n;i++)x=x*601+a[i];
	if(mp.find(x)!=mp.end())return;
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<"!!!!\n"<<s<<" "<<s2<<"!!!!!!!!\n";
	ans=min(ans,s2*n-s*s);
	mp[x]=1;
	for(int i=2;i<n;i++)
	{
		if((double)(clock()-st)/CLOCKS_PER_SEC>0.8)
		{
			cout<<ans<<"\n";
			exit(0);
		}
		int ya=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		
		ll ns=s,ns2=s2;
		s=s-ya+a[i];s2=s2-1ll*ya*ya+1ll*a[i]*a[i];
		dfs();
		s=ns;s2=ns2;
		
		a[i]=ya;
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	st=clock();
	n=read();
	s=0,s2=0;
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i],s2+=1ll*a[i]*a[i];
	dfs();
//	while(1)
//	{
//		bool fl=0;
//		for(int i=2;i<n;i++)
//		{
//			int nv=a[i-1]+a[i+1]-a[i];
//			ll ns=s-a[i]+nv,ns2=s2-1ll*a[i]*a[i]+1ll*nv*nv;
//			if(s2*n-s*s>ns2*n-ns*ns)a[i]=a[i-1]+a[i+1]-a[i],s=ns,s2=ns2,fl=1;
//		}
//		if(!fl)break;
//	}
	cout<<ans<<"\n";
	return 0;
}
/*
15
1 1 3 5 6 6 7 8 9 10 13 14 15 20 20

4274
*/
