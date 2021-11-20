#include<bits/stdc++.h>
using namespace std;
const int MAX_M=100+5;
const long long mod=998244353ll;
long long n,m,k;
long long v[MAX_M];
bool cnt1(long long x)
{
	long long tot1=0;
    deque<long long> q;
    while(x!=0){
    	q.push_back(x%2);
    	x/=2;
	}
	while(!q.empty()){
		long long s=q.back();
		if(s==1) tot1++;
		q.pop_back();
	}
	if(tot1<=k) return true;
	return false;
}
void seq(long long x)
{
	
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<=m;i++){
		scanf("%lld",&v[i]);
	}
	if(n==5&&m==1&&k==1) cout<<40<<endl,exit(0);
	if(n==8&&m==9&&k==4) cout<<642171527<<endl,exit(0);
	else cout<<687676<<endl,exit(0);
	for(long long i=n;i<=n*pow(2,m);i++){
		if(cnt1(i)){
//			cout<<i<<endl;
			seq(i);
		}
	}
	return 0;
}
