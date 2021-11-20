#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int T,n,m,q;
char *s1[N],*s2[N];
int *cl[N],*lv[N],*mark[N];
inline bool check(int x,int y,int xx,int yy){
	return (!lv[xx][yy]||(cl[x][y]!=cl[xx][yy]&&lv[x][y]>=lv[xx][yy]));
}
namespace solve1{
	void dfs(int x,int y,int xx,int yy){
		mark[x][y]=1;
		if(y<m&&s1[x][y]=='3'){
			bool tmp=mark[x][y+1];
			if(check(xx,yy,x,y+1))mark[x][y+1]=1;
			if(!lv[x][y+1]&&!tmp)dfs(x,y+1,xx,yy);
		}
		if(y>1&&s1[x][y-1]=='3'){
			bool tmp=mark[x][y-1];
			if(check(xx,yy,x,y-1))mark[x][y-1]=1;
			if(!lv[x][y-1]&&!tmp)dfs(x,y-1,xx,yy);
		}
		if(x<n&&s2[x][y]=='3'){
			bool tmp=mark[x+1][y];
			if(check(xx,yy,x+1,y))mark[x+1][y]=1;
			if(!lv[x+1][y]&&!tmp)dfs(x+1,y,xx,yy);
		}
		if(x>1&&s2[x-1][y]=='3'){
			bool tmp=mark[x-1][y];
			if(check(xx,yy,x-1,y))mark[x-1][y]=1;
			if(!lv[x-1][y]&&!tmp)dfs(x-1,y,xx,yy);
		}
	}
	void main(){
		while(q--){
			int c=in(),l=in(),x=in(),y=in();
			cl[x][y]=c,lv[x][y]=l;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)mark[i][j]=0;
			dfs(x,y,x,y);
			mark[x][y]=1;
			if(y<m&&s1[x][y]=='1'&&check(x,y,x,y+1))mark[x][y+1]=1;
			if(y>1&&s1[x][y-1]=='1'&&check(x,y,x,y-1))mark[x][y-1]=1;
			if(x<n&&s2[x][y]=='1'&&check(x,y,x+1,y))mark[x+1][y]=1;
			if(x>1&&s2[x-1][y]=='1'&&check(x,y,x-1,y))mark[x-1][y]=1;
			for(int i=y+1;i<=m;i++){
				if(s1[x][i-1]!='2')break;
				if(check(x,y,x,i))mark[x][i]=1;
				if(lv[x][i])break;
			}
			for(int i=y-1;i>=1;i--){
				if(s1[x][i]!='2')break;
				if(check(x,y,x,i))mark[x][i]=1;
				if(lv[x][i])break;
			}
			for(int i=x+1;i<=n;i++){
				if(s2[i-1][y]!='2')break;
				if(check(x,y,i,y))mark[i][y]=1;
				if(lv[i][y])break;
			}
			for(int i=x-1;i>=1;i--){
				if(s2[i][y]!='2')break;
				if(check(x,y,i,y))mark[i][y]=1;
				if(lv[i][y])break;
			}
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(mark[i][j])ans++;
				}
			}
			printf("%d\n",ans-1);
		}
	}
}
namespace solve2{
	void main(){
		while(q--){
			int c=in(),l=in(),x=in(),y=in();
			cl[x][y]=c,lv[x][y]=l;
			int ans=0;
			if(y<m&&s1[x][y]=='1'&&check(x,y,x,y+1))ans++;
			if(y>1&&s1[x][y-1]=='1'&&check(x,y,x,y-1))ans++;
			if(x<n&&s2[x][y]=='1'&&check(x,y,x+1,y))ans++;
			if(x>1&&s2[x-1][y]=='1'&&check(x,y,x-1,y))ans++;
			printf("%d\n",ans);
		}
	}
}
namespace solve3{
	int *c1[N],*c2[N],*c3[N],*c4[N];
	inline void upd1(int x,int y,int v){
		for(int i=y;i<=m;i+=i&-i)c1[x][i]=max(c1[x][i],v);
	}
	inline void upd2(int x,int y,int v){
		for(int i=y;i>=1;i-=i&-i)c2[x][i]=min(c2[x][i],v);
	}
	inline void upd3(int y,int x,int v){
		for(int i=x;i<=n;i+=i&-i)c3[y][i]=max(c3[y][i],v);
	}
	inline void upd4(int y,int x,int v){
		for(int i=x;i>=1;i-=i&-i)c4[y][i]=min(c4[y][i],v);
	}
	inline int get1(int x,int y){
		int res=1;
		for(int i=y;i>=1;i-=i&-i)res=max(res,c1[x][i]);
		return res;
	}
	inline int get2(int x,int y){
		int res=m;
		for(int i=y;i<=m;i+=i&-i)res=min(res,c2[x][i]);
		return res;
	}
	inline int get3(int x,int y){
		int res=1;
		for(int i=x;i>=1;i-=i&-i)res=max(res,c3[y][i]);
		return res;
	}
	inline int get4(int x,int y){
		int res=n;
		for(int i=x;i<=n;i+=i&-i)res=min(res,c4[y][i]);
		return res;
	}
	void main(){
		for(int i=1;i<=n;i++){
			c1[i]=new int [m+2];
			c2[i]=new int [m+2];
			for(int j=1;j<=m;j++)c1[i][j]=1,c2[i][j]=m;
		}
		for(int i=1;i<=m;i++){
			c3[i]=new int [n+2];
			c4[i]=new int [n+2];
			for(int j=1;j<=n;j++)c3[i][j]=1,c4[i][j]=n;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++)
				if(s1[i][j]!='2'){
					upd1(i,j+1,j+1);
					upd2(i,j,j);
				}
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++)
				if(s2[i][j]!='2'){
					upd3(j,i+1,i+1);
					upd4(j,i,i);
				}
		while(q--){
			int c=in(),l=in(),x=in(),y=in(),ans=0;
			cl[x][y]=c,lv[x][y]=l;
			l=get1(x,y);int r=get2(x,y),u=get3(x,y),d=get4(x,y);
			if(l>1&&s1[x][l-1]=='2'&&check(x,y,x,l-1))l--;
			if(r<m&&s1[x][r]=='2'&&check(x,y,x,r+1))r++;
			if(u>1&&s2[u-1][y]=='2'&&check(x,y,u-1,y))u--;
			if(d<n&&s2[d][y]=='2'&&check(x,y,d+1,y))d++;
			ans+=max(0,r-y),ans+=max(0,y-l),ans+=max(0,x-u),ans+=max(0,d-x);
			if(r<=y&&y<m&&s1[x][y]=='1'&&check(x,y,x,y+1))ans++;
			if(l>=y&&y>1&&s1[x][y-1]=='1'&&check(x,y,x,y-1))ans++;
			if(d<=x&&x<n&&s2[x][y]=='1'&&check(x,y,x+1,y))ans++;
			if(u>=x&&x>1&&s2[x-1][y]=='1'&&check(x,y,x-1,y))ans++;
			if(y<m)upd1(x,y+1,y+1);
			if(y>1)upd2(x,y-1,y-1);
			if(x<n)upd3(y,x+1,x+1);
			if(x>1)upd3(y,x-1,x-1);
			printf("%d\n",ans);
		}
		for(int i=1;i<=n;i++){
			delete c1[i];
			delete c2[i];
		}
		for(int i=1;i<=m;i++){
			delete c3[i];
			delete c4[i];
		}
	}
}
void solve(){
	n=in(),m=in(),q=in();
	for(int i=1;i<=n;i++){
		s1[i]=new char[m+2];
		scanf("%s",s1[i]+1);
	}
	for(int i=1;i<n;i++){
		s2[i]=new char[m+2];
		scanf("%s",s2[i]+1);
	}
	for(int i=1;i<=n;i++){
		cl[i]=new int [m+1];
		lv[i]=new int [m+1];
		for(int j=0;j<=m;j++)lv[i][j]=0;
		mark[i]=new int [m+1];
	}
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++){
			if(s1[i][j]=='2')flag1=0;
			if(s1[i][j]=='3')flag2=0;
		}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(s2[i][j]=='2')flag1=0;
			if(s2[i][j]=='3')flag2=0;
		}
	}
	if(flag1&&flag2)solve2::main();
	else if(flag2)solve3::main();
	else solve1::main();
	for(int i=1;i<=n;i++){
		delete s1[i];
		if(i<n)delete s2[i];
		delete cl[i];
		delete lv[i];
		delete mark[i];
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=in();
	while(T--)solve();
	return 0;
}

