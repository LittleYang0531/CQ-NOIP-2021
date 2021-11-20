#include<iostream>
#include<cstdio>
#include<cmath>
//#define _DEBUG
#ifdef _DEBUG
#endif//DEBUG
#define _INOUT
#ifdef _INOUT
#endif//INOUT
#define God(a) (((a%Mod)+Mod)%Mod)
using namespace std;
const int Mod=998244353;
struct node{
	bool ATP[111];//S的二进制数 
	int Num[31];//选择的ai 
	int One;//1的个数 
	add(int a)
	{
		if(ATP[a])
			add(a+1),ATP[a]=0,One--;
		else
			ATP[a]=1,One++;
	}
}K;
int v[101]={0};
int n=0,m=0,k=0;
unsigned long long ans=0;
unsigned long long Sum()
{
	register unsigned long long ssum=1;
	for(register int i=1;i<=n;i++)
		ssum=God(ssum*v[K.Num[i]]);
	return ssum;
}
void dfs(int num)
{
	if(num>n)
	{
		
		if(K.One<=k)
			ans=God(ans+Sum());
		return;
	}
	for(register int i=0;i<=m;i++)
	{
		node ls=K;
		K.add(i+1);
		K.Num[num]=i;
		dfs(num+1);
		K=ls;
	}
}
int main()
{
	#ifdef _INOUT
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	#endif//INOUT
	scanf(" %d %d %d",&n,&m,&k);
	for(register int i=0;i<=m;i++)
		scanf(" %d",&v[i]);
	register int minn=n;
	dfs(1);
	printf("%llu\n",ans);
	return 0;
}


