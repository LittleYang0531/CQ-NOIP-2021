#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=5e3+10;
int T;
int n,m,q;
char c[N];
int dx[]={0,-1,1,0,0};
int dy[]={0,0,0,-1,1};
int ans;

struct node{
	int up,down,left,right;
	bool had;
	int co,lv;
	bool vis;
	int eaten;
};

int eatcode;

//vector<node,vector<node> > point;
node point[M][M] ;
vector<node> input;

int check(int x,int y,int co,int lv){
	if(point[x][y].had==false) return 1;
	else{
		if(point[x][y].co==co||point[x][y].lv>lv) return 0;
		else return 2;
	}
}

void ff(int x,int y,int co,int lv){
	point[x][y].vis=true;
	int status=check(x,y,co,lv);
	
	if(status==2){
		if(point[x][y].eaten!=eatcode) ans++;
		point[x][y].eaten=eatcode;	
	}else if(status==1){
		ans++;
		for(int i=1;i<=4;i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(point[xx][yy].vis) continue;
			if(i==1&&point[x][y].up!=3) continue;
			if(i==2&&point[x][y].down!=3) continue;
			if(i==3&&point[x][y].left!=3) continue;
			if(i==4&&point[x][y].right!=3) continue;
			ff(xx,yy,co,lv);
		}
	}
	point[x][y].vis=false;
}

void dfs(int x,int y,int mode,int pos,int co,int lv){//1=up,2=down,3=left,4=right
//mode -1=start, 1=usual, 2=strait, 3=aonnect
	if(mode==-1){
		if(point[x][y].up!=0&&point[x][y].up!=-1) dfs(x-1,y,point[x][y].up,1,co,lv);
		if(point[x][y].down!=0&&point[x][y].down!=-1) dfs(x+1,y,point[x][y].down,2,co,lv);
		if(point[x][y].left!=0&&point[x][y].left!=-1) dfs(x,y-1,point[x][y].left,3,co,lv);
		if(point[x][y].right!=0&&point[x][y].right!=-1) dfs(x,y+1,point[x][y].right,4,co,lv);
	}
	if(mode==1){
		if(check(x,y,co,lv)) ans++;
		return;
	}
	if(mode==2){
		while(true){
			int status=check(x,y,co,lv);
			if(status) ans++;
			if(status==2||status==0){
				return;
			}
			
//			if(point[x+dx[pos]][y+dy[pos]]==2) x+=dx[pos],y+=dy[pos];
			if(pos==1&&point[x][y].up==2) x+=dx[pos],y+=dy[pos];
			if(pos==2&&point[x][y].down==2) x+=dx[pos],y+=dy[pos];
			if(pos==3&&point[x][y].left==2) x+=dx[pos],y+=dy[pos];
			if(pos==4&&point[x][y].right==2) x+=dx[pos],y+=dy[pos];
			else{
				return;
			}
		}
	}
	if(mode=3){
		ff(x,y,co,lv);
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
//		point.clear();
//		input.clear();
		scanf("%d%d%d",&n,&m,&q);
//		scanf("\n");
//		int MAX=max(n,m);
//		for(int i=0;i<=m;i++){
//			input.push_back({-1,-1,-1,-1,false,0,0,false,0});
//		}
//		for(int i=0;i<=n;i++){
//			point.push_back(input);
//		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				point[i][j]={-1,-1,-1,-1,false,0,0,false,0};
			}
		}
//		scanf("\n");
		for(int i=1;i<=n;i++){
			scanf("%s",c+1);
			for(int j=1;j<m;j++){
				int status=c[j]-'0';
				point[i][j].right=point[i][j+1].left=status;
			}	
		}
		for(int i=1;i<n;i++){
			scanf("%s",c+1);
			for(int j=1;j<=m;j++){
				int status=c[j]-'0';
				point[i][j].down=point[i+1][j].up=status;
			}
		}
		
		for(int i=1;i<=q;i++){
			int co,lv,x,y;
			eatcode++;
			scanf("%d%d%d%d",&co,&lv,&x,&y);
			point[x][y].had=true;
			point[x][y].co=co;
			point[x][y].lv=lv;
			ans=0;
			dfs(x,y,-1,-1,co,lv);
			printf("%d\n",ans);
		}
	}
	return 0;
}

