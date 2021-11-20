#include<iostream>
#include<cstdio>
const int N=1e7+5;
using namespace std;
//char me1;
int pri[N],ne[N];
bool f[N],v[N];
int su=0;
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
inline void init()
{
	for(int t=1;t<=1000000;t*=10)
	{
		for(int i=0;i<t;i++)
		for(int j=0,fw=1000000/t;j<fw;j++)f[i+7*t+j*t*10]=1;
	}
//	cout<<f[2476325]<<"!!!!\n";
//	for(int i=1;i<1000;i++)cout<<i<<":"<<f[i]<<"!!!!\n";
//	int su=0;
//	for(int i=2;i<N;i++)
//	{
//		if(!v[i])pri[++su]=i;
//		for(int j=1;j<=su&&pri[j]*i<N;j++)
//		{
//			v[i*pri[j]]=1;
//			f[i*pri[j]]|=f[i]|f[pri[j]];
//			if(i*pri[j]==1335)cout<<i<<" "<<pri[j]<<" "<<f[i]<<" "<<f[pri[j]]<<"!!!!\n";
//			if(i%pri[j]==0)break;
//		}
//	}
	for(int i=10000000;i;i--)
	if(f[i])
	{
//		if(i==2476325)cout<<"!!!\n";
		for(int j=i+i;j<N;j+=i)
		{
//			if(j==9999999)cout<<i<<"!!!\n";
			f[j]=1;
		}
	}
	int res=N;
	for(int i=N-1;i;i--)
	{
		ne[i]=res;
		if(!f[i])res=i;
	}
//	cout<<f[10000000]<<"!!!!\n";
}
//char me2;
int main()
{
//	cout<<((&me1-&me2)>>20)<<"!!!!\n";
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int t=read();
	while(t--)
	{
		int x=read();
		if(f[x])cout<<"-1\n";
		else cout<<ne[x]<<"\n";
	}
	return 0;
}
