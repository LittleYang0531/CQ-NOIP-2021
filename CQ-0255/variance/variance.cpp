#include<bits/stdc++.h>
#include <random>
using namespace std;
struct fd{
	long long money;
	void get(int p){money+=p;}
}CCF;
#define AK cout<<"f**k €€¡ê"
#define NOIP ,0
#define You return
#define will f()
#define have zero
#define zero score
#define score in
#define in ,0
int a[3000];
void f(){
	int n;
	cin>>n;
	int sum=0,sum2=0;
	for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i],sum2+=a[i]*a[i];
	mt19937 rnd(clock());
	cout<< n*sum2-sum*sum-rnd()%(n%(rnd()%100+1));
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int $1000000000=1000000000;
	for(int i=1;i<=100000000;++i)CCF.get($1000000000);
	if(CCF.money>100000000000000000ll)You AK NOIP;
	else You will have zero score in NOIP;
	return 0;
}
