#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int t;
int n,m,q;
int gx[5]={0,-1,0,1,0},gy[5]={0,0,1,0,-1};
int bt[5]={0,3,4,1,2};
struct node{ //u--1,r--2,d--3,l--4;
	int dir[5];
	bool k;
	int vl,col;
}dot[5005][5005];
bool doted[5005][5005];
int road,wnt=0;
inline void go(int x,int y,int r,int dir,int col,int lv){
	if(dot[x][y].k==1&&(dot[x][y].col==col||(dot[x][y].col!=col&&dot[x][y].vl>lv))) return ;
	if(doted[x][y]==0) wnt++;
	doted[x][y]=1;
	if(dot[x][y].k==1) return ;
	if(r==1) return ;
	if(r==2){
		if(dot[x][y].dir[dir]==2) go(x+gx[dir],y+gy[dir],r,dir,col,lv);
	}
	if(r==3){
		for(int i=1;i<=4;i++){
			if(dot[x][y].dir[i]==3&&i!=bt[dir]) go(x+gx[i],y+gy[i],r,i,col,lv);
		}
	}
} 
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&q);
		for(int i=1;i<=n;i++){
			char a;
			for(int j=1;j<=m-1;j++){
				scanf("%c",&a);
				dot[i][j].dir[2]=int(a-'0');
				dot[i][j+1].dir[4]=int(a-'0');
			}
		}
		for(int i=1;i<=n-1;i++){
			char a;
			for(int j=1;j<=m;j++){
				scanf("%c",&a);
				dot[i][j].dir[3]=int(a-'0');
				dot[i+1][j].dir[1]=int(a-'0');
			}
		}
		while(q--){
			memset(doted,0,sizeof(doted));
			wnt=0;
			int a,b,c,d;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			dot[c][d].k=1,dot[c][d].vl=b,dot[c][d].col=a;
			doted[c][d]=1;
			for(int i=1;i<=4;i++){
				if(dot[a][b].dir[i]!=0) go(c+gx[i],d+gy[i],dot[a][b].dir[i],i,a,b);
			}
			printf("%d\n",wnt);
		}
	}
	
	return 0;
}
//soccer:0
//NOIP NB
//CCF NB
