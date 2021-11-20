#include<bits/stdc++.h>
using namespace std;
#define int long long

const double down=0.996;
const int Maxn=510;
const int INF=0x3f3f3f3f;
int N,A[Maxn],ans=INF,K=100;

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+ch-'0',ch=getchar();
	return ret*f;
}

int Solve(){
	int ret=0;
	for(int i=1;i<=N;i++){
		int tmp=0;
		for(int j=1;j<=N;j++) tmp+=A[i]-A[j];
		ret+=tmp*tmp;
	}
	return ret/N;
}

void fire(){
	double t=5000;
	while(t>1e-19){
		int x=rand()%N;
		while(x<=1) x=rand()%N;
		int tmp=A[x];
		A[x]=A[x-1]+A[x+1]-A[x];
		int now_ans=Solve();
		if(now_ans<ans) ans=now_ans;
		else if(exp(-ans+now_ans)>rand()/RAND_MAX) A[x]=tmp;
		else ans=now_ans;
		t*=down;
	}
}

bool check(int x){
	if(A[x-1]+A[x+1]-A[x]==A[x]) return 0;
	A[x]=A[x-1]+A[x+1]-A[x];
	return 1;
}

void DFS(int x,int f){
	int tmp=A[x];
	if(!check(x)) return;
	ans=min(ans,Solve());
	for(int i=2;i<N;i++) if(i!=f&&i!=x) DFS(i,x);
	A[x]=tmp;
}

void Solve1(){
	ans=Solve();
	for(int i=2;i<N;i++) DFS(i,0);
	printf("%d",ans);
}

void Solve2(){
	while(K--) fire();
	printf("%lld",ans);
}

signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	N=read();
	for(int i=1;i<=N;i++) A[i]=read();
	if(N<=4) Solve1();
	else Solve2();
	return 0;
}
/*Hope I can get more point!!
RP++!!
And, Fuck CCF!!!*/
