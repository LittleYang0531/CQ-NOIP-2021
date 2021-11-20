#include<bits/stdc++.h>
#define inl inline 
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;

template<typename T>inl void exg(T &x,T &y){ x^=y^=x^=y; }
template<typename T>inl void chkmn(T &x,const T &y){ (x>y) && (x=y); }
template<typename T>inl void chkmx(T &x,const T &y){ (x<y) && (x=y); }

const int maxn=2e5+5;
int _T,n,m,q;
vii c[maxn];
vector<bool> b1[maxn],b2[maxn],b3[maxn],vis[maxn];
string S[maxn],T[maxn];
pii _q[maxn<<4];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>_T;
	while(_T--){
		cin>>n>>m>>q;
		rep(i,1,n){
			cin>>S[i],c[i].resize(m+1),b1[i].resize(m+1),b2[i].resize(m+1),b3[i].resize(m+1),vis[i].resize(m+1);
			rep(j,1,m) c[i][j]=mp(0,0);
		}rep(i,1,n-1) cin>>T[i];
		int col,lv,x,y;
		while(q--){
			cin>>col>>lv>>x>>y;
			if((x ^ 1) && T[x-1][y-1]=='1'){ if(!c[x-1][y].se || ((c[x-1][y].fi ^ col) && c[x-1][y].se<=lv)) b1[x-1][y]=1; }
			if((x ^ n) && T[x][y-1]=='1'){ if(!c[x+1][y].se || ((c[x+1][y].fi ^ col) && c[x+1][y].se<=lv)) b1[x+1][y]=1; }
			if((y ^ 1) && S[x][y-2]=='1'){ if(!c[x][y-1].se || ((c[x][y-1].fi ^ col) && c[x][y-1].se<=lv)) b1[x][y-1]=1; }
			if((y ^ m) && S[x][y-1]=='1'){ if(!c[x][y+1].se || ((c[x][y+1].fi ^ col) && c[x][y+1].se<=lv)) b1[x][y+1]=1; }
			int xx=x,yy=y;
			while(xx ^ 1){
				if(T[xx-1][yy-1]=='2'){
					--xx;
					if(c[xx][yy].se){
						if((c[xx][yy].fi ^ col) && c[xx][yy].se<=lv) b2[xx][yy]=1;
						break;
					}b2[xx][yy]=1;
				}else break;
			}xx=x,yy=y;
			while(xx ^ n){
				if(T[xx][yy-1]=='2'){
					++xx;
					if(c[xx][yy].se){
						if((c[xx][yy].fi ^ col) && c[xx][yy].se<=lv) b2[xx][yy]=1;
						break;
					}b2[xx][yy]=1;
				}else break;
			}xx=x,yy=y;
			while(yy ^ 1){
				if(S[xx][yy-2]=='2'){
					--yy;
					if(c[xx][yy].se){
						if((c[xx][yy].fi ^ col) && c[xx][yy].se<=lv) b2[xx][yy]=1;
						break;
					}b2[xx][yy]=1;
				}else break;
			}xx=x,yy=y;
			while(yy ^ m){
				if(S[xx][yy-1]=='2'){
					++yy;
					if(c[xx][yy].se){
						if((c[xx][yy].fi ^ col) && c[xx][yy].se<=lv) b2[xx][yy]=1;
						break;
					}b2[xx][yy]=1;
				}else break;
			}int head=1,tail=1;
			_q[tail++]=mp(x,y);
			while(head<tail){
				pii p=_q[head++];
				if(c[p.fi][p.se].se){
					if((c[p.fi][p.se].fi ^ col) && c[p.fi][p.se].se<=lv) b3[p.fi][p.se]=1;
					continue;
				}else b3[p.fi][p.se]=1;
				if(p.fi ^ 1){ if(T[p.fi-1][p.se-1]=='3' && !vis[p.fi-1][p.se]) _q[tail++]=mp(p.fi-1,p.se),vis[p.fi-1][p.se]=1; }
				if(p.fi ^ n){ if(T[p.fi][p.se-1]=='3' && !vis[p.fi+1][p.se]) _q[tail++]=mp(p.fi+1,p.se),vis[p.fi+1][p.se]=1; }
				if(p.se ^ 1){ if(S[p.fi][p.se-2]=='3' && !vis[p.fi][p.se-1]) _q[tail++]=mp(p.fi,p.se-1),vis[p.fi][p.se-1]=1; }
				if(p.se ^ m){ if(S[p.fi][p.se-1]=='3' && !vis[p.fi][p.se+1]) _q[tail++]=mp(p.fi,p.se+1),vis[p.fi][p.se+1]=1; }
			}int ans=0;
			rep(i,1,n) rep(j,1,m){
				if(b1[i][j] || b2[i][j] || b3[i][j]){
					b1[i][j]=b2[i][j]=b3[i][j]=0;
					if((i ^ x) || (j ^ y)) ++ans;
				}vis[i][j]=0;
			}cout<<ans<<endl;
			c[x][y]=mp(col,lv);
		}
	}
	return 0;
}
