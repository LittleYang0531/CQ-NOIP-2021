#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define ll long long
const ll MAXN=1e4+5;
ll a[MAXN],v[MAXN];
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1; i<=n; i++)scanf("%lld",a+i);
	ll ans=0,sum=0;
	for(ll i=1; i<=n; i++) {
		ans+=a[i]*a[i];
		sum+=a[i];
	}
	ll Min=0x7fffffffffffffff;
	for(ll w=0; w<=1e7; w++) {
		ll i=rand()%(n-2)+2;
		ll p=a[i-1]+a[i+1]-a[i];
		if(p==a[i])continue;
		ll last=n*ans-sum*sum;
		ll now=n*(ans-a[i]*a[i]+p*p)-(sum-a[i]+p)*(sum-a[i]+p);
		if(now<=last||w>5e6) {
			ans=ans-a[i]*a[i]+p*p;
			sum=sum-a[i]+p;
			a[i]=p;
			if(now<Min)Min=now;
		}
	}
	cout<<Min<<endl;
	return 0;
}
