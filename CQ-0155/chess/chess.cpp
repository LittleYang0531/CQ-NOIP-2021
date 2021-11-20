#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 100005;
typedef pair<int,int> PII;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
class kamisato{
	public:
		int col,lv,x,y;
		kamisato(int col_=0,int lv_=0,int x_=0,int y_=0):col(col_),lv(lv_),x(x_),y(y_){}
};
class Ayaka{
	public:
		int w[4];
};
class haoye{
	public:
		int x,y,flag;
		haoye(int x_=0,int y_=0,int flag_=0):x(x_),y(y_),flag(flag_){}
};
unordered_map<int,unordered_map<int,Ayaka> >h;
unordered_map<int,unordered_map<int,kamisato> >che;
int n,m,q;

inline void in(int &num){
	num = 0;
	char tmp = getchar();
	while(tmp<'0'||tmp>'9')
		tmp = getchar();
	while(tmp>='0'&&tmp<='9'){
		num = num*10+(tmp^48);
		tmp = getchar();
	}
}

inline int bfs(kamisato begin){
	unordered_map<int,unordered_map<int,bool> > b;
	queue<haoye> q;
	q.push({begin.x,begin.y,0});
	b[begin.x][begin.y] = true;
	int ans = 0;
	while(q.size()){
		auto u = q.front();
		q.pop();
		ans++;
		if(!u.flag){
			for(int k=0;k<4;k++){
				int tx = u.x+dx[k];
				int ty = u.y+dy[k];
				if(tx<1||tx>n||ty<1||ty>m)
					continue;
				if(!h[u.x][u.y].w[k])
					continue;
				if(b[tx][ty])
					continue;
				b[tx][ty] = true;
				if(che[tx][ty].x){
					if(begin.col!=che[tx][ty].col&&begin.lv>=che[tx][ty].lv)
						ans++;
					continue;
				}
				if(h[u.x][u.y].w[k]==1){
					ans++;
					continue;
				}
				if(h[u.x][u.y].w[k]==2){
					q.push({tx,ty,k+1});
					continue;
				}
				if(h[u.x][u.y].w[k]==3){
					q.push({tx,ty,-1});
					continue;
				}
			}
		}
		else if(u.flag==-1){
			for(int k=0;k<4;k++){
				int tx = u.x+dx[k];
				int ty = u.y+dy[k];
				if(tx<1||tx>n||ty<1||ty>m)
					continue;
				if(!h[u.x][u.y].w[k])
					continue;
				if(b[tx][ty])
					continue;
				if(che[tx][ty].x){
					if(begin.col!=che[tx][ty].col&&begin.lv>=che[tx][ty].lv)
						ans++;
					continue;
				}
				if(h[u.x][u.y].w[k]==3){
					b[tx][ty] = true;
					q.push({tx,ty,-1});
					continue;
				}
			}
		}
		else{
			int tx = u.x+dx[u.flag-1];
			int ty = u.y+dy[u.flag-1];
			if(tx<1||tx>n||ty<1||ty>m)
				continue;
			if(b[tx][ty])
				continue;
			if(che[tx][ty].x){
				if(begin.col!=che[tx][ty].col&&begin.lv>=che[tx][ty].lv)
					ans++;
				continue;
			}
			if(h[u.x][u.y].w[u.flag-1]==2){
				b[tx][ty] = true;
				q.push({tx,ty,u.flag});
				continue;
			}
		}
	}
	return ans-1;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	in(T);
	while(T--){
		h = unordered_map<int,unordered_map<int,Ayaka> >();
		che = unordered_map<int,unordered_map<int,kamisato> >();
		in(n),in(m),in(q);
		for(int k=1;k<=n;k++)
			for(int j=1;j<m;j++){
				char tmp = getchar();
				while(tmp<'0'||tmp>'9')
					tmp = getchar();
				h[k][j].w[0] = h[k][j+1].w[2] = tmp^48;
			}
		for(int k=1;k<n;k++)
			for(int j=1;j<=m;j++){
				char tmp = getchar();
				while(tmp<'0'||tmp>'9')
					tmp = getchar();
				h[k][j].w[1] = h[k+1][j].w[3] = tmp^48;
			}
		while(q--){
			kamisato tmp;
			in(tmp.col),in(tmp.lv),in(tmp.x),in(tmp.y);
			che[tmp.x][tmp.y] = tmp;
			printf("%d\n",bfs(tmp));
		}
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
