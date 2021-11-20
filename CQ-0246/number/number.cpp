#include<bits/stdc++.h>
#define r register
using namespace std;

const int maxn = 1e7+5;
bool isok[maxn];
inline bool check(int n)
{
	if(n%7==0) return 0;
	r int dn=n;
	while(dn!=0)
	{
		if(dn%10==7) return 0;
		dn/=10;
	}
	return 1; 
}
inline bool fen(int dn)  //return 1Êä³ö-1 
{
	r int n=dn;
	if(!check(n)) return 1;
	r bool r3=0;
	for(r int i=2;2*i<=n;++i)
	{
		if(!check(n)) return 1;
		if(n%i==0)
		{
			if(i%10==3) 
			{
				++r3;
				if(r3>=3) return 1;
			}
			if(!check(i)) return 1; 
		}
	}
	return 0;
}
int main(int argc,char **argv)
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	r int T,dq;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&dq);
		if(fen(dq)) printf("-1\n");
		else 
		{
			++dq;
			while(fen(dq)) ++dq;
			printf("%d\n",dq);
		}
	}
	exit(0);
}

