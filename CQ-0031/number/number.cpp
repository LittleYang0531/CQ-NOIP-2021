/*---And in that light,I find deliverance.---*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1.1e7+5;
bool p[maxn];
int nex[maxn];
bool check(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
void init(){
	for(int i=1;i<=1.1e7;++i){
		if(p[i]) continue;
		if(!check(i)) continue;
		for(int j=i;j<=1.1e7;j+=i) p[j]=1;
	}
	for(int i=1.1e7;i>=1;--i){
		if(p[i+1]==0) nex[i]=i+1;
		else nex[i]=nex[i+1]; 
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	init();
	int T;cin>>T;
	while(T--){
		int x;cin>>x;
		if(p[x]) cout<<-1<<'\n';
		else cout<<nex[x]<<'\n';
	}
	return 0;
}
