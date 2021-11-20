#include<cstdio>
#include<algorithm>
const int Q=200005;
const int INF=(1<<30);
#define gc() getchar()
typedef long long ll;
#define rg register int
#define cint const register int
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){int res=0,f=1;char c;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
int T,n,m,q;
inline int Id(cint x,cint y){return (x-1)*m+y;}
struct node{int cl,lv;}a[Q];
int h[Q],ccf;struct Edge{int to,nxt,val;}e[Q<<2];
inline void edge(cint x,cint y,cint z){e[++ccf]=(Edge){y,h[x],z};h[x]=ccf;}
inline void gph(cint x,cint y,cint z){edge(x,y,z);edge(y,x,z);}
int vst[Q];
inline int solve1(cint S){
	rg res=0;
	for(rg i=h[S];i;i=e[i].nxt){
		cint y=e[i].to;if(e[i].val^1)continue;
		if(a[y].cl==a[S].cl)continue;
		if(a[y].lv>a[S].lv)continue;vst[y]=1;++res;
	}return res;
}
inline int solve2(cint anc,cint S,cint d){
	rg res=0;
	for(rg i=h[S];i;i=e[i].nxt){
		cint y=e[i].to;if(e[i].val^2)continue;
		if(a[y].lv>a[anc].lv)continue;
		if(a[y].cl==a[anc].cl)continue;
		if(y-S!=d)continue;vst[y]=1;
		if(a[y].lv)++res;else res+=solve2(anc,y,d)+1;
	}return res;
}
inline int solve3(cint anc,cint S){
	rg res=0;
	for(rg i=h[S];i;i=e[i].nxt){
		cint y=e[i].to;if(e[i].val^3)continue;
		if(a[y].cl==a[anc].cl)continue;
		if(a[y].lv>a[anc].lv)continue;
		if(vst[y]==2)continue;if(!vst[y])++res;
		vst[y]=2;if(!a[y].lv)res+=solve3(anc,y);
	}return res;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);for(;T--;){
		read(n);read(m);read(q);
		for(rg i=1;i<=n;++i)for(rg j=1;j<=m;++j)a[Id(i,j)].cl=a[Id(i,j)].lv=h[Id(i,j)]=0;ccf=0;
		for(rg i=1;i<=n;++i){
			char c;while(c=gc(),c<'0'||c>'3');gph(Id(i,1),Id(i,2),c-'0');
			for(rg j=2;j<m;++j)c=gc(),gph(Id(i,j),Id(i,j+1),c-'0');
		}
		for(rg i=1;i<n;++i){
			char c;while(c=gc(),c<'0'||c>'3');gph(Id(i,1),Id(i+1,1),c-'0');
			for(rg j=2;j<=m;++j)c=gc(),gph(Id(i,j),Id(i+1,j),c-'0');
		}
		if(n*m<=200000&&q<=2000){
			for(rg i=1,x,y,c,lv;i<=q;++i){
				read(c);read(lv);read(x);read(y);
				cint id=Id(x,y);rg res=0;
				for(rg i=1;i<=n;++i)for(rg j=1;j<=m;++j)vst[Id(i,j)]=0;vst[id]=1;
				a[id].cl=c+1;a[id].lv=lv;
				res+=solve1(id);
				res+=solve2(id,id,1);res+=solve2(id,id,-1);
				res+=solve2(id,id,m);res+=solve2(id,id,-m);
				res+=solve3(id,id);
				write(res,'\n');
			}
		}else{
			for(rg i=1,x,y,c,lv;i<=q;++i){
				read(c);read(lv);read(x);read(y);
				cint id=Id(x,y);rg res=0;
				a[id].cl=c+1;a[id].lv=lv;
				res+=solve1(id);write(res,'\n');
			}
		}
	}
	return 0;
}
