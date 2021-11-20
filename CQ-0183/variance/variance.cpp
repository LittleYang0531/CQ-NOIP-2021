#include<iostream>
#include<cstdio>
using namespace std;
int n,a[10001],b[7][5],asw=0x7fffffff;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",a+i);
	for(int i=1; i<=6; i++) b[i][1]=a[1],b[i][4]=a[4];
	b[1][2]=a[2],b[1][3]=a[3];
	b[2][2]=a[1]+a[3]-a[2],b[2][3]=a[3];
	b[3][2]=a[2],b[3][3]=a[2]+a[4]-a[3];
	b[4][2]=a[1]+a[3]-a[2],b[4][3]=a[1]+a[4]-a[2];
	b[5][2]=a[1]+a[4]-a[3],b[5][3]=a[2]+a[4]-a[3];
	b[6][2]=a[1]+a[4]-a[3],b[6][3]=a[1]+a[4]-a[2];
	for(int i=1; i<=6; i++) {
		int sum1=0,sum2=0;
		for(int j=1; j<=4; j++) sum1+=b[i][j],sum2+=b[i][j]*b[i][j];
		asw=min(asw,sum2*n-sum1*sum1);
	}
	printf("%d",asw);
}
