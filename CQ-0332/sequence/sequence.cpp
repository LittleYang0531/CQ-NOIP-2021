#include <bits/stdc++.h>
//#define int __int128
using namespace std;
int n, m, k, answer, v[105], jc[105], inv[105], inv_jc[105];
const int mod = 998244353;
inline int read(int &x){
	int s=0, f=1; char c=getchar();
	while(c < '0' || c > '9'){ if(c == '-') f=-1; c=getchar(); }
	while(c >= '0' && c <= '9') s=(s << 3)+(s << 1)+c-'0', c=getchar(); x=s*f;
}
//inline void write(int x){
//	if(x == 0) return ;
//	if(x < 0) putchar('-'), x=-x;
//	write(x/10);
//	putchar((char) x%10+'0');
//	return ;
//}
//void dfs(int x, int gs, int ans){
//	(answer+=ans*jc[n]%mod*inv_jc[n-gs]%mod)%=mod;
//	if(gs == 0) return ;
//	for(int i = m; i >= 0; --i)
//		dfs(x+(1<<i),k-1,(ans*v[i])%mod);
//}
signed main() {
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n), read(m), read(k);
	for(int i = 0; i < m+1; ++i)
		read(v[i]), (answer+=v[i]*(n-i))%=mod;
//	if(answer == 0)
//		cout<<0<<"\n";
//	else
//		write(answer);
	cout<<(answer-n+1)*10<<"\n";
	return 0;
}
