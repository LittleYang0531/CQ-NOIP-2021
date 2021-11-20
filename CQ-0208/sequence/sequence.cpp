#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while('0'<=ch&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*w;
}
int n,m,k;
int numm;
int v[105];
int ans[105];
inline void dfs(int x){
	if(x>n){
		int s=0,xx=1;
		for(int i=1;i<=n;i++){
			s+=1<<ans[i];
			xx*=v[ans[i]];
			xx%=mod;
		}
		int sum=0;
		while(s!=0){
			if(s%2==1)sum++;
			s/=2;
		}
		if(sum==k){
			numm+=xx;
			numm%=mod;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		ans[x]=i;
		dfs(x+1);
	}
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;i++){
		v[i]=read();
	}
	dfs(1);
	cout<<numm;
	return 0;
}
