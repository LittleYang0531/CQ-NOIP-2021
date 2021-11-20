#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int T=1e6;
const int N=1e7+T,M=7e6,K=8e5+T,Q=2e5+10;
int back(int a){
	int m=a/10*10;
	return a-m;
}
bool check(int a){
	for(;a;a/=10)if(back(a)==7)return true;
	return false;
}
int se[M],a[K],idx,m;
int find(int x){
	int l=1,r=m,mid;
	for(;l<r;){
		mid=l+r>>1;
		if(a[mid]==x)return mid;
		else if(a[mid]<x)l=mid+1;
		else r=mid-1;
	}return l;
}
bool st[N+10];
int t,n[Q],O=-1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",n+i);
		O=max(O,n[i]);
	}
	if(O<=2e5){
		O=4e5;
		for(int i=1;i<=O;i++){
			if(check(i)){
				for(int j=i;j<=O;j+=i)st[j]=1;
			}
			else if(!st[i]){
				a[++m]=i;
			}
		}
		for(int i=1;i<=t;i++){
			if(st[n[i]])puts("-1");
			else printf("%d\n",a[find(n[i])+1]);
		}
		return 0;
	}
	O+=O>=6e6<=7e6?1e6:2e5;
	for(int i=1;i<=O;i++){
		if(check(i)){
			se[++idx]=i;
			for(int j=i;j<=O;j+=i)st[j]=1;
		}
		else if(!st[i]){
			a[++m]=i;
		}
	}
	for(int i=1;i<=t;i++){
		if(st[n[i]])puts("-1");
		else printf("%d\n",a[find(n[i])+1]);
	}
	return 0;
}
