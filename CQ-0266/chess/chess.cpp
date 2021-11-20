#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const unsigned int N=1e4+5;
int T,n,m,qes,ans,optright[N][N],optdown[N][N],sx,sy;
bool vis[N][N];
struct Node{
	int color;
	int level;
	Node(){
		color=-1;
		level=-1;
	}
}map[N][N];
struct Queue{
	int x;
	int y;
	bool pt;
	bool onlydir;//true:up or down   false:right or left
	bool dirlor;
	bool ht;
};
queue<Queue>q;
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=y;
}
inline void write(int x,bool wrap){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)
	write(x/10,false);
	putchar('0'+x%10);
	if(wrap)
	puts("");
}
bool check(int x,int y){
	return !vis[x][y]&&x>0&&y>0&&x<=n&&y<=m;
}
void clear(){
	while(!q.empty())
	q.pop();
}
void bfs(){
	while(!q.empty()){
		int tx=q.front().x;
		int ty=q.front().y;
		//printf("at (%d,%d)\n",tx,ty);
		bool pt=q.front().pt;
		bool onlydir=q.front().onlydir;
		bool dirlor=q.front().dirlor;
		bool ht=q.front().ht;
		q.pop();
		//up tx-1 ty
		if(check(tx-1,ty)&&optdown[tx-1][ty]!=0&&map[tx-1][ty].color!=map[sx][sy].color&&map[tx-1][ty].level<=map[sx][sy].level&&(!onlydir||(onlydir&&dirlor==true))){
			if(optdown[tx-1][ty]==1&&(!onlydir)&&(!ht)){//普通道路 
				if(!pt){
					vis[tx-1][ty]=true;
					ans++;
					q.push(Queue{tx-1,ty,true,onlydir,dirlor,ht});
				}
			}
			if(optdown[tx-1][ty]==2&&(!pt)&&(!ht)){//直行道路 
				if(!onlydir||(onlydir&&dirlor==true)){
					vis[tx-1][ty]=true;
					ans++;
					q.push(Queue{tx-1,ty,pt,true,true,ht});
				}
			}
			if(optdown[tx-1][ty]==3&&(!pt)&&(!onlydir)){//互通道路 
				vis[tx-1][ty]=true;
				ans++;
				q.push(Queue{tx-1,ty,pt,onlydir,dirlor,true});
			}
		}
		//down tx+1 ty
		if(check(tx+1,ty)&&optdown[tx][ty]!=0&&map[tx+1][ty].color!=map[sx][sy].color&&map[tx+1][ty].level<=map[sx][sy].level&&(!onlydir||(onlydir&&dirlor==true))){
			if(optdown[tx][ty]==1&&(!onlydir)&&(!ht)){//普通道路 
				if(!pt){
					vis[tx+1][ty]=true;
					ans++;
					q.push(Queue{tx+1,ty,true,onlydir,dirlor,ht});
				}
			}
			if(optdown[tx][ty]==2&&(!pt)&&(!ht)){//直行道路 
				if(!onlydir||(onlydir&&dirlor==true)){
					vis[tx+1][ty]=true;
					ans++;
					q.push(Queue{tx+1,ty,pt,true,true,ht});
				}
			}
			if(optdown[tx][ty]==3&&(!pt)&&(!onlydir)){//互通道路 
				vis[tx+1][ty]=true;
				ans++;
				q.push(Queue{tx+1,ty,pt,onlydir,dirlor,true});
			}
		}
		//right tx ty-1
		if(check(tx,ty-1)&&optdown[tx][ty-1]!=0&&map[tx][ty-1].color!=map[sx][sy].color&&map[tx][ty-1].level<=map[sx][sy].level&&(!onlydir||(onlydir&&dirlor==false))){
			if(optdown[tx][ty-1]==1&&(!onlydir)&&(!ht)){//普通道路 
				if(!pt){
					vis[tx][ty-1]=true;
					ans++;
					q.push(Queue{tx,ty-1,true,onlydir,dirlor,ht});
				}
			}
			if(optdown[tx][ty-1]==2&&(!pt)&&(!ht)){//直行道路 
				if(!onlydir||(onlydir&&dirlor==false)){
					vis[tx][ty-1]=true;
					ans++;
					q.push(Queue{tx,ty-1,pt,true,false,ht});
				}
			}
			if(optdown[tx][ty-1]==3&&(!pt)&&(!onlydir)){//互通道路 
				vis[tx][ty-1]=true;
				ans++;
				q.push(Queue{tx,ty-1,pt,onlydir,dirlor,true});
			}
		}
		//left tx ty+1
		if(check(tx,ty+1)&&optdown[tx][ty]!=0&&map[tx][ty+1].color!=map[sx][sy].color&&map[tx][ty+1].level<=map[sx][sy].level&&(!onlydir||(onlydir&&dirlor==false))){
			if(optdown[tx][ty]==1&&(!onlydir)&&(!ht)){//普通道路 
				if(!pt){
					vis[tx][ty+1]=true;
					ans++;
					q.push(Queue{tx,ty+1,true,onlydir,dirlor,ht});
				}
			}
			if(optdown[tx][ty]==2&&(!pt)&&(!ht)){//直行道路 
				if(!onlydir||(onlydir&&dirlor==false)){
					vis[tx][ty+1]=true;
					ans++;
					q.push(Queue{tx,ty+1,pt,true,false,ht});
				}
			}
			if(optdown[tx][ty]==3&&(!pt)&&(!onlydir)){//互通道路 
				vis[tx][ty+1]=true;
				ans++;
				q.push(Queue{tx,ty+1,pt,onlydir,dirlor,true});
			}
		}
	}
}
void solve(){
	read(n);
	read(m);
	read(qes);
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=m-1;j++)
		scanf("%1d",&optright[i][j]);
	}
	for(register int i=1;i<=n-1;i++){
		for(register int j=1;j<=m;j++)
		scanf("%1d",&optdown[i][j]);
	}
	for(register int i=1;i<=qes;i++){
		ans=0;
		memset(vis,false,sizeof(vis));
		clear();
		int col,lv,x,y;
		read(col);
		read(lv);
		read(x);
		read(y);
		map[x][y].color=col;
		map[x][y].level=lv;
		sx=x;
		sy=y;
		q.push(Queue{x,y,false,false,false,false});
		bfs();
		write(ans+1,true);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--)
	solve();
	return 0;
}
//wdnmd ccf
//fuck ccf
//还好这道题只浪费了我半个小时
//半个小时一分都拿不到 我是sb
//现在是12:17分，13分钟我能调的出来？？？？？？？？
//草 才记起来是13点结束 
//update:一个小时一分都拿不到 我是真的sb 
//我吐了 好难调
//这题好恶心 
//I Love Xiaoting
//AFOed 
