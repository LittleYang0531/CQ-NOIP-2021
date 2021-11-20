#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
const int Mxdt=100000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int T,n,m,Q,tot,c[400005],v[400005],x[400005],y[400005],vis[200005],vis1[200005],vis2[200005],ans;
char opt[400005];int num(int x,int y){return (x-1)*m+y;}
struct line{int x,y,opt;}l[2000005];
int h[400005],cnt;
struct edge{int to,next,opt;}e[2000005];
void add(int x,int y,int z){
	e[++cnt]=(edge){y,h[x],z};h[x]=cnt;
}
int C[400005],V[400005];
void dfs(int x,int c,int v){
	int i,y;if(vis1[x])return;
	vis1[x]=1;
	if(!vis[x]){vis[x]=1;
		if(!C[x])++ans;
		else{
			if(C[x]!=c&&V[x]<=v){
				++ans;
			}
			return;
		}
		
	}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(e[i].opt==3)dfs(y,c,v);
	}
}
void DFS(int x,int c,int v,int del){
	int i,y;if(vis2[x])return;
	vis2[x]=1;
	if(!vis[x]){vis[x]=1;
		if(!C[x])++ans;
		else{
			if(C[x]!=c&&V[x]<=v){
				++ans;
			}
			return;
		}
		
	}
	for(i=h[x];i;i=e[i].next){
		y=e[i].to;
		if(e[i].opt==2&&y-x==del)DFS(y,c,v,del);
	}
}
int main(){
//	system("fc chess.out chess3.ans");
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read()+1;
	while(--T){
		n=read();m=read();Q=read();tot=0;int Max=0;
		memset(h,0,sizeof(h));cnt=0;
		memset(C,0,sizeof(C));
		memset(V,0,sizeof(V));
		for(int i=1;i<=n;++i){
			scanf("%s",opt+1);
			for(int j=1;j<m;++j){
				if(opt[j]!='0'){
					l[++tot]=(line){num(i,j),num(i,j+1),opt[j]-'0'};
					Max=max(Max,opt[j]-'0');
				}
			}
		}
		for(int i=1;i<n;++i){
			scanf("%s",opt+1);
			for(int j=1;j<=m;++j){
				if(opt[j]!='0'){
					l[++tot]=(line){num(i,j),num(i+1,j),opt[j]-'0'};
					Max=max(Max,opt[j]-'0');
				}
			}
		}
		for(int i=1;i<=Q;++i){
			c[i]=read()+1;v[i]=read();
			x[i]=read();y[i]=read();
			vis[num(x[i],y[i])]=1;
		}
		for(int i=1;i<=tot;++i){
			add(l[i].x,l[i].y,l[i].opt);
			add(l[i].y,l[i].x,l[i].opt);
		}
		if(Q<=2000){
			for(int i=1;i<=Q;++i){
				memset(vis,0,sizeof(vis));
				memset(vis1,0,sizeof(vis1));
				memset(vis2,0,sizeof(vis2));
				ans=0;vis[num(x[i],y[i])]=vis1[num(x[i],y[i])]=vis2[num(x[i],y[i])]=1;
				for(int j=h[num(x[i],y[i])];j;j=e[j].next){
					int tp=e[j].to;
					if(e[j].opt==3)dfs(tp,c[i],v[i]);
					else if(e[j].opt==1){
						if(!vis[tp]){
							if(!C[tp]||(C[tp]!=c[i]&&V[tp]<=v[i]))++ans;vis[tp]=1;
						}
					}
					else{
						DFS(tp,c[i],v[i],tp-num(x[i],y[i]));
					}
				}
				cout<<ans<<'\n';
				C[num(x[i],y[i])]=c[i];V[num(x[i],y[i])]=v[i];
			}
		}
		else{
			if(Max==1){
				for(int i=1;i<=Q;++i){
					ans=0;
					for(int j=h[num(x[i],y[i])];j;j=e[j].next){
						int tp=e[j].to;
						if(!C[tp]||(C[tp]!=c[i]&&V[tp]<=v[i]))++ans;
					}
					cout<<ans<<'\n';
					C[num(x[i],y[i])]=c[i];V[num(x[i],y[i])]=v[i];
				}
			}	
		}
	}
	return 0;
}
