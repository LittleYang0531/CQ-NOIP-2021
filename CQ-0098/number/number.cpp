#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
int T,x,p[N+5],vis[N+5],visp[N+5],tot=0,nxt[N+5];
inline bool ck(int x){
	int t;
	while(x){
		t=x%10;x/=10;
		if(t==7)return true;
	}
	return false;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j;
	cin.tie(0);cout.tie(0);
	cin>>T;vis[0]=1;visp[1]=1;
	for(i=1;i<=N;++i){
		if(!vis[i]&&ck(i))vis[i]=1;
		if(vis[i])p[++tot]=i;
		for(j=1;i*p[j]<=N&&j<=tot;++j){
			vis[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	tot=0;
	for(i=2;i<=N;++i){
		if(visp[i]==0)p[++tot]=i;
		if(!vis[i]&&ck(i))vis[i]=1;
		if(vis[i]){
			for(j=1;p[j]*i<=N&&j<=tot;++j){
				vis[p[j]*i]=1;
			}
		}
		for(j=1;p[j]*i<=N&&j<=tot;++j){
			visp[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	x=-1;
	for(i=N;i>=0;--i){
		nxt[i]=x;
		if(vis[i]==0)x=i;
	}
	while(T--){
		cin>>x;
		if(vis[x])
			cout<<-1<<'\n';
		else
			cout<<nxt[x]<<'\n';
	}
	return 0;
}
