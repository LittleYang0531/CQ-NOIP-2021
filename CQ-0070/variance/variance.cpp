#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int n;
int a[10004];
ull rnd[10004];
map<ull,bool> m;
ll ans;

ll gets(){
	ll sum=0,tot=0;
	for(int i=1;i<=n;i++) 
		sum+=(ll)a[i]*a[i],tot+=a[i];
	return sum*n-tot*tot;
}

ull gethash(){
	ull has=1;
	for(int i=1;i<=n;i++) has=has*rnd[a[i]];
	return has;
}

void dfs(){
	ull has=gethash();
	if(m[has]) return;
	m[has]=1,ans=min(ans,gets());
	
	for(int i=2;i<n;i++){
		int ca=a[i];
		if(a[i-1]+a[i+1]-ca!=ca){
			a[i]=a[i-1]+a[i+1]-ca;
			dfs();
			a[i]=ca;
		}
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=2){printf("%lld",gets());return 0;}
	
	srand(time(0));
	for(int i=1;i<=600;i++) 
		rnd[i]=(998244353ull*rand()+rand()+1717171717ull);
	
	ans=gets();
	dfs();
	
	printf("%lld",ans);
	
	return 0;
}

