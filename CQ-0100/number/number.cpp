#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7+5;
int vis[maxn],nxt[maxn],query[maxn];
void initial7(){
	for(int i=1;i<=10000000;++i){
		int tmp=i,flag=0;
		while(tmp){
			if(tmp%10==7){
				flag=1;
				break;
			}
			tmp/=10;
		}
		if(flag){
			for(int j=i;j<=10000001;j+=i)
				vis[j]=1;
		}
	}
	nxt[10000000]=10000001;
	for(int i=10000000-1;i>=1;--i){
		if(!vis[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1]; 
		//nxt[i]表示i后面第一个可以报的数
	}
}
void initial6(){
	for(int i=1;i<=1000000;++i){
		int tmp=i,flag=0;
		while(tmp){
			if(tmp%10==7){
				flag=1;
				break;
			}
			tmp/=10;
		}
		if(flag){
			for(int j=i;j<=1000001;j+=i)
				vis[j]=1;
		}
	}
	nxt[1000000]=1000001;
	for(int i=1000000-1;i>=1;--i){
		if(!vis[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1]; 
		//nxt[i]表示i后面第一个可以报的数
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	if(T<=1000) initial6();
	else initial7();
	for(int t=1;t<=T;++t){
		int x;
		cin>>x;
		if(vis[x]) cout<<"-1\n";
		else cout<<nxt[x]<<"\n";
	}
	return 0;
}
