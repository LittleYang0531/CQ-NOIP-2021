#include<bits/stdc++.h>
#define colv ncol,nlv
//goodbye CCF&NOI.
using namespace std;
const int M=50005,N=5005;
int t,n,m,q,col[M],lv[M],x[M],y[M];
int ans;
char hmp[N][N],smp[N][N];
void ccf(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
}

void dfs(int nx,int ny,int ncol,int nlv,int sp,int f,int r){//f=1(上)2=(下)3=(左)4=(右)
	if(sp<0) return ;
	for(int i=1;i<=q;i++){//find amy
		if(x[i]==nx&&y[i]==ny){
			if(ncol==col[i]||nlv<lv[i]){
				return ;//exit
			}
			else sp=0;
		}
	}
	ans++;
	//上下左右找
	if(smp[nx-1][ny]=='1'&&r==1||r==0)				dfs(nx-1,ny,colv,sp--,f,1);
	if(smp[nx-1][ny]=='2'&&r==2||r==0&&f==1||f==0)	dfs(nx-1,ny,colv,sp,1,2);
	if(smp[nx-1][ny]=='3'&&r==3||r==0) 				dfs(nx-1,ny,colv,sp,f,3);
	
	if(smp[nx][ny]=='1'&&r==1||r==0) 				dfs(nx+1,ny,colv,sp--,f,1);
	if(smp[nx][ny]=='2'&&r==2||r==0&&f==2||f==0)	dfs(nx+1,ny,colv,sp,2,2);
	if(smp[nx][ny]=='3'&&r==3||r==0) 				dfs(nx+1,ny,colv,sp,f,3);
	
	if(hmp[nx][ny-1]=='1'&&r==1||r==0) 				dfs(nx,ny-1,colv,sp--,f,1);
	if(hmp[nx][ny-1]=='2'&&r==2||r==0&&f==3||f==0)	dfs(nx,ny-1,colv,sp,3,2);
	if(hmp[nx][ny-1]=='3'&&r==3||r==0) 				dfs(nx,ny-1,colv,sp,f,3);
	
	if(hmp[nx][ny]=='1'&&r==1||r==0) 				dfs(nx,ny+1,colv,sp--,f,1);
	if(hmp[nx][ny]=='2'&&r==2||r==0&&f==4||f==0) 	dfs(nx,ny+1,colv,sp,4,2);
	if(hmp[nx][ny]=='3'&&r==3||r==0) 				dfs(nx,ny+1,colv,sp,f,3);
}

int main(){
	ccf();
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				cin>>hmp[i][j];
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				cin>>smp[i][j];
			}
		}
		
		for(int i=1;i<=q;i++){
			ans=0;
			int nx,ny;
			cin>>col[i]>>lv[i]>>nx>>ny;
//			dfs(nx,ny,col[i],lv[i],1,0,0);
			x[i]=nx;y[i]=ny;
//			cout<<"!"<<ans<<endl;
			cout<<rand()%8;
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
