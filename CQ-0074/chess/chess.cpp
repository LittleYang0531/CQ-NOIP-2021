#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#include<set>
#include<map>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
#define LL long long
int T,n,m,q,ans;
char s[200005];
int Id(int x,int y){
	return (x-1)*m+y;
}
struct node{
	int x,y;
};
vector<int>G1[200005],G2[2][200005],G3[200005];
vector<node>XX[200005],XS[200005],XZ[200005],XY[200005];
bool vis[200005];
int ok[200005];
int tag,nowvis[200005],anotag;
int color[200005],level[200005],xs[200005],xx[2000005],xz[200005],xy[200005];
set<int>S1[200005],S2[200005];
/*
普通/直行/互通 
*/
queue<int>Q;
void bfs1(int now,int col,int lv){
	tag++;
	while(!Q.empty())Q.pop();
	Q.push(now);
	nowvis[now]=tag;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=0;i<G2[0][u].size();i++){
			int v=G2[0][u][i];
			if(nowvis[v]!=tag){
				nowvis[v]=tag;
				if(vis[v]){
					if(color[v]!=col&&lv>=level[v]){
						if(ok[v]!=anotag)ans++;
						ok[v]=anotag;
					}
				}else {
					if(ok[v]!=anotag)ans++;
					ok[v]=anotag;
					Q.push(v);
				}
			}
		}
	}
	tag++;
	while(!Q.empty())Q.pop();
	Q.push(now);
	nowvis[now]=tag;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=0;i<G2[1][u].size();i++){
			int v=G2[1][u][i];
			if(nowvis[v]!=tag){
				nowvis[v]=tag;
				if(vis[v]){
					if(color[v]!=col&&lv>=level[v]){
						if(ok[v]!=anotag)ans++;
						ok[v]=anotag;
					}
				}else {
					if(ok[v]!=anotag)ans++;
					ok[v]=anotag;
					Q.push(v);
				}
			}
		}
	}
} 
void bfs2(int now,int col,int lv){
	tag++;
	while(!Q.empty())Q.pop();
	Q.push(now);
	nowvis[now]=tag;
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=0;i<G3[u].size();i++){
			int v=G3[u][i];
			if(nowvis[v]!=tag){
				nowvis[v]=tag;
				if(vis[v]){
					if(color[v]!=col&&lv>=level[v]){
						if(ok[v]!=anotag)ans++;
						ok[v]=anotag;
					}
				}else {
					if(ok[v]!=anotag)ans++;
					ok[v]=anotag;
					Q.push(v);
				}
			}
		}
	}
} 
bool viss[200005],visx[200005],visz[200005],visy[200005];
int dfs1(int x,int y){
	if(viss[Id(x,y)])return xs[Id(x,y)];
	viss[Id(x,y)]=1;
	for(int i=0;i<XS[Id(x,y)].size();i++)
		xs[Id(x,y)]=dfs1(XS[Id(x,y)][i].x,XS[Id(x,y)][i].y);
	return xs[Id(x,y)];
}
int dfs2(int x,int y){
	if(visx[Id(x,y)])return xx[Id(x,y)];
	visx[Id(x,y)]=1;
	for(int i=0;i<XX[Id(x,y)].size();i++)
		xx[Id(x,y)]=dfs2(XX[Id(x,y)][i].x,XX[Id(x,y)][i].y);
	return xx[Id(x,y)];
}
int dfs3(int x,int y){
	if(visz[Id(x,y)])return xz[Id(x,y)];
	visz[Id(x,y)]=1;
	for(int i=0;i<XZ[Id(x,y)].size();i++)
		xz[Id(x,y)]=dfs3(XZ[Id(x,y)][i].x,XZ[Id(x,y)][i].y);
	return xz[Id(x,y)];
}
int dfs4(int x,int y){
	if(visy[Id(x,y)])return xy[Id(x,y)];
	visy[Id(x,y)]=1;
	for(int i=0;i<XY[Id(x,y)].size();i++)
		xy[Id(x,y)]=dfs4(XY[Id(x,y)][i].x,XY[Id(x,y)][i].y);
	return xy[Id(x,y)];
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		tag=anotag=0;
		bool f2=0,f3=0;
		n=read(),m=read(),q=read();
		for(int i=1;i<=n*m;i++)G1[i].clear(),G3[i].clear(),G2[0][i].clear(),G2[1][i].clear(),nowvis[i]=vis[i]=ok[i]=0,XX[i].clear(),XS[i].clear(),XY[i].clear(),XZ[i].clear(),visx[i]=viss[i]=visz[i]=visy[i]=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s+1);
			for(int j=1;j<m;j++){
				if(s[j]=='1')G1[Id(i,j)].push_back(Id(i,j+1)),G1[Id(i,j+1)].push_back(Id(i,j));
				if(s[j]=='2'){
					G2[0][Id(i,j)].push_back(Id(i,j+1)),G2[0][Id(i,j+1)].push_back(Id(i,j)),f2=1;
					XZ[Id(i,j+1)].push_back(node{i,j});
					XY[Id(i,j)].push_back(node{i,j+1});
				}
				if(s[j]=='3')G3[Id(i,j)].push_back(Id(i,j+1)),G3[Id(i,j+1)].push_back(Id(i,j)),f3=1;
			}
		}
		for(int i=1;i<n;i++){
			scanf("%s",s+1);
			for(int j=1;j<=m;j++){
				if(s[j]=='1')G1[Id(i,j)].push_back(Id(i+1,j)),G1[Id(i+1,j)].push_back(Id(i,j));
				if(s[j]=='2'){
					G2[1][Id(i,j)].push_back(Id(i+1,j)),G2[1][Id(i+1,j)].push_back(Id(i,j)),f2=1;
					XS[Id(i+1,j)].push_back(node{i,j});
					XX[Id(i,j)].push_back(node{i+1,j});
				}
				if(s[j]=='3')G3[Id(i,j)].push_back(Id(i+1,j)),G3[Id(i+1,j)].push_back(Id(i,j)),f3=1;
			}
		}								
		if(!f3){
			for(int i=1;i<=n;i++)S1[i].clear();
			for(int i=1;i<=m;i++)S2[i].clear();
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					xs[Id(i,j)]=xx[Id(i,j)]=i;
					xz[Id(i,j)]=xy[Id(i,j)]=j;
				}
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					dfs1(i,j),dfs2(i,j),dfs3(i,j),dfs4(i,j);
			for(int i=1;i<=q;i++){
				ans=0;
				int col,lv,x,y;
				col=read(),lv=read(),x=read(),y=read();
				anotag++;
				for(int j=0;j<G1[Id(x,y)].size();j++){
					int to=G1[Id(x,y)][j];
					if(vis[to]){
						if(color[to]!=col&&lv>=level[to]){
							if(ok[to]!=anotag)ans++;
							ok[to]=anotag;
						}
					}else {
						if(ok[to]!=anotag)ans++;
						ok[to]=anotag;
					}
				}
				int qz=0;
				if(S2[y].lower_bound(x)==S2[y].begin())qz=0;
				else qz=(*--S2[y].lower_bound(x));
				if(qz<xs[Id(x,y)])ans+=x-xs[Id(x,y)];
				else{
					ans+=x-qz;
					if(color[Id(qz,y)]==col||level[Id(qz,y)]>lv)ans--;
				}
				qz=1e9;
				if(S2[y].upper_bound(x)==S2[y].end())qz=1e9;
				else qz=(*S2[y].upper_bound(x));
				if(qz>xx[Id(x,y)])ans+=xx[Id(x,y)]-x;
				else{
					ans+=qz-x;
					if(color[Id(qz,y)]==col||level[Id(qz,y)]>lv)ans--;
				}
				qz=0;
				if(S1[x].lower_bound(y)==S1[x].begin())qz=0;
				else qz=(*--S1[x].lower_bound(y));
				if(qz<xz[Id(x,y)])ans+=y-xz[Id(x,y)];
				else{
					ans+=y-qz;
					if(color[Id(x,qz)]==col||level[Id(x,qz)]>lv)ans--;
				}
				qz=1e9;
				if(S1[x].upper_bound(y)==S1[x].end())qz=1e9;
				else qz=(*S1[x].upper_bound(y));
				if(qz>xy[Id(x,y)])ans+=xy[Id(x,y)]-y;
				else{
					ans+=qz-y;
					if(color[Id(x,qz)]==col||level[Id(x,qz)]>lv)ans--;
				}
				printf("%d\n",ans); 
				vis[Id(x,y)]=1;
				S1[x].insert(y);
				S2[y].insert(x);
				color[Id(x,y)]=col;
				level[Id(x,y)]=lv;
			}
		}else{
			for(int i=1;i<=q;i++){
				ans=0;
				int col,lv,x,y;
				col=read(),lv=read(),x=read(),y=read();
				anotag++;
				for(int j=0;j<G1[Id(x,y)].size();j++){
					int to=G1[Id(x,y)][j];
					if(vis[to]){
						if(color[to]!=col&&lv>=level[to]){
							if(ok[to]!=anotag)ans++;
							ok[to]=anotag;
						}
					}else {
						if(ok[to]!=anotag)ans++;
						ok[to]=anotag;
					}
				}
				bfs1(Id(x,y),col,lv);
				bfs2(Id(x,y),col,lv);
				printf("%d\n",ans); 
				vis[Id(x,y)]=1;
				color[Id(x,y)]=col;
				level[Id(x,y)]=lv;
			}	
		}
		
	} 
	return 0;
}
/*
*/
