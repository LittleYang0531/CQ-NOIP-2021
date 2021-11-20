#include<bits/stdc++.h>//AFO
namespace MY_STD{
	#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
	#ifdef GTRAKIOI
	#define defrog(...) fprintf(stderr,__VA_ARGS__)
	#else
	#define defrog(...) 1
	#endif
	
	typedef long long ll;
	typedef std::vector<int>vi;
	typedef std::pair<int,int>pii;
	typedef std::vector<std::pair<int,int>>vpii;
	#define pb push_back
	#define eb emplace_back
	
	inline int getchar(){static char ibuf[1<<15],*p1,*p2;return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++;}
	struct IOer{
		inline int rint(){char c,f=0;while((c=getchar())<48||c>57)if(c=='-')f=1;unsigned int a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
		inline operator int(){return rint();}
		inline char rchar(){char c;while(!isgraph(c=getchar()));return c;}
	}g90;
	
	const int SIZE=400040,N=100010;
	int n,m;
	char type[SIZE];
	int has[SIZE];
	inline int ID(const int&i,const int&j,const int&k){
		if(k==2)return (i-1)*(m-1)+j;
		else if(k==1)return n*(m-1)+(i-1)*m+j;
		else return (i-1)*(m-1)+j;
	}
	
	signed main(){
		File("chess");
		for(int T=g90;T--;){
			n=g90,m=g90;int Q=g90;
			for(int i=1;i<=n;++i)for(int j=1;j<m;++i){
				type[ID(i,j,0)]=g90.rchar();
			}
			for(int i=1;i<n;++i)for(int j=1;j<=m;++i){
				type[ID(i,j,1)]=g90.rchar();
			}
			
			static int col[N],lv[N],x[N],y[N],vis[SIZE];
			for(int q=1;q<=Q;++q){
				col[q]=g90,lv[q]=g90,x[q]=g90,y[q]=g90;
				
				puts("0");
				
			}
		}
		return 0;
	}
}
signed main(){
	return MY_STD::main();
}
