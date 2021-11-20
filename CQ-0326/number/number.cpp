//Ã»¸´Ï°µ½Å·À­É¸£¬Î£~ 
#include <iostream>
#include <cstdio>
#include <cmath>
//#include <time.h>
using namespace std;
inline int rd()
{
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')
	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int T,n,ton[10000007],ans[10000006];
bool pd2(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	double time1=clock();
	for(int i=1;i<=10000000;i++){
		if(ton[i])continue;
		if(pd2(i))
		{
			for(int j=1;j<=10000000/i;j++)
			ton[i*j]=1;
		}
	}
	int last=10000001;
	for(int i=10000000;i>=1;i--)
	{
		ans[i]=last;
		if(!ton[i])last=i;
	}
//	double time2=clock();
//	printf("%lf\n",time2-time1);
	T=rd();
	while(T--)
	{
		n=rd();
		if(ton[n]){
			puts("-1");
			continue;
		}
		printf("%d\n",ans[n]);
	}
//	double time3=clock();
//	printf("%lf",time3-time1);
	return 0;
}
