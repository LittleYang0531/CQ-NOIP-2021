/*
CCF-NOIp 2021 
Pass: IronHeart@413A
*/
#include<bits/stdc++.h>
namespace MY_STD{
	#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
	#define defrog(...) fprintf(stderr,__VA_ARGS__)
	
	typedef long long ll;
	typedef std::vector<int>vi;
	typedef std::pair<int,int>pii;
	
	inline int getchar(){static char ibuf[1<<15],*p1,*p2;return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++;}
	struct IOer{
		inline int rint(){char c,f=0;while((c=getchar())<48||c>57)if(c=='-')f=1;unsigned int a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
		inline operator int(){return rint();}
	}g90;
	
	const int N=33,LSIZE=18,SIZE=1<<18,M=998244353;
	int v[LSIZE];
	int popcnt[SIZE],f[N][SIZE];
	signed main(){
		File("sequence");
		int n=g90,m=g90,k=g90;
		for(int i=0;i<=m;++i)v[i]=g90;
		
		popcnt[0]=0;
		for(int S=1;S<=n*(1<<m);++S)popcnt[S]=popcnt[S>>1]+(S&1);
		f[0][0]=1;
		for(int i=1;i<=n;++i){
			for(int S=0;S<=i*(1<<m);++S){
				for(int x=0;x<=m&&(1<<x)<=S;++x){
					f[i][S]=(f[i][S]+f[i-1][S-(1<<x)]*(ll)v[x])%M;
				}
//				defrog("%d %d %d\n",i,S,f[i][S]);
			}
		}
		ll ans=0;
		for(int S=0;S<=n*(1<<m);++S)if(popcnt[S]<=k)ans=(ans+f[n][S])%M;
		printf("%lld\n",ans);
		return 0;
	}
}
signed main(){
	return MY_STD::main();
}
