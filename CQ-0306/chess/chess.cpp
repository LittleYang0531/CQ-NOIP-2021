#include<cstdio>
#include<cctype>
#include<vector>
const int M=2e5+5,fx[]={0,1,0,-1},fy[]={1,0,-1,0};
int T,n,m,q;std::vector<int>a[M],b[M],col[M],lv[M];std::vector<bool>vis[M],V[M];
inline bool check(const int&x,const int&y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void DFS(const int&x,const int&y,const int&Lv,const int&Col,const int&typ,const int&fp){
	vis[x][y]=true;
	if(lv[x][y]){
//		printf("-11451419260817\n");
		return void(Col!=col[x][y]&&Lv>=lv[x][y]&&(V[x][y]=true));
	}
	V[x][y]=true;//printf("-{%d,%d,%d,%d,%d,%d}---\n",x,y,Lv,Col,typ,fp);
	for(int i=0;i<4;++i){
		int tx=x+fx[i],ty=y+fy[i];
		if(!check(tx,ty)||vis[tx][ty])continue;//printf("{%d,%d}%d\n",tx,ty,i);
		if(i==0){
			if(b[x][y]^typ)continue;
			if(typ==2&&i==fp)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq00\n");
			if(typ==3)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq01\n");
		}
		if(i==1){
			if(a[x][y]^typ)continue;
			if(typ==2&&i==fp)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq10\n");
			if(typ==3)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq11\n");
		}
		if(i==2){
			if(b[x][y-1]^typ)continue;
			if(typ==2&&i==fp)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq20\n");
			if(typ==3)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq21\n");
		}
		if(i==3){
			if(a[x-1][y]^typ)continue;
			if(typ==2&&i==fp)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq30\n");
			if(typ==3)DFS(tx,ty,Lv,Col,typ,i);//,printf("qaq31\n");
		}
	}
}
void Clear(const int&x,const int&y){
	vis[x][y]=false;
	for(int i=0;i<4;++i){
		int tx=x+fx[i],ty=y+fy[i];
		if(check(tx,ty)&&vis[tx][ty])Clear(tx,ty);
	}
}
void clear(const int&x,const int&y){
	V[x][y]=false;
	for(int i=0;i<4;++i){
		int tx=x+fx[i],ty=y+fy[i];
		if(check(tx,ty)&&V[tx][ty])clear(tx,ty);
	}
}
inline int read(){
	int n(0);char s;while(!isdigit(s=getchar()));
	while(n=n*10+(s&15),isdigit(s=getchar()));return n;
}
inline int read_I(){
	char s;while(!isdigit(s=getchar()));return s&15;
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,col,lv,x,y;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(i=0;i<=n;++i){
			std::vector<int>().swap(a[i]);a[i].resize(m+1);
			std::vector<int>().swap(b[i]);b[i].resize(m+1);
			std::vector<bool>().swap(V[i]);V[i].resize(m+1);
			std::vector<bool>().swap(vis[i]);vis[i].resize(m+1);
			std::vector<int>().swap(::lv[i]);::lv[i].resize(m+1);
			std::vector<int>().swap(::col[i]);::col[i].resize(m+1);
		}
		for(i=1;i<=n;++i)for(j=1;j<m;++j)b[i][j]=read_I();
		for(i=1;i<n;++i)for(j=1;j<=m;++j)a[i][j]=read_I();
		while(q--){
			int sum(0);col=read();lv=read();x=read();y=read();V[x][y]=true;
			for(i=0;i<4;++i){
				int tx=x+fx[i],ty=y+fy[i];vis[x][y]=true;
				if(!check(tx,ty))continue;//printf("{%d,%d}\n",tx,ty);
				if(i==0){
					if(!b[x][y])continue;
					if(b[x][y]==1){
						((!::lv[tx][ty])||(lv>=::lv[tx][ty]&&col!=::col[tx][ty]))&&(V[tx][ty]=true);
					}
					else DFS(tx,ty,lv,col,b[x][y],i);
				}
				if(i==1){
					if(!a[x][y])continue;
					if(a[x][y]==1){
						((!::lv[tx][ty])||(lv>=::lv[tx][ty]&&col!=::col[tx][ty]))&&(V[tx][ty]=true);
					}
					else DFS(tx,ty,lv,col,a[x][y],i);
				}
				if(i==2){
					if(!b[x][y-1])continue;
					if(b[x][y-1]==1){
						((!::lv[tx][ty])||(lv>=::lv[tx][ty]&&col!=::col[tx][ty]))&&(V[tx][ty]=true);
					}
					else DFS(tx,ty,lv,col,b[x][y-1],i);
				}
				if(i==3){
					if(!a[x-1][y])continue;
					if(a[x-1][y]==1){
						((!::lv[tx][ty])||(lv>=::lv[tx][ty]&&col!=::col[tx][ty]))&&(V[tx][ty]=true);
					}
					else DFS(tx,ty,lv,col,a[x-1][y],i);
				}
				Clear(x,y);
			}
			for(i=1;i<=n;++i)for(j=1;j<=m;++j)if(V[i][j])++sum;clear(x,y);
			printf("%d\n",sum-1);::col[x][y]=col;::lv[x][y]=lv;
		}
	}
}
/*
2
3 3 5
02
12
22
100
023
1 0 3 3
*/
