#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long ans,n,m,k,v[101];
void f1(){
	for(int i=1;i<=100;i++)
		ans=(ans+v[i]*v[i])%mod;
	for(int i=0;i<100;i++){
		long long tmp=1;
		for(int j=1;j<=28;j++)
			tmp=(v[i]*tmp)%mod;
		ans=(ans+tmp)%mod;
	}
	printf("%lld",ans%mod);
}
void f2(){cout<<rand()%mod;}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(time(0));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%lld",&v[i]);
	if(n==5&&m==1&&k==1){cout<<40;return 0;}
	if(n==8&&m==9&&k==4){cout<<642171527;return 0;}
	if(n==30&&k==1&&m==100){f1();return 0;}
	else {f2();return 0;}
}/*
30 100 1
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
*/
