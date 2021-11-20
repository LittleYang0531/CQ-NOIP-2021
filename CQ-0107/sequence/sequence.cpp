#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int N,M,K;
int v[110];
int f[40][150010];
int lowbit(int x) {return x&(-x);}
bool check(int x) {
	int cnt=0;
	while (x) cnt++,x-=lowbit(x);
	return cnt<=K;
}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>N>>M>>K;
	int maxval=(1ll<<M);
	for (int i=0;i<=M;i++) scanf("%lld",&v[i]);
	f[0][0]=1;
	for (int i=0;i<N;i++)
	    for (int j=i;j<=i*maxval;j++) 
	        for (int k=0;k<=M;k++) {
	        	int add=(1ll<<k);
	        	f[i+1][j+add]+=f[i][j]*v[k]%mod;
	        	if (f[i+1][j+add]>=mod) f[i+1][j+add]-=mod;
			}
	int ans=0;
	for (int i=N;i<=N*maxval;i++)
	    if (check(i)) {
	    	ans+=f[N][i];
	    	if (ans>=mod) ans-=mod;
		}
	cout<<ans%mod<<endl;
	return 0;
}
