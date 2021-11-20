#include<bits/stdc++.h>
using namespace std;
const int N=10000005;
bool bj[N];
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;++i){
		if(bj[i])continue;
		int r=log10(i)+1;
		bool flag=0;
		for(int j=0;j<=r-1;++j){
			int t=pow(10,j);
			if((i/t)%10==7){
				flag=1;
				break;
			}
		}
		bj[i]=flag;
		if(flag){
			for(int j=2;i*j<=N;++j){
				bj[i*j]=1;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=N;++i){
		if(!bj[i]){
			a[++cnt]=i;
		}
	}
	int t=0;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		if(bj[x]){
			puts("-1");
		}else{
			int l=1,r=cnt;
			while(l<r){
				int mid=(l+r)>>1;
				if(a[mid]>x){
					r=mid;
				}else{
					l=mid+1;
				}
			}
			printf("%d\n",a[l]);
		}
	}
	return 0;
}
