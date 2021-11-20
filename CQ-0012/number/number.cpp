#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=1e7+5;
int n,t;
bool mark[N];
int nxt[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=in();
	n=10000000;
	for(int i=1;i<=n;i++){
		if(!mark[i]){
			int x=i,flag=0;
			while(x){
				if(x%10==7)flag=1;
				x/=10;
			}
			if(flag){
				for(int j=i;j<=n;j+=i)mark[j]=1;
			}
		}
	}
	int las=n+1;
	for(int i=n;i>=1;i--){
		if(!mark[i]){
			nxt[i]=las;
			las=i;
		}
	}
	while(t--){
		n=in();
		if(mark[n])puts("-1");
		else printf("%d\n",nxt[n]); 
	}
	return 0;
}

