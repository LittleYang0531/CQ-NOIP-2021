#include<bits/stdc++.h>
#define inl inline 
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define repp(i,x,y,d) for(int i=(x);i<=(y);i+=(d))
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
typedef long long LL;

template<typename T>inl void exg(T &x,T &y){ x^=y^=x^=y; }
template<typename T>inl void chkmn(T &x,const T &y){ (x>y) && (x=y); }
template<typename T>inl void chkmx(T &x,const T &y){ (x<y) && (x=y); }

const int MOD=998244353;

inl int inc(int a,int b){ return (a+b>=MOD) ? a+b-MOD : a+b; }
inl int mul(int a,int b){ return 1LL*a*b%MOD; }
inl void Inc(int &a,int b){ ((a+=b)>=MOD) && (a-=MOD); }
inl void Mul(int &a,int b){ a=1LL*a*b%MOD; }
inl void Sqr(int &a){ a=1LL*a*a%MOD; }
int KSM(int a,int x=MOD-2){
	int res=1;
	while(x){
		if(x & 1) Mul(res,a);
		Sqr(a),x>>=1;
	}return res;
}

const int maxn=110;
int n,m,k;
int v[maxn];

namespace case_1{
	int f[32][1<<17];
	void Work(){
		f[0][0]=1;
		rep(i,0,n-1) rep(j,0,(1<<17)-1) if(f[i][j]) rep(l,0,m){
			const int x=j+(1<<l);
			Inc(f[i+1][x],mul(f[i][j],v[l]));
		}int ans=0;
		rep(i,0,(1<<17)-1) if(__builtin_popcount(i)<=k) Inc(ans,f[n][i]);
		printf("%d\n",ans);
	}
}
//namespace case_2{
//	int g[maxn][35],f[maxn][35][35],fac[35],fiv[35];
//	inl int Binom(int x,int y){ return mul(fac[x],mul(fiv[y],fiv[x-y])); }
//	void Work(){
//		fac[0]=1;
//		rep(i,1,n) fac[i]=mul(fac[i-1],i);
//		fiv[n]=KSM(fac[n]);
//		per(i,n-1,0) fiv[i]=mul(fiv[i+1],i+1);
//		
//		rep(i,0,m+5){
//			g[i][1]=v[i];
//			rep(j,2,n) rep(l,0,i) if(j>=(1<<(i-l))) Inc(g[i][j],mul(g[l][j-(1<<(i-l))],Binom(i,l))); 
//			
////			Inc(g[i][j],mul(g[i-1][k],g[i-1][j-k]));
//		}
//		
////		rep(i,0,m+5){
////			rep(j,1,n) printf("%d ",g[i][j]);
////			puts("");
////		}
//		
//		f[0][1][1]=v[0],f[0][0][0]=1;
//		rep(i,1,m+5) rep(j,0,n) rep(l,0,k){
//			f[i][j][l]=f[i-1][j][l];
//			rep(x,1,j) Inc(f[i][j][l],mul(f[i-1][j-x][l-1],g[i][x])); 
////			printf("%d %d %d %d\n",i,j,l,f[i][j][l]);
//		}int ans=0;
//		rep(i,1,k) Inc(ans,f[m+5][n][i]);
//		printf("%d\n",ans);
//	}
//}

int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	rep(i,0,m) scanf("%d",&v[i]);
	case_1::Work();
	return 0;
}
