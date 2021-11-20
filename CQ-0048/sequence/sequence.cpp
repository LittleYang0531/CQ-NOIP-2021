#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
using namespace std;
using ll=long long;
const int maxm=100,maxn=30,mod=998244353;
int n,m,k,ans,v[maxm+2],power[maxm+2][maxn+1],f[maxm+2][maxn+1][maxn+1][maxn+1],C[maxn+1][maxn+1];
inline int inc(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int adjust(int x){
	int res=0;
	x>>=1;
	while(x)res+=(x>>=1);
	return res;
}
int main(){
	freopen("sequence.in","r",stdin),freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k),f[0][0][0][0]=1;
	loop(i,1,m+1){
		scanf("%d",&v[i]),power[i][0]=1;
		loop(j,1,n)power[i][j]=(ll)power[i][j-1]*v[i]%mod;
	}
	loop(i,0,n)C[i][0]=1;
	loop(i,1,n)loop(j,1,i)C[i][j]=inc(C[i-1][j],C[i-1][j-1]);
	loop(i,0,m)loop(j,0,n)loop(p,0,j)loop(q,0,j)loop(x,0,n-j){
		int nextp=p/2+x,nextq=q+nextp/2;
		f[i+1][j+x][nextp][nextq]=inc(f[i+1][j+x][nextp][nextq],(ll)f[i][j][p][q]*C[n-j][x]%mod*power[i+1][x]%mod);
	}
	loop(p,0,n)loop(q,0,n)if(q+adjust(p)>=n-k)ans=inc(ans,f[m+1][n][p][q]);
	printf("%d",ans);
	return 0;
}
