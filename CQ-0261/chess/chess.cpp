// nm
#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){ll a=0;int b=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9'){a=(a<<1)+(a<<3)+(c^48);c=getchar();}return a*b;}
const int MAX_N = 1e4 + 9;
const int MAX_M = 1e4 + 9;
const int MAX_Q = 1e5 + 9;
const int Dxy[4][2] = {0,1,0,-1,1,0,-1,0};
int T;
int n,m,q;
int zy[MAX_N][MAX_M];
int sx[MAX_N][MAX_M];
bool vis[MAX_N][MAX_M];
bool checked[MAX_N][MAX_M];
struct Node{int col,lv;}qz[MAX_N][MAX_M];
queue<pair<int,int> >Q;
inline int solve(int x,int y,int col,int lv){
	memset(checked,0,sizeof checked);
	checked[x][y] = 1;
	int tx,ty;
	int ans = 0;
	// left
	
	tx = x;
	ty = y-1;
//	puts("1");
	if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
		switch(zy[tx][ty]){
			case 0:{break;}
			case 1:{if(checked[tx][ty] == 0) ++ans;checked[tx][ty] = 1;break;}
			case 2:{
				while(ty>=1){
					if(checked[tx][ty] == 0) ++ans;
					checked[tx][ty] = 1;
					--ty;
					if(ty==0) break;
					if(zy[tx][ty]!=2) break;
					if(qz[tx][ty].lv!=0){
						if(col!=qz[tx][ty].col && lv>=qz[tx][ty].lv){
							if(checked[tx][ty] == 0) ++ans;
							checked[tx][ty] = 1;
						}
						break;
					}
				}
				break;
			}
			case 3:{
				if(checked[tx][ty] == 0) ++ans;
				checked[tx][ty] = 1;
				Q.push(make_pair(tx,ty));
				memset(vis,0,sizeof vis);
				vis[tx][ty] = 1;
				while(Q.size()){
					pair<int,int> now = Q.front();
					Q.pop();
					bool f;
					for(int i=0;i<4;++i){
						f=1;
						int X = now.first + Dxy[i][0];
						int Y = now.second + Dxy[i][1];
						if(X<1||X>n||Y<1||Y>m||vis[X][Y]) continue;
						vis[X][Y]=1;
						if(qz[X][Y].lv!=0){
							if(col!=qz[X][Y].col && lv>=qz[X][Y].lv) f=0;
							else continue;
						}
						int t;
						if(i==0) t=zy[tx][ty];
						if(i==1) t=zy[X][Y];
						if(i==2) t=sx[tx][ty];
						if(i==3) t=sx[X][Y];
						if(t==3){
							if(checked[X][Y] == 0) ++ans;
							checked[X][Y] = 1;
							if(f) Q.push(make_pair(X,Y));
						}
					}
				}
				break;
			}
	}
//	cout << "Left:" << ans << '\n';
	// right 
	tx = x;
	ty = y+1;
//	puts("2");
	if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
		switch(zy[x][y]){
			case 0:{break;}
			case 1:{if(checked[tx][ty] == 0) ++ans;checked[tx][ty] = 1;break;}
			case 2:{
				while(ty<=m){
					if(checked[tx][ty] == 0) ++ans;
					checked[tx][ty] = 1;
					++ty;
					if(ty==m+1) break;
					if(zy[tx][ty]!=2) break;
					if(qz[tx][ty].lv!=0){
						if(col!=qz[tx][ty].col && lv>=qz[tx][ty].lv){
							if(checked[tx][ty] == 0) ++ans;
							checked[tx][ty] = 1;
						}
						break; 
					}
				}
				break;
			}
			case 3:{
				if(checked[tx][ty] == 0) ++ans;
				checked[tx][ty] = 1;
				Q.push(make_pair(tx,ty));
				memset(vis,0,sizeof vis);
				vis[tx][ty] = 1;
				while(Q.size()){
					pair<int,int> now = Q.front();
					Q.pop();
					bool f;
					for(int i=0;i<4;++i){
						f=1;
						int X = now.first + Dxy[i][0];
						int Y = now.second + Dxy[i][1];
						if(X<1||X>n||Y<1||Y>m||vis[X][Y]) continue;
						vis[X][Y]=1;
						if(qz[X][Y].lv!=0){
							if(col!=qz[X][Y].col && lv>=qz[X][Y].lv) f=0;
							else continue;
						}
						int t;
						if(i==0) t=zy[tx][ty];
						if(i==1) t=zy[X][Y];
						if(i==2) t=sx[tx][ty];
						if(i==3) t=sx[X][Y];
						if(t==3){
							if(checked[X][Y] == 0) ++ans;
							checked[X][Y] = 1;
							if(f) Q.push(make_pair(X,Y));
						}
					}
				}
				break;
			}
		}
//		cout << "Right:" << ans << '\n';
	// down
	tx = x + 1;
	ty = y;
//	puts("3");
	if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
		switch(sx[x][y]){
			case 0:{break;}
			case 1:{if(checked[tx][ty] == 0) ++ans;checked[tx][ty] = 1;break;}
			case 2:{
				while(tx<=n){
					if(checked[tx][ty] == 0) ++ans;
					checked[tx][ty] = 1;
					++tx;
					if(tx==n+1) break;
					if(sx[tx][ty]!=2) break;
					if(qz[tx][ty].lv!=0){
						if(col!=qz[tx][ty].col && lv>=qz[tx][ty].lv){
							if(checked[tx][ty] == 0) ++ans;
							checked[tx][ty] = 1;
						}
						break;
					}
				}
				break;
			}
			case 3:{
				if(checked[tx][ty] == 0) ++ans;
				checked[tx][ty] = 1;
				Q.push(make_pair(tx,ty));
				memset(vis,0,sizeof vis);
				vis[tx][ty] = 1;
				while(Q.size()){
					pair<int,int> now = Q.front();
					Q.pop();
					bool f;
					for(int i=0;i<4;++i){
						f=1;
						int X = now.first + Dxy[i][0];
						int Y = now.second + Dxy[i][1];
						if(X<1||X>n||Y<1||Y>m||vis[X][Y]) continue;
						vis[X][Y]=1;
						if(qz[X][Y].lv!=0){
							if(col!=qz[X][Y].col && lv>=qz[X][Y].lv) f=0;
							else continue;
						}
						int t;
						if(i==0) t=zy[tx][ty];
						if(i==1) t=zy[X][Y];
						if(i==2) t=sx[tx][ty];
						if(i==3) t=sx[X][Y];
						if(t==3){
							if(checked[X][Y] == 0) ++ans;
							checked[X][Y] = 1;
							if(f) Q.push(make_pair(X,Y));
						}
					}
				}
				break;
			}
		}
//		cout << "Down:" << ans << '\n';
	// up
	tx = x - 1;
	ty = y;
//	puts("4");
	if(tx>=1&&tx<=n&&ty>=1&&ty<=m)
		switch(sx[tx][ty]){
			case 0:{break;}
			case 1:{if(checked[tx][ty] == 0) ++ans;checked[tx][ty] = 1;break;}
			case 2:{
				while(tx>=1){
					if(checked[tx][ty] == 0) ++ans;
					checked[tx][ty] = 1;
					--tx;
					if(tx==0) break;
					if(sx[tx][ty]!=2) break;
					if(qz[tx][ty].lv!=0){
						if(col!=qz[tx][ty].col && lv>=qz[tx][ty].lv){
							if(checked[tx][ty] == 0) ++ans;
							checked[tx][ty] = 1;
						}
						break;
					}
				}
				break;
			}
			case 3:{
				if(checked[tx][ty] == 0) ++ans;
				checked[tx][ty] = 1;
				Q.push(make_pair(tx,ty));
				memset(vis,0,sizeof vis);
				vis[tx][ty] = 1;
				while(Q.size()){
					pair<int,int> now = Q.front();
					Q.pop();
					bool f;
					for(int i=0;i<4;++i){
						f=1;
						int X = now.first + Dxy[i][0];
						int Y = now.second + Dxy[i][1];
						if(X<1||X>n||Y<1||Y>m||vis[X][Y]) continue;
						vis[X][Y]=1;
						if(qz[X][Y].lv!=0){
							if(col!=qz[X][Y].col && lv>=qz[X][Y].lv) f=0;
							else continue;
						}
						int t;
						if(i==0) t=zy[tx][ty];
						if(i==1) t=zy[X][Y];
						if(i==2) t=sx[tx][ty];
						if(i==3) t=sx[X][Y];
						if(t==3){
							if(checked[X][Y] == 0) ++ans;
							checked[X][Y] = 1;
							if(f) Q.push(make_pair(X,Y));
						}
					}
				}
				break;
			}
		}
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=m;++j){
//			if(checked[i][j]){
//				cout << i << ' ' << j << '\n';
//			}
//		}
//	}
//	cout << "Up:";
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T = read();
	while(~--T){
		n = read();
		m = read();
		for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) qz[i][j].col = qz[i][j].lv = 0;
		q = read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j){
				char c = getchar();
				while(c<'0'||c>'3') c = getchar();
				zy[i][j] = c - '0';
			}
		}
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j){
				char c = getchar();
				while(c<'0'||c>'3') c = getchar();
				sx[i][j] = c - '0';
			}
		}
		for(int i=1;i<=q;++i){
			int col = read(),lv = read(),x = read(),y = read();
//			puts("Here");
			cout << solve(x,y,col,lv) << "\n";
			qz[x][y] = (Node){col,lv};
		}
	}
//	cout <<"Time:" << clock() << "ms.";
	return 0;
}
