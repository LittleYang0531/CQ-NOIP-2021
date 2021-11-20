#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int Maxx=10000015,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch){
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
const int E=10000007;
char o[Maxx];int Ans[Maxx];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=0;i<=1000000;++i){
		if(o[i])for(int j=0;j<10;++j)o[i*10+j]=1;
		o[i*10+7]=1;
	}
	for(int i=E;i;--i)
	if(o[i])for(int j=i<<1;j<=E;j+=i)o[j]=1;
	for(int i=E,p=E+1;i;--i){
		Ans[i]=p;
		if(!o[i])p=i;
	}
	int T=read()+1;
	while(--T){
		int x=read();
		if(o[x])puts("-1");
		else cout<<Ans[x]<<"\n";
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
/*
2
9999998
10000000
Ans:
10000001
-1
*/
