/*---And in that light,I find deliverance.---*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int> ri[maxn],le[maxn],dw[maxn],up[maxn];
char s[maxn];
unordered_map<int,int> lev[maxn];
unordered_map<int,int> col[maxn];
int bfs(int x,int y,int c,int l){
	int X=x,Y=y,ans=0;
	queue<pair<int,int> > Q;
	unordered_map<int,int> vis[maxn];
	Q.emplace(x,y);
	if(vis[x][y-1]==0&&le[x][y]==1){
			if(lev[x][y-1]){
				if(c!=col[x][y-1]&&l>=lev[x][y-1]){
					++ans;
					vis[x][y-1]=1;
				}
			}
			else{
				vis[x][y-1]=1;
				++ans;
			}
		}
		if(vis[x][y+1]==0&&ri[x][y]==1){
			if(lev[x][y+1]){
				if(c!=col[x][y+1]&&l>=lev[x][y+1]){
					++ans;
					vis[x][y+1]=1;
				}
			}
			else{
				vis[x][y+1]=1;
				++ans;
			}
		}
		if(vis[x+1][y]==0&&dw[x][y]==1){
			if(lev[x+1][y]){
				if(c!=col[x+1][y]&&l>=lev[x+1][y]){
					++ans;
					vis[x+1][y]=1;
				}
			}
			else{
				vis[x+1][y]=1;
				++ans;
			}
		}
		if(vis[x-1][y]==0&&up[x][y]==1){
			if(lev[x-1][y]){
				if(c!=col[x-1][y]&&l>=lev[x-1][y]){
					++ans;
					vis[x-1][y]=1;
				}
			}
			else{
				vis[x-1][y]=1;
				++ans;
			}
		}
	while(!Q.empty()){
		auto u=Q.front();Q.pop();
		int x,y;tie(x,y)=u;
		if(vis[x][y-1]==0&&le[x][y]==3){
			if(lev[x][y-1]){
				if(c!=col[x][y-1]&&l>=lev[x][y-1]){
					++ans;
					vis[x][y-1]=1;
				}
			}
			else{
				vis[x][y-1]=1;
				++ans;
				Q.emplace(x,y-1);
			}
		}
		if(vis[x][y+1]==0&&ri[x][y]==3){
			if(lev[x][y+1]){
				if(c!=col[x][y+1]&&l>=lev[x][y+1]){
					++ans;
					vis[x][y+1]=1;
				}
			}
			else{
				vis[x][y+1]=1;
				++ans;
				Q.emplace(x,y+1);
			}
		}
		if(vis[x+1][y]==0&&dw[x][y]==3){
			if(lev[x+1][y]){
				if(c!=col[x+1][y]&&l>=lev[x+1][y]){
					++ans;
					vis[x+1][y]=1;
				}
			}
			else{
				vis[x+1][y]=1;
				++ans;
				Q.emplace(x+1,y);
			}
		}
		if(vis[x-1][y]==0&&up[x][y]==3){
			if(lev[x-1][y]){
				if(c!=col[x-1][y]&&l>=lev[x-1][y]){
					++ans;
					vis[x-1][y]=1;
				}
			}
			else{
				vis[x-1][y]=1;
				++ans;
				Q.emplace(x-1,y);
			}
		}
	}
	int xx,yy;
	xx=X,yy=Y;
	while(le[xx][yy]==2){
		if(lev[xx][yy-1]){
			if(c!=col[xx][yy-1]&&l>=lev[xx][yy-1]){
				if(!vis[xx][yy-1])
					vis[xx][yy-1]=1,++ans;
			}
			break;
		}
		else{
			if(!vis[xx][yy-1])
				vis[xx][yy-1]=1,++ans;
			--yy;
		}
	}
	xx=X,yy=Y;
	while(ri[xx][yy]==2){
		if(lev[xx][yy+1]){
			if(c!=col[xx][yy+1]&&l>=lev[xx][yy+1]){
				if(!vis[xx][yy+1])
					vis[xx][yy+1]=1,++ans;
			}
			break;
		}
		else{
			if(!vis[xx][yy+1])
				vis[xx][yy+1]=1,++ans;
			++yy;
		}
	}
	xx=X,yy=Y;
	while(up[xx][yy]==2){
		if(lev[xx-1][yy]){
			if(c!=col[xx-1][yy]&&l>=lev[xx-1][yy]){
				if(!vis[xx-1][yy])
					vis[xx-1][yy]=1,++ans;
			}
			break;
		}
		else{
			if(!vis[xx-1][yy])
				vis[xx-1][yy]=1,++ans;
			--xx;
		}
	}
	xx=X,yy=Y;
	while(dw[xx][yy]==2){
		if(lev[xx+1][yy]){
			if(c!=col[xx+1][yy]&&l>=lev[xx+1][yy]){
				if(!vis[xx+1][yy])
					vis[xx+1][yy]=1,++ans;
			}
			break;
		}
		else{
			if(!vis[xx+1][yy])
				vis[xx+1][yy]=1,++ans;
			++xx;
		}
	}
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n,m,q;cin>>n>>m>>q;
		for(int i=1;i<=n;++i){
			cin>>(s+1);
			ri[i].emplace_back(0);
			le[i].emplace_back(0);
			le[i].emplace_back(0);
			for(int j=1;j<=m-1;++j)
				ri[i].emplace_back(s[j]-'0'),le[i].emplace_back(s[j]-'0');
			ri[i].emplace_back(0);
		}
		for(int i=1;i<=m;++i) up[i].emplace_back(0),dw[i].emplace_back(0);
		for(int i=1;i<=n;++i) up[1].emplace_back(0),dw[n].emplace_back(0);
		for(int i=1;i<n;++i){
			cin>>(s+1);
			for(int j=1;j<=m;++j) dw[i].emplace_back(s[j]-'0'),up[i+1].emplace_back(s[j]-'0');
		}
		for(int i=1;i<=q;++i){
			int co,lv,x,y;cin>>co>>lv>>x>>y;
			lev[x][y]=lv;
			col[x][y]=co;
			cout<<bfs(x,y,co,lv)<<'\n';
		}
		for(int i=1;i<=max(n,m);++i) le[i].clear(),ri[i].clear(),dw[i].clear(),up[i].clear(),lev[i].clear(),col[i].clear();
	}
	return 0;
}

