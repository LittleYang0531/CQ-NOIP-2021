#include<stdio.h>
#include<vector>
using namespace std;
#define R register int
#define I inline
#define N 200001
const int DIR[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[N];
struct Edges{
	int Item[4];
};
vector<Edges>A[N],B[N];
vector<int>C[2][N],D[N];
I bool Check(int x,int y,int t,int c,int v,int d){
	if(C[c][x][y]!=0||C[c^1][x][y]>v||B[x][y].Item[d]==t){
		return false;
	}
	return true;
}
I int DFS2(int x,int y,int d,int c,int v,int t,const int n,const int m){
	B[x][y].Item[d^2]=t;
	int res=D[x][y]!=t,vx=DIR[d][0]+x,vy=DIR[d][1]+y;
	D[x][y]=t;
	if(C[c^1][x][y]==0&&vx!=-1&&vy!=-1&&vx!=n&&vy!=m&&A[x][y].Item[d]==2&&Check(vx,vy,t,c,v,d^2)==true){
		res+=DFS2(vx,vy,d,c,v,t,n,m);
	}
	return res;
}
I int DFS3(int x,int y,int d,int c,int v,int t,const int n,const int m){
	B[x][y].Item[d^2]=t;
	int res=D[x][y]!=t,vx,vy;
	D[x][y]=t;
	if(C[c^1][x][y]==0){
		for(R i=0;i!=4;i++){
			vx=x+DIR[i][0];
			vy=y+DIR[i][1];
			if(vx!=-1&&vy!=-1&&vx!=n&&vy!=m&&A[x][y].Item[i]==3&&Check(vx,vy,t,c,v,i^2)==true){
				res+=DFS3(vx,vy,i,c,v,t,n,m);
			}
		}
	}
	return res;
}
I void Solve(){
	int n,m,q,x,y,c,v,ans,vx,vy;
	scanf("%d%d%d",&n,&m,&q);
	for(R i=0;i!=n;i++){
		vector<int>().swap(D[i]);
		vector<int>().swap(C[0][i]);
		vector<int>().swap(C[1][i]);
		vector<Edges>().swap(B[i]);
		vector<Edges>().swap(A[i]);
	}
	for(R i=0;i!=n;i++){
		A[i].resize(m);
		B[i].resize(m);
		C[0][i].resize(m);
		C[1][i].resize(m);
		D[i].resize(m);
		scanf("%s",s);
		for(R j=1;j!=m;j++){
			A[i][j-1].Item[0]=A[i][j].Item[2]=s[j-1]-'0';
		}
	}
	for(R i=1;i!=n;i++){
		scanf("%s",s);
		for(R j=0;j!=m;j++){
			A[i-1][j].Item[1]=A[i][j].Item[3]=s[j]-'0';
		}
	}
	for(R i=1;i<=q;i++){
		ans=0;
		scanf("%d%d%d%d",&c,&v,&x,&y);
		x--;
		y--;
		C[c][x][y]=v;
		for(R j=0;j!=4;j++){
			vx=x+DIR[j][0];
			vy=y+DIR[j][1];
			if(vx!=-1&&vy!=-1&&vx!=n&&vy!=m){
				if(A[x][y].Item[j]==1){
					if(Check(vx,vy,i,c,v,j^2)==true){
						if(D[vx][vy]!=i){
							ans++;
							D[vx][vy]=i;
						}
						B[vx][vy].Item[j^2]=i;
					}
				}else if(A[x][y].Item[j]==2){
					if(Check(vx,vy,i,c,v,j^2)==true){
						ans+=DFS2(vx,vy,j,c,v,i,n,m);
					}
				}else if(A[x][y].Item[j]==3){
					if(Check(vx,vy,i,c,v,j^2)==true){
						ans+=DFS3(vx,vy,j,c,v,i,n,m);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
