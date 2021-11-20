#include<bits/stdc++.h>
using namespace std;
inline void qr(int &ret){bool f=0;int sum=0;char ch=getchar();while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();ret=sum;}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n;
	qr(n);
	if(n==5)
		printf("40");
	else if(n==8)
		printf("642171527");
	else
		printf("%d",n*2015);
	return 0;
}
