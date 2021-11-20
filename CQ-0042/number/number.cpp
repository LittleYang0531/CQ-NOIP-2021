#include<bits/stdc++.h>
using namespace std;
const int N=1e7+9;
inline int read()
{
	char ch;
	int op=1,x=0;
	while((ch=getchar())<'0'||ch>'9')if(ch=='-')op=-1;
	x=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')x=x*10+ch-'0';
	return x*op;
}
int n,pnt;
int pm[N/10],pre[N],f[N];
bool b[N];
inline bool chk(int x){while(x){if(x%10==7)return 1;x/=10;}return 0;}
inline bool sol(int x)
{
	int y=x;
	while(y!=1){if(b[pre[y]]||b[x/pre[y]])return 1;y/=pre[y];}
	return 0;
}
void init(int lim)
{
	for(int i=2;i<=lim;i++)
	{
		if(!pre[i])pre[i]=i,pm[++pnt]=i;
		if(!b[i]&&chk(i))b[i]=1;
		if(!b[i]&&sol(i))b[i]=1;
		for(int j=1;j<=pnt;j++)
		{
			if(1ll*i*pm[j]>lim)break;
			pre[i*pm[j]]=pm[j];b[i*pm[j]]|=(b[i]|b[pm[j]]);
			if(i%pm[j]==0)break;
		}
	}
	for(int i=lim;i>=1;i--)f[i]=((!b[i+1])?i+1:f[i+1]);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cas;
	cas=read();init(N-2);
	while(cas--)
	{
		n=read();
		if(b[n])printf("-1\n");
		else printf("%d\n",f[n]);
	}
	return 0;
}
