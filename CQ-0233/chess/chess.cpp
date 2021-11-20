#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
//vector<int> a[2600],b[2600];
int T,n,m,q,a[2550][2550],col[2010],lv[2010],x[2010],y[2010],ans,ou,vis[2550][2550];
char ch1[2550][2550],ch2[2550][2550];
bool in(int ew,int xw){
	return 1<=ew&&ew<=n&&1<=xw&&xw<=m;
}
void dfs(int nx,int ny,bool eat){
	if(!in(nx,ny)) return;
	vis[nx][ny]=1;
	if(ch2[nx-1][ny]=='3'&&vis[nx-1][ny]==0){
//		puts("#U");
//		cout<<nx-1<<' '<<ny<<endl;
		int su=a[nx-1][ny];
		if(su==0){
			ans++;
			dfs(nx-1,ny,0);
		}else if(eat==0&&col[su]!=col[ou]&&lv[ou]>=lv[su]){
			
			ans++;
			return;
		}
		vis[nx-1][ny]=1;
	}
	if(ch1[nx][ny-1]=='3'&&vis[nx][ny-1]==0){
//		puts("#L");
//		cout<<nx<<' '<<ny-1<<endl;
		int su=a[nx][ny-1];
		if(su==0){
			ans++;
			dfs(nx,ny-1,0);
		}else if(eat==0&&col[su]!=col[ou]&&lv[ou]>=lv[su]){
			ans++;
			vis[nx][ny-1]=1;
			return;
		}
	}
	if(ch1[nx][ny]=='3'&&vis[nx][ny+1]==0){
//		puts("#R");
//		cout<<nx<<' '<<ny+1<<endl;
		int su=a[nx][ny+1];
		if(su==0){
			ans++;
//			puts("EEE");
			dfs(nx,ny+1,0);
		}else if(eat==0&&col[su]!=col[ou]&&lv[ou]>=lv[su]){
			ans++;
			vis[nx][ny+1]=1;
			return;
		}
	}
	if(ch2[nx][ny]=='3'&&vis[nx+1][ny]==0){
//		puts("#D");
//		cout<<nx+1<<' '<<ny<<endl;
		int su=a[nx+1][ny];
		if(su==0){
			ans++;
			dfs(nx+1,ny,0);
		}else if(eat==0&&col[su]!=col[ou]&&lv[ou]>=lv[su]){
			ans++;
			vis[nx+1][ny]=1;
			return;
		}
	}
}
void straight(int ee){
	int xx=x[ee],yy=y[ee],xxx,yyy,su;
	xxx=xx,yyy=yy;
	while(ch2[xxx-1][yyy]=='2'&&a[xxx-1][yyy]==0&&in(xxx-1,yyy)) vis[xxx-1][yyy]=1,xxx--,ans++;
	su=a[xxx-1][yyy];
	if(su&&col[su]!=col[ee]&&lv[ee]>=lv[su]&&in(xxx-1,yyy)) vis[xxx-1][yyy]=1,ans++;
	xxx=xx,yyy=yy;
	while(ch1[xxx][yyy-1]=='2'&&a[xxx][yyy-1]==0&&in(xxx,yyy-1)) vis[xxx][yyy-1]=1,yyy--,ans++;
	su=a[xxx][yyy-1];
	if(su&&col[su]!=col[ee]&&lv[ee]>=lv[su]&&in(xxx,yyy-1)) vis[xxx][yyy-1]=1,ans++;
	xxx=xx,yyy=yy;
	while(ch1[xxx][yyy]=='2'&&a[xxx][yyy+1]==0&&in(xxx,yyy+1)) vis[xxx][yyy+1]=1,yyy++,ans++;
	su=a[xxx][yyy+1];
//	if(ee==2) cout << "####" << xxx << ' ' << yyy << ' ' << su << endl;
//	if(ee==2) cout << "####" << su << ' ' << bool(col[su]!=col[ee]) << ' ' << (bool)(lv[ee]>=lv[su]) << endl;
	if(su&&col[su]!=col[ee]&&lv[ee]>=lv[su]&&in(xxx,yyy+1)) vis[xxx][yyy+1]=1,ans++;
	xxx=xx,yyy=yy;
	while(ch2[xxx][yyy]=='2'&&a[xxx+1][yyy]==0&&in(xxx+1,yyy)) vis[xxx+1][yyy]=1,xxx++,ans++;
	su=a[xxx+1][yyy];
//	if(ee==2) cout<<"####" <<lv[ee] << ' ' << lv[su] << endl;
	if(su&&col[su]!=col[ee]&&lv[ee]>=lv[su]&&in(xxx+1,yyy)) vis[xxx+1][yyy]=1,ans++;
	return;
}
void simple(int ee){
	int xx=x[ee],yy=y[ee],su;
	su=a[xx-1][yy];
	if(vis[xx-1][yy]==0&&in(xx-1,yy)&&ch2[xx-1][yy]=='1'&&(su==0||su&&col[su]!=col[ee]&&lv[ee]>=lv[su])) vis[xx-1][yy]=1,ans++;
	su=a[xx][yy-1];
	if(vis[xx][yy-1]==0&&in(xx,yy-1)&&ch1[xx][yy-1]=='1'&&(su==0||su&&col[su]!=col[ee]&&lv[ee]>=lv[su])) vis[xx][yy-1]=1,ans++;
	su=a[xx][yy+1];
	if(vis[xx][yy+1]==0&&in(xx,yy+1)&&ch1[xx][yy]=='1'&&(su==0||su&&col[su]!=col[ee]&&lv[ee]>=lv[su])) vis[xx][yy+1]=1,ans++;
	su=a[xx+1][yy];
	if(vis[xx+1][yy]==0&&in(xx+1,yy)&&ch2[xx][yy]=='1'&&(su==0||su&&col[su]!=col[ee]&&lv[ee]>=lv[su])) vis[xx+1][yy]=1,ans++;
	return;
}
void flat(){
	memset(a,0,sizeof(a));
	for(int i=0;i<2550;i++){
		for(int j=0;j<2550;j++){
			ch1[i][j]=ch2[i][j]='8';
		}
	}
//	for(int i=1;i<=n;i++) a[i][0]=a[i][m+1]=200000;
	scanf("%d%d%d",&n,&m,&q);getchar();
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++) ch1[i][j]=getchar();
		getchar();
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++) ch2[i][j]=getchar();
		getchar();
	}
//	cout << endl << endl;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<m;j++) cout<<ch1[i][j];
//		cout<<endl;
//	}
//	for(int i=1;i<n;i++){
//		for(int j=1;j<=m;j++) cout<<ch2[i][j];
//		cout<<endl;
//	}
	for(int i=1;i<=q;i++){
//		cout << "\nCASE#" << i << ":\n";
		scanf("%d%d%d%d",&col[i],&lv[i],&x[i],&y[i]);
		a[x[i]][y[i]]=i;
		ans=0;
		
		memset(vis,0,sizeof(vis));
		straight(i);
//		cout << ans << endl;
		simple(i);
//		cout << ans << endl;
		ou=i;
		dfs(x[i],y[i],0);//must 3
//		ans=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++) ans+=vis[i][j];
//		}
//		ans--;
		printf("%d\n",ans);
	}
	return;
}
int main(){
	freopen("chess3.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--) flat();
	return 0;
}
