#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int rd()
{
	int s=0;bool bj=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){bj|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^48);ch=getchar();}
	return bj?-s:s;
}
void ptnum(int x)
{
	if(x>9)ptnum(x/10);
	putchar(x%10^48);
}
void pt(int x,char ch)
{
	if(x<0){putchar('-');x=-x;}
	ptnum(x);putchar(ch);
}
int lim=1e7;
int T;
//bool vst[11000005];
bool tmp[11000005];
//int p[5000005];
int bj[10000005];
int pd(int x)
{
	while(x)
	{
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
void Work()
{
//	vst[1]=1;
	for(int i=2;i<=lim;++i)
	{
		if(!tmp[i])
		{
			tmp[i]=pd(i);
			if(tmp[i])for(int j=i;j<=lim;j+=i)tmp[j]=1;
		}
//		if(!vst[i])
//		{
//			p[++p[0]]=i;
//		}
//		for(int j=1;j<=p[0]&&i*p[j]<=lim;++j)
//		{
//			vst[i*p[j]]=1;
//			if(i%p[j]==0)break;
//		}
	}
	int no=1e7+1;
	for(int i=lim;i>=1;--i)
	{
		bj[i]=no;
		if(!tmp[i])no=i;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Work();
//	for(int i=1;i<=100;++i)cout<<bj[i]<<" ";cout<<endl;
	T=rd();
	int x;
	while(T--)
	{
		x=rd();
		pt(tmp[x]?-1:bj[x],'\n');
	}
	return 0;
}
