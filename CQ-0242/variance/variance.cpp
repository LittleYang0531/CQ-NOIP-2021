#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<map>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

const int MAXN=1e4+5;
typedef long long ll;
int n;
ll ans;
vector <int> a;


#define ll long long

ll calc(){
	ll s=0;
	for (int i=1;i<=n;i++) s+=a[i];
	ll ret=0;
	for (int i=1;i<=n;i++){
		ret+=(ll)n*(ll)a[i]*(ll)a[i];
		ret-=2ll*a[i]*s;
	}
	ret+=s*s;
	return ret;
}

map <vector<int>,bool> mp;

void dfs(){
	if (mp.find(a)!=mp.end()) return;
	ans=min(ans,calc());
	mp[a]=1;
	for (int i=n-1;i>1;i--){
		int tmp=a[i];
		a[i]=(a[i-1]+a[i+1]-a[i]);
		dfs();
		a[i]=tmp;
	}
	return;
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	ans=1e18;
	a.resize(n+5);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs();
	printf("%lld\n",ans);
	return 0;
}
// Sto Orz %%% CJG ÉúÈÕ¿ìÀÖ CJG AK NOIP

