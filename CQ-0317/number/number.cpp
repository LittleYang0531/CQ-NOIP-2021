#include<bits/stdc++.h>
#define N 5000005
using namespace std;
int q,n,num[15],ans;
bool vis[N+10],b[N+10];
int tp[N+10]; 
bool run(int n){
	memset(num,0,sizeof(num));
	int cnt=0;
	while(n){
		if(n%10==7)return 1;
		n/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	for(int i=1;i<=N;i++){
		if(i%10==7||i/10%10==7||i/100%10==7||i/1000%10==7||
		i/10000%10==7||i/100000%10==7||
		i/1000000%10==7){
			b[i]=1;
		}
	}
	for(int i=1;i<=N;i++){
		if(b[i]==1&&vis[i]==0){
			vis[i]=1;
			for(int j=i+i;j<=N;j+=i){
				vis[j]=1;
			}
		}
	}
	for(int i=1;i<=N;i++)
		if(vis[i]==0){
			tp[++ans]=i;
		}
	while(q--){
		scanf("%d",&n);//read
		if(vis[n]==1){
		cout<<"-1\n";
			continue;
		}
		int l=1,r=ans,mid=(l+r)/2;
		while(l<r){
			if(n>tp[mid])l=mid;
			if(n<tp[mid])r=mid;
			if(n==tp[mid]){
				printf("%d\n",tp[mid+1]);
				break;
			}
			mid=(l+r)/2;
		}
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
