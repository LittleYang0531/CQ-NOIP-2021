#include <bits/stdc++.h>
#define pii pair<pair<int,int>,pair<int,int> >
#define fx first.first
#define fy first.second
#define tx second.first
#define ty second.second
#define mp make_pair
using namespace std;
map <pii,int> p;
map <pair<int,int>,bool> vis;
map <pair<int,int>,bool> havechess;
map <pair<int,int>,int> havelevel;
map <pair<int,int>,bool> ans;
int n,m,q;
int cnt;
bool f; 
int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int oknum;
int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void dfs(int col,int lv,int nowx,int nowy,int roadnum,int dxx,int dyy,int cot){
//	cnt++;
//	cout<<nowx<<" "<<nowy<<endl;
	for(int i=0;i<4;i++){
		if(p[mp(mp(nowx,nowy),mp(nowx+dx[i],nowy+dy[i]))]==0){
			continue;
		}
		if((nowx+dx[i]>n||nowx+dx[i]<1)||(nowy+dy[i]>m||nowy+dy[i]<1)){
			continue;
		}
		if(havechess.count(mp(nowx+dx[i],nowy+dy[i]))){
			if(!vis.count(mp(nowx+dx[i],nowy+dy[i]))&&havechess[mp(nowx+dx[i],nowy+dy[i])]!=col&&havelevel[mp(nowx+dx[i],nowy+dy[i])]<=lv&&(roadnum==-1||p[mp(mp(nowx,nowy),mp(nowx+dx[i],nowy+dy[i]))]==roadnum)){
				if(roadnum==2&&(dx[i]!=dxx||dy[i]!=dyy)){
					continue;
				}
				if(roadnum==1&&cot==1){
					continue;
				}
//				havechess.erase(mp(nowx+dx[i],nowy+dy[i]));
//				cnt++;
				ans[mp(nowx+dx[i],nowy+dy[i])]=1;
				vis[mp(nowx+dx[i],nowy+dy[i])]=1;
//				cout<<"1:"<<nowx+dx[i]<<" "<<nowy+dy[i]<<endl;
				continue;
			}
		}
		else{
			if(!vis.count(mp(nowx+dx[i],nowy+dy[i]))&&(roadnum==-1||p[mp(mp(nowx,nowy),mp(nowx+dx[i],nowy+dy[i]))]==roadnum)){
				if(roadnum==2&&(dx[i]!=dxx||dy[i]!=dyy)){
					continue;
				}
				if(roadnum==1&&cot==1){
					continue;
				}
				vis[mp(nowx+dx[i],nowy+dy[i])]=1;
//				cout<<"2:"<<nowx+dx[i]<<" "<<nowy+dy[i]<<endl;
//				cnt++;
				ans[mp(nowx+dx[i],nowy+dy[i])]=1;
				oknum++;
				dfs(col,lv,nowx+dx[i],nowy+dy[i],p[mp(mp(nowx,nowy),mp(nowx+dx[i],nowy+dy[i]))],dx[i],dy[i],cot+1);
			}
		}
	}
	vis.erase(mp(nowx,nowy));
}
void solve(){
	f=false;
	n=read(),m=read(),q=read();
	p.clear();
	havechess.clear();
	havelevel.clear();
	vis.clear();
	cnt=oknum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			char c=getchar();
			while(c<'0'||c>'9'){
				c=getchar();
			}
			if(c-'0'==2||c-'0'==3){
				f=true;
			}
			p[mp(mp(i,j),mp(i,j+1))]=c-'0';
			p[mp(mp(i,j+1),mp(i,j))]=c-'0';
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			char c=getchar();
			while(c<'0'||c>'9'){
				c=getchar();
			}
			if(c-'0'==2||c-'0'==3){
				f=true;
			}
			p[mp(mp(i,j),mp(i+1,j))]=c-'0';
			p[mp(mp(i+1,j),mp(i,j))]=c-'0';
		}
	}
	int col,lv,x,y;
	if(!f){
		while(q--){
			col=read(),lv=read(),x=read(),y=read();
			havechess[mp(x,y)]=col;
			havelevel[mp(x,y)]=lv;
			cnt=0;
			for(int i=0;i<4;i++){
				if(p[mp(mp(x,y),mp(x+dx[i],y+dy[i]))]==0){
					continue;
				}
				else{
					if(havechess.count(mp(x+dx[i],y+dy[i]))){
						if(havechess[mp(x+dx[i],y+dy[i])]!=col&&havelevel[mp(x+dx[i],y+dy[i])]<=lv){
							cnt++;
						}
					}
					else{
						cnt++;
					}
				}
			}
			printf("%d\n",cnt);
		}
		return;
	}
	while(q--){
		col=read(),lv=read(),x=read(),y=read();
		havechess[mp(x,y)]=col;
		havelevel[mp(x,y)]=lv;
		vis.clear();
		ans.clear();
		cnt=0;
		vis[mp(x,y)]=0;
		dfs(col,lv,x,y,-1,-2,-2,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ans.count(mp(i,j))){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
}
int T;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}//24pts~36pts,CCF's magic help me!I want to this code run of 4e8~2e9 don't TLE!!!
//这是一个在提高组靠一个SB DFS 滚进NOIp的彩笔。
//他的洛谷名字叫LEMON_ni，如果你是奇人合集大全的编辑者可以把我放上去。
//今天是遇到你的第318天，318天以前，我发了一条说说，写的是“正是OIerLEMON_ni”
//然后呢？
//就这样，一个男生就开始了梦境般的OI之旅。
//我曾经迷茫过，因为搞不懂并查集为什么可以路径压缩。
//我曾经失败过，因为模拟赛次次比别人考得低
//我曾经……
//无论如何，愿我 RP++，奇迹不再辜负奇迹，自己不再辜负自己。 
