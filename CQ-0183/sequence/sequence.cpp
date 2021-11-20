#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,k,asw,v[101];
long long sum=1,ss=1;
void dfs(int x,int y,int z,long long vv) {
	long long ssum=sum;
	if(x==0) {
		if(y==z) {
			for(int i=1; i<=y; i++) vv*=v[0],sum*=i;
			asw=(asw+ss/sum)%998244353;
			sum=ssum;
		}
		return;
	}
	dfs(x-1,y,z,vv);
	for(int i=1; i<=y/(1<<x)&&i<=z; i++) {
		vv*=v[x];
		sum*=i;
		dfs(x-1,y-i*(1<<x),z-i,vv);
	}
	sum=ssum;
}
int main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0; i<=m; i++) scanf("%d",v+i);
	int maxm=n;
	for(int i=1; i<=m; i++) maxm*=2;
	for(int i=1; i<=n; i++) ss*=i;
	for(int i=n; i<=maxm; i++) {
		int j=0,ij=i,l;
		while(ij) j++,l=ij&-ij,ij-=l;
		if(j>k) continue;
		dfs(log2(l),i,n,1);
	}
	printf("%d",asw);
}
