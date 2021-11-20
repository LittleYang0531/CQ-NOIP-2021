#include<bits/stdc++.h>
using namespace std;
const int maxn=200007;
int T;
int x;
int vis[maxn];
int t,xy;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	for(int i=1;i<=200007;i++){
		if(vis[i]==1) continue;
		if(i%7==0){
			vis[i]=1;
		}
		else{
			 t=i;
			while(t>=1){
				if(t%10==7){
					vis[i]=1;break;
				}
				t=t/10;
			}
			if(vis[i]==1){
				xy=i;
			   while(xy<=200007){
			   	  vis[xy]=1;
			   	  xy+=i;
			   }	
			}
		}
	}
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>x;
		if(vis[x]==1){
			cout<<"-1"<<"\n";
		}
		else{
			int s=x+1;
			while(s<=200007){
				if(vis[s]==1) s++;
				else{
					cout<<s<<"\n";break;
				}
			}
		}
	}
	return 0;
}
