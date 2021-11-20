#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,sum1,sum2;
ll a[10005];
struct op{
	ll t,p;
};
ll calc(op x){return N*(sum2-x.t*x.t+(x.p-x.t)*(x.p-x.t))-(sum1-x.t+x.p-x.t)*(sum1-x.t+x.p-x.t);}
bool operator<(const op &x,const op &y){return calc(x)>calc(y);}
priority_queue<op> q;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&N);
	for(ll i=1;i<=N;i++)
	{
		scanf("%lld",&a[i]);
		sum1+=a[i],sum2+=a[i]*a[i];
	}
	for(ll i=2;i<N;i++)
	{
		op next;
		next.t=a[i],next.p=a[i-1]+a[i+1];
		q.push(next);
	}
	while(N*sum2-sum1*sum1>calc(q.top()))
	{
		sum1=sum1-(q.top().t<<1)+q.top().p;
		sum2=(sum2-(q.top().t)*(q.top().t)+(q.top().p-q.top().t)*(q.top().p-q.top().t));
		op next;
		next.p=q.top().p;
		next.t=q.top().p-q.top().t;
		q.pop();
		q.push(next);
	}
	printf("%lld",N*sum2-sum1*sum1);
}
