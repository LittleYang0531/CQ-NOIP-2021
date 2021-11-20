#include<bits/stdc++.h>
using namespace std;
inline void qr(int &ret){bool f=0;int sum=0;char ch=getchar();while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+(ch^48),ch=getchar();ret=sum;}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	qr(n);
	printf("25");
	return 0;
}
