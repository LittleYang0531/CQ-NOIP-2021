#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

int g[10000005],nxt,to[10000005];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int check(int x)
{
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=1e7+1;i++)
	{
		if(g[i])continue;
		if(!check(i)){
			to[nxt]=i;nxt=i;
//			cout<<i<<"\n";
			continue;
		}
//		cout<<i<<"\n";
		for(int j=1;j<=(1e7+1)/i;j++)g[i*j]=1;
	}
	int T=read();
	while(T--)
	{
		int x=read();
		if(g[x]){cout<<"-1\n";continue;}
		cout<<to[x]<<"\n";
	}
	return 0;
}
