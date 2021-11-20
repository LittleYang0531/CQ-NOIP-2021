#include<bits/stdc++.h>
using namespace std;
const int M=1e7+5;
int n,m,tot,xpx[M],T,cnt;
bool vis[M];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l=0,r=0;
	for(int i=1;i<=10000000;i++){
		if(vis[i]==0){
			int x=i;bool flag=0;
			while(x){
				if(x%10==7){
					flag=1;
					break;
				}
				x/=10;
			}
			if(flag){
				cnt++;
				for(int j=i;j<=300000;j+=i){
					vis[j]=1;
				}
			}
		}
		if(vis[i]){
			if(vis[i-1]){
				r++;
			}
			else{
				l=i;r=i;
			}
			continue;
		}
		else{
			if(l){
				++tot;
				for(int j=l;j<=r;j++){
					xpx[j]=r;
				}
				l=0;
			}
		}
	//	tot++;
		
	}
	//printf("%d",cnt);
	scanf("%d",&T);
	int x;
	for(int i=1;i<=T;i++){
		scanf("%d",&x);
		if(vis[x]){
			printf("-1\n");
			continue;
		}
		if(vis[x+1]==0){
			printf("%d\n",x+1);
		}
		else{
			if(xpx[x+1])
			printf("%d\n",xpx[x+1]+1);
			else
			printf("10000001\n");
		}
	}
	
	return 0;
}
