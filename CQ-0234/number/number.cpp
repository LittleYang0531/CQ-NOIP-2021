#include<bits/stdc++.h>
using namespace std;
const int mxn=1e7+1005;
int T;
bool P[mxn];
bool ans[mxn];
int nxt[mxn],pw[20],x[mxn];
void init(int maxn){
	int now=0; 
	for(int i=1;i<1000000;i++){
		int w=0;
		int ti=i; 
		now=0;
		while(ti){
			P[ti*pw[w+1]+7*pw[w]+now]=1;
			w++;
			now=now*10+ti%10;
			ti/=10; 
		}
		P[7*pw[w]+now]=1;	
	} 
	P[7]=1;
	for(int i=1;i<maxn;i++){
		if(P[i]){   
			for(int j=i;j<maxn;j+=i){
				ans[j]=1;	 
			}
		}
	} 
	int lst=0;  
	for(int i=1;i<maxn;i++){ 
		if(!ans[i]){ 
			nxt[lst]=i;
			lst=i;
		}	
	}     
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	pw[0]=1;
	for(int i=1;i<=9;i++){
		pw[i]=pw[i-1]*10;
	} 
	scanf("%d",&T);
	int mx=0;
	for(int i=1;i<=T;i++){
		scanf("%d",&x[i]);
		if(mx<x[i]){
			mx=x[i];
		}
	}
	init(mx+1000);
	for(int i=1;i<=T;i++){ 
		if(ans[x[i]]){
			printf("-1\n");
		}
		else{
			printf("%d\n",nxt[x[i]]);
		}
	}
	return 0;
}
