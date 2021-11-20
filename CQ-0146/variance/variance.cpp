#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;string s;deque<string>q;
ll ans=1e18;map<string,int>vis;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		char c=x;s+=c;
	}
	q.push_back(s);vis[s]=1;
	while(!q.empty()){
		string k=q.front();q.pop_front();
		int s1=0,s2=0;
		for(int i=0;i<n;i++)s2+=k[i]*k[i],s1+=k[i];
		ans=min(ans,1ll*n*s2-1ll*s1*s1);
		for(int i=1;i<n-1;i++){
			k[i]=k[i-1]+k[i+1]-k[i];
			if(!vis[k])vis[k]=1,q.push_back(k);
			k[i]=k[i-1]+k[i+1]-k[i];
		}
	}
	printf("%lld",ans);
	return 0;
}
