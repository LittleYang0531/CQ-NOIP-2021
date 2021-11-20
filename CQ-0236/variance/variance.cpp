#include<bits/stdc++.h>
using namespace std;
const int k=131,mod=1e8+7,maxn=1e4+5;
bool vis[mod];
int n,a[maxn],sum,ans=2e9,Hash[maxn];
inline int f(){
	int k=0;
	for(int i=1;i<=n;++i)
		k+=(a[i]*n-sum)*(a[i]*n-sum);
	return k/n;
}
inline void dfs(){
	if(!ans)
		return;
	for(int i=1;i<=n;++i)
		Hash[i]=(Hash[i-1]*k+a[i])%mod;
	if(vis[Hash[n]])
		return;
	vis[Hash[n]]=1;
	ans=min(ans,f());
	for(int i=2;i<n;++i){
		if(a[i-1]+a[i+1]!=a[i]*2&&a[i-1]+a[i+1]-a[i]<=a[i+1]&&a[i-1]+a[i+1]-a[i]>=a[i-1]){
			int k=a[i];
			a[i]=a[i-1]+a[i+1]-a[i];
			sum=sum-k+a[i];
			dfs();
			sum=sum-a[i]+k;
			a[i]=k;
		}
	}
	return;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	dfs();
	printf("%d\n",ans);
	return 0;
}
/*
PPPP         ZZZZZZZZZ        JJJJJJ              AA              K       K      NN       N            O             III          PPPP
P   P               Z            J               A  A             K      K       N N      N          O   O            I           P    P
P    P             Z             J              A    A            K    K         N  N     N         O     O           I           P     P
P    P            Z              J             A      A           K  K           N   N    N        O       O          I           P    P
P  P             Z               J            A        A          KK             N    N   N       O         O         I           P   P
PP              Z                J           AAAAAAAAAAAA         K  K           N     N  N        O       O          I           PP
P              Z            J    J           A          A         K    K         N      N N         O     O           I           P
P             Z               J  J           A          A         K      K       N       NN          O   O            I           P
P            ZZZZZZZZZZZ        JJ           A          A         K       K      N        N            O              I           P
*/
