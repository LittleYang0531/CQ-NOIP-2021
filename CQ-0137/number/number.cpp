#include <cstdio>
#include <algorithm>
#include <bitset>
#define rint register int
using namespace std;
const int Max=5e5+5;
int T,tmp,a[Max];
bool book[Max];

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f= ch=='-' ? -1:1;
	for(;ch<='9'&&ch>='0';ch=getchar()) x=(x<<1)+(x<<3)+(ch-'0');
	return x*f;
}

inline int check(int x)
{
	if(!x) return 0;
	if(x%10==7) return 1;
	return check(x/10);
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    T=read();
    for(rint i=1;i<=T;i++) a[i]=read();
    int o=1;
    if(T>10000)
    {
    	bitset <15000000> boo;
    	for(rint i=1;i<=15000000;i++)
    {
    	if(!boo[i]&&check(i))
		{
		boo[i]=1;
		for(rint j=2;j*i<=15000000;j++) boo[j*i]=1;
		}
	}
	while(o<=T)
	{
		if(boo[a[o]]) printf("-1\n");
		else
		{
			int l=a[o]+1;
			while(boo[l]) l++;
			printf("%d\n",l);
		}
		o++;
	}
	}
	else 
	{
	for(rint i=1;i<=Max;i++)
    {
    	if(!book[i]&&check(i))
		{
		book[i]=1;
		for(rint j=2;j*i<=Max;j++) book[j*i]=1;
		}
	}
	while(o<=T)
	{
		if(book[a[o]]) printf("-1\n");
		else
		{
			int l=a[o]+1;
			while(book[l]) l++;
			printf("%d\n",l);
		}
		o++;
	}
	}
	return 0;
}
