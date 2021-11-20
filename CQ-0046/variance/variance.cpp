#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(int i=(a); i>=(b); --i)
#define pb push_back
#define mid ((l+r)>>1)
using namespace std;
//bool happy1041; ll time1=clock();
//
const ll N=1e4;
ll n,tot=0,tot2=0,ltot,ltot2,uans,nans,ans=1e18;
ll a[50005];
//
void SA(){
	double st=2333,et=1e-6,dt=0.9957;
	uans=n*tot2-tot*tot;
	for(double t=st; t>=et; t*=dt){
//		cout<<t<<endl;
		ll x=rand()%(n-2)+2,num=a[x+1]+a[x-1]-a[x];
		ll nans=n*(tot2-a[x]*a[x]+num*num)-(tot-a[x]+num)*(tot-a[x]+num);
		if(1.0*(nans-uans)/uans<1.0*rand()/RAND_MAX*t/st){
			tot2=tot2-a[x]*a[x]+num*num;
			tot=tot-a[x]+num;
			a[x]=num;
			uans=nans;
		}
		ans=min(uans,ans);
//		FOR(j,1,n)
//		printf("%lld ",a[j]); printf("\n");
	}
}
//
ll gt(){
	ll k=0,t=1; char c=getchar();
	while(!isdigit(c)) t=(c=='-')?-1:t,c=getchar();
	while(isdigit(c)) k=(k<<1)+(k<<3)+(c^48),c=getchar();
	return k*t;
}
void wr(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wr(x/10);
	putchar(x%10+'0');
	return;
}
//bool Happy1041;
//void usage(){ ll time2=clock();
//	cout<<(&Happy1041-&happy1041)/1024/1024<<"Mb,"<<time2-time1<<"ms\n";
//}
int main(){
	srand(23333333);
//	usage();
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=gt();
	FOR(i,1,n){ a[i]=gt();	
		tot+=a[i];
		tot2+=a[i]*a[i];
	} 
	ltot=tot;
//	dfs(1);
//	else 
	FOR(i,1,4500) SA();
	printf("%lld",ans);
	return 0;
}




