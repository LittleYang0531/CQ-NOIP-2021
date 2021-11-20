#include<bits/stdc++.h>
using namespace std;
#define int long long

const int Mod=998244353;
const int Maxn=40;
int N,M,K,v[Maxn],ans,tmp[Maxn],tot_1[10000010];
bool Vis[10000010];

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+ch-'0',ch=getchar();
	return ret*f;
}

inline bool check(int x){
	int ret=0;
	while(x){
		if(x%2==1) ret++;
		if(ret>K) return 0;
		x>>=1;
	}
	if(ret>K) return 0;
	return 1;
}

void DFS(int x,int val,int num,int sum){
	tmp[x]=val;
	if(x==N){
		if(Vis[sum]) ans=(ans+num)%Mod;
		tmp[x]=0;
		return;
	}
	for(int i=0;i<=M;i++) DFS(x+1,i,num*v[i]%Mod,sum+(1<<i));
	tmp[x]=0;
}

inline void Solve1(){
	int mx=N*(1<<M);
	for(int i=0;i<=13;i++) tot_1[(1<<i)]=1;
	for(int i=3;i<=mx;i++){
		if(!tot_1[i]) if(i%2==0) tot_1[i]=tot_1[i>>1];
		else tot_1[i]=tot_1[i-1]+1;
		if(tot_1[i]<=K) Vis[i]=true;
	} 
	for(int i=0;i<=M;i++) DFS(1,i,v[i],(1<<i));
	printf("%lld",ans%Mod);
}

signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	N=read(),M=read(),K=read();
	for(int i=0;i<=M;i++) v[i]=read();
	if(N<=8){ Solve1(); return 0; }
	return 0;
}
/*Hope I can get more point!!
RP++!!
And, Fuck CCF!!!*/
