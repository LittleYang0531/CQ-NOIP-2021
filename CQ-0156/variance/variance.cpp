#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
typedef long long ll;
int n;
std::vector<int>val;
ll get(std::vector<int>gave){
	ll tot=0,ave=0;
	for(int i=0;i<n;i++)ave+=gave[i];
	tot+=1ll*ave*ave;
	for(int i=0;i<n;i++)tot+=n*gave[i]*gave[i];
	for(int i=0;i<n;i++)tot-=2*ave*gave[i];
	return tot;
}
std::map<std::vector<int>,bool>apr;
ll go(std::vector<int>gave){
	ll res=get(gave);
	double ave=0.0;
	for(int i=0;i<n;i++)ave+=1.0*gave[i];
	ave/=n;
	for(int i=1;i<n-1;i++){
		gave[i]=gave[i+1]+gave[i-1]-gave[i];
			if(!apr[gave]){
				apr[gave]=true;
				res=std::min(res,go(gave));
			}
		gave[i]=gave[i+1]+gave[i-1]-gave[i];
	}
	return res;
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		val.push_back(x);
	}
	apr[val]=true;
	ll ans=go(val);
	printf("%lld",ans);
	return 0;
}
/*
4
1 2 4 6
*/
/*
6
1 5 11 12 15 18
*/
/*
10
6 19 34 35 56 63 82 82 83 99
*/
/*
a'=a-1/n(2ak-a_{k+1}-a_{k-1})
*/
