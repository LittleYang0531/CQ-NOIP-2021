#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	write(x/10);
	putchar('0'+x%10);
}
int a[20000005];
void dfs(int x,bool flag)
{
	if(x>14000000)	return ;
	if(flag && a[x]!=-1)	for(int i=1;i*x<=14000000;++i)	a[i*x]=-1;
	for(int i=0+int(x==0);i<=9;++i)	dfs(x*10+i,flag || (i==7));
}
int main(){
	freopen("number.in","r",stdin);
//	freopen("number4.in","r",stdin);
	freopen("number.out","w",stdout);
	dfs(0,false);
	int lst=-1;
	for(int i=14000000;~i;--i)
	{
		if(a[i]==0)
		{
			a[i]=lst;
			lst=i;
		}
	}
	int t=read();
	while(t-->0)	write(a[read()]),puts("");
	return 0;
}
/*
this is My Castle Town...
*/
