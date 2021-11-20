#include<bits/stdc++.h>
using namespace std;
const int N=10005;
long long n,a[N],b[N],qp,sum,tq;
long long ans=1e18;
long long calc(){
	long long res=0;
	for(int i=1;i<=n;i++){
		res+=a[i]*a[i]*n;
	}
	res-=sum*sum;
	ans=min(ans,res);
	return res;
}
void mn(){
	for(int i=1;i<=n;i++)a[i]=b[i];
	long long tt=qp;
	sum=tq;
	for(double t=10000;t>0.0001;t*=0.99999){
		int y=rand()%n+1;
		if(y==1||y==n)continue;
		long long r=a[y];
		long long x=a[y-1]+a[y+1]-r;
		long long sum_=sum-r+x;
		long long dt=(x*x-r*r)*n+sum*sum-sum_*sum_;
		ans=min(ans,tt+dt);
		if(exp(-dt/t)>=double(rand())/RAND_MAX){
			a[y]=x;
			sum=sum_;
			tt+=dt;
		}
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		b[i]=a[i];
		sum+=a[i];
	}
	tq=sum;
	qp=calc();
	while(double(clock())/CLOCKS_PER_SEC<=0.8)mn();
	cout<<ans;
	return 0;
}
