#include<bits/stdc++.h>
using namespace std;
int T,n,a[10005005],l;
bool flag[10005005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=2;i<=10005000;i++){
		if(!flag[i]) {
			int u=i,o=0;
			while(u>0){
				if(u%10==7) {
					o=1;
					break;
				}
				u/=10;
			}
			if(o){
				for(int j=i;j<=10005000;j+=i) flag[j]=1;
			}else {
				a[l]=i,l=i;
			}
		}
	}
	while(T--){
		scanf("%d",&n);
		if(flag[n]==1) printf("-1\n");
		else printf("%d\n",a[n]);
	}
	return 0;
}
