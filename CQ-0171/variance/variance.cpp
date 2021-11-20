#include<bits/stdc++.h>
using namespace std;
const long long base=233;
long long n,ans=1e18,ttt=0;
int cnt=0;
bitset<10000005> vis;
struct ok{
	long long a[16],s,sum,cz,hs;
}t,tt;
queue<ok> q;
map<long long,int> mp;
long long ksm(long long k,long long c){
	if(!c) return 1;
	long long g=ksm(k,(c>>1));
	if(c&1) return g*g*k;
	else return g*g;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	t.s=t.sum=t.hs=0;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&t.a[i]);
		t.s+=t.a[i];
		t.sum=t.sum+t.a[i]*t.a[i];
		t.hs=t.hs*base+t.a[i];
	}
	t.cz=t.sum*n-t.s*tt.s;
	mp[t.hs]=++cnt;
	ans=t.cz;
	q.push(t);
	while(!q.empty()){
		t=q.front();q.pop();
		for(long long i=2;i<n;i++){
			tt=t;
			if((tt.a[i]<<1)==(tt.a[i-1]+tt.a[i+1])) continue;
			tt.s-=tt.a[i];tt.sum-=(tt.a[i]*tt.a[i]);
			tt.hs=tt.hs-tt.a[i]*ksm(base,i-1);
			tt.a[i]=tt.a[i-1]+tt.a[i+1]-tt.a[i];
			tt.hs=tt.hs+tt.a[i]*ksm(base,i-1);
			tt.s+=tt.a[i];tt.sum+=(tt.a[i]*tt.a[i]);
			tt.cz=tt.sum*n-tt.s*tt.s;
			if(!mp.count(tt.hs)) mp[tt.hs]=++cnt;
			else continue;
			q.push(tt);
			ans=min(ans,tt.cz);
		}
		ttt++;
		if(ttt>=400000){
			printf("%lld",ans);
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}

