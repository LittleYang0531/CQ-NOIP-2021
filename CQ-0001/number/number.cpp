#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10000001;
int p[10000005],nxt[10000005];
bool s[10000005],vst[10000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=N;i++){
		int w=i,fl=0;
		while(w)fl|=(w%10==7),w/=10;
		if(fl)s[i]=1;
	}
	for(int i=2;i<=N;i++){
		if(!vst[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&i*p[j]<=N;j++){
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=N;i++){
		if(s[i]){
			for(int j=1;j<=p[0]&&i*p[j]<=N;j++)s[i*p[j]]=1;
		}
	}
	for(int i=N;i>=1;i--){
		if(s[i])nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		if(s[n])puts("-1");
		else cout<<nxt[n+1]<<'\n';
	}
	return 0;
}
