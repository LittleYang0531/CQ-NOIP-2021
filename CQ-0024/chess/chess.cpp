#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch){
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
#define F(x,y) (((x)-1)*n+(y)-1)
int n,m,q;
int su[400005],sd[400005],sl[400005],sr[400005];
char Sx[400005],Sy[400005],*id;
struct node {
	int c,l;
	inline node(int a=0,int b=0){c=a,l=b;}
}P[400005];
inline bool Ck(int c,int l,node p){
	return c!=p.c&&l>=p.l;
}
int c,l,Ans,tmc,vis[400005];
void Dfs(int x,int y){
	if(x<1||x>n||y<1||y>m||vis[F(x,y)]==tmc)return ;
	if(!Ck(c,l,P[F(x,y)]))return ;
	++Ans,vis[F(x,y)]=tmc;
	if(P[F(x,y)].c)return ;
	if(x!=1&&Sy[F(x-1,y)]=='3')Dfs(x-1,y);
	if(x!=n&&Sy[F(x,y)]=='3')Dfs(x+1,y);
	if(y!=1&&Sx[F(x,y-1)]=='3')Dfs(x,y-1);
	if(y!=m&&Sx[F(x,y)]=='3')Dfs(x,y+1);
	
} 
int main()
{ 
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read()+1;
	while(--T){
		n=read(),m=read(),q=read();
		id=Sx;for(int i=1;i<=n;++i)scanf("%s",id),id+=m;
		id=Sy;for(int i=1;i<n;++i)scanf("%s",id),id+=m;
		for(int i=2;i<=n;++i)
		for(int j=1;j<=m;++j){
			su[F(i,j)]=Sy[F(i-1,j)]=='2'?su[F(i-1,j)]+1:0;
			sl[F(i,j)]=Sx[F(i,j-1)]=='2'?sl[F(i,j-1)]+1:0;
		}
		for(int i=n-1;i;--i)
		for(int j=m;j;--j){
			sd[F(i,j)]=Sy[F(i,j)]=='2'?sd[F(i+1,j)]+1:0;
			sr[F(i,j)]=Sx[F(i,j)]=='2'?sr[F(i,j+1)]+1:0;
		}
		for(int i=1;i<=q;++i){
			c=read()+1,l=read();int x=read(),y=read();
			Ans=0,++tmc;
			if(x!=1&&Sy[F(x-1,y)]=='1')Ans+=Ck(c,l,P[F(x-1,y)]),vis[F(x-1,y)]=tmc;
			if(x!=n&&Sy[F(x,y)]=='1')Ans+=Ck(c,l,P[F(x+1,y)]),vis[F(x+1,y)]=tmc;
			if(y!=1&&Sx[F(x,y-1)]=='1')Ans+=Ck(c,l,P[F(x,y-1)]),vis[F(x,y-1)]=tmc;
			if(y!=m&&Sx[F(x,y)]=='1')Ans+=Ck(c,l,P[F(x,y+1)]),vis[F(x,y+1)]=tmc;
			for(int px=x-1;px&&Sy[F(px,y)]=='2';--px){
				if(!Ck(c,l,P[F(px,y)]))break;
				++Ans,vis[F(px,y)]=tmc;
				if(P[F(px,y)].c)break;
			}
			for(int px=x+1;px<=n&&Sy[F(px-1,y)]=='2';++px){
				if(!Ck(c,l,P[F(px,y)]))break;
				++Ans,vis[F(px,y)]=tmc;
				if(P[F(px,y)].c)break;
			}
			for(int py=y-1;py&&Sx[F(x,py)]=='2';--py){
				if(!Ck(c,l,P[F(x,py)]))break;
				++Ans,vis[F(x,py)]=tmc;
				if(P[F(x,py)].c)break;
			}
			for(int py=y+1;py<=m&&Sx[F(x,py-1)]=='2';++py){
				if(!Ck(c,l,P[F(x,py)]))break;
				++Ans,vis[F(x,py)]=tmc;
				if(P[F(x,py)].c)break;
			}
			--Ans,Dfs(x,y),cout<<Ans<<"\n";P[F(x,y)]=node(c,l);
		}
		memset(P,0,sizeof(P));
		memset(su,0,sizeof(su));
		memset(sd,0,sizeof(sd));
		memset(sl,0,sizeof(sl));
		memset(sr,0,sizeof(sr));
	} 
	return 0;
}

