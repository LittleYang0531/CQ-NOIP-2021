#include<bits/stdc++.h>
using namespace std;
const long long Mo=998244353;
long long n,m,k,val[105];
long long numcnt=0,waycnt=1,valcnt=1,ans=0,s=0,cntk=0;
void sec(long long x){
	if(x==0)return;
	long long sum=1;
	while(sum*2<=x)sum*=2;
	cntk++;
	if(cntk>k)return;
	sec(x-sum);
}
bool check(){
	cntk=0;
	sec(s);
	if(cntk>k)return false;
	else return true;
}
void found(long long x){//枚举x的个数 
    if(numcnt==n){//已经选完 
    	long long nans;
    	nans=waycnt*valcnt;
    	nans=nans%Mo;
    	if(check())ans+=nans;
    	ans=ans%Mo;
    	return;
	}
    if(x==m){//剩下所有都是m
        long long nans,nvc,ns;
        nvc=valcnt;
        ns=s;
        for(long long i=1;i<=n-numcnt;i++){
        	valcnt*=val[m];
    	    valcnt=valcnt%Mo;
    	    if(x!=0)s+=2<<(x-1);
    		else s++;
		}
    	nans=waycnt*valcnt;
    	nans=nans%Mo;
    	if(check())ans+=nans;
    	ans=ans%Mo;
    	valcnt=nvc;
    	s=ns;
    	return;
	}
    for(long long i=0;i<=n-numcnt;i++){
    	if(i==0){
    		found(x+1);
    		continue;
		}
    	long long twc=1,nvc,ns,nwc;
    	nvc=valcnt;
    	ns=s;
    	nwc=waycnt;
    	for(long long j=n-numcnt;j>n-numcnt-i;j--){
    		twc*=j;
    		valcnt*=val[x];//A(ij)
    		valcnt=valcnt%Mo;
    		if(x!=0)s+=2<<(x-1);
    		else s++;
		}
		for(int j=2;j<=i;j++)twc=twc/j;//C(ij)
    	waycnt*=twc;
    	waycnt=waycnt%Mo;
    	numcnt+=i;
    	found(x+1);
    	numcnt-=i;
    	waycnt=nwc;
    	valcnt=nvc;
    	s=ns;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=0;i<=m;i++)
	    scanf("%lld",&val[i]);
	found(0);//枚举ai个数 
	printf("%lld",ans%Mo);
	return 0;
}
