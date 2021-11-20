#include<bits/stdc++.h>
#define N 200005
typedef long long ll;
using namespace std;
inline int read(void){
	char opt;int res=0,flag=1;
	while((opt=getchar())<'0'||opt>'9')if(opt=='-')flag=-1;
	while(opt>='0'&&opt<='9')res=res*10+opt-'0',opt=getchar();
	return res*flag;
}
inline char gc(void){
	char opt;
	while((opt=getchar())<'0'||opt>'9');
	return opt;
}
int Case,n,m,q,X[N],Y[N],lv[N],c[N],vis[N],used[N],res,st[N],top;
char A[N],B[N];
inline int POS(int x,int y){return (x-1)*m+y;}
inline int Attack(int a,int b){
	return c[a]!=c[b]&&lv[a]>=lv[b];
}
inline int Dir(int x,int y,int dx,int dy,int pos){
	if(x<1||y<1||x>n||y>m)return 0;
	if(used[POS(x,y)])return Attack(pos,used[POS(x,y)]);
	if(dx==-1&&B[POS(x-1,y)]=='2')return 1+Dir(x+dx,y+dy,dx,dy,pos);
	if(dx==1&&B[POS(x,y)]=='2')return 1+Dir(x+dx,y+dy,dx,dy,pos);
	if(dy==-1&&A[POS(x,y-1)]=='2')return 1+Dir(x+dx,y+dy,dx,dy,pos);
	if(dy==1&&A[POS(x,y)]=='2')return 1+Dir(x+dx,y+dy,dx,dy,pos);
	return 1;
}
inline void Ran(int x,int y,int pos){
	if(x<1||y<1||x>n||y>m)return ;
	if(vis[POS(x,y)])return ;++res;
	vis[st[++top]=POS(x,y)]=1;
	if(used[POS(x,y)])return void(res+=Attack(pos,used[POS(x,y)]));
	if(B[POS(x-1,y)]=='3')Ran(x-1,y,pos);
	if(B[POS(x,y)]=='3')Ran(x+1,y,pos);
	if(A[POS(x,y-1)]=='3')Ran(x,y-1,pos);
	if(A[POS(x,y)]=='3')Ran(x,y+1,pos);
}
inline void Solve1(void){
	int i,j;
	for(i=1;i<=q;++i){
		scanf("%d%d%d%d",c+i,lv+i,X+i,Y+i);
		res=0;
		vis[st[++top]=POS(X[i],Y[i])]=1;
		if(Y[i]>1&&A[POS(X[i],Y[i]-1)]!='0'){
			if(A[POS(X[i],Y[i]-1)]=='1'&&Attack(i,used[POS(X[i],Y[i]-1)]))++res;
			if(A[POS(X[i],Y[i]-1)]=='2')res+=Dir(X[i],Y[i]-1,0,-1,i);
			if(A[POS(X[i],Y[i]-1)]=='3')Ran(X[i],Y[i]-1,i);
		}
		if(X[i]>1&&B[POS(X[i]-1,Y[i])]!='0'){
			if(B[POS(X[i]-1,Y[i])]=='1'&&Attack(i,used[POS(X[i]-1,Y[i])]))++res;
			if(B[POS(X[i]-1,Y[i])]=='2')res+=Dir(X[i]-1,Y[i],-1,0,i);
			if(B[POS(X[i]-1,Y[i])]=='3')Ran(X[i]-1,Y[i],i);
		}
		if(Y[i]<m&&A[POS(X[i],Y[i])]!='0'){
			if(A[POS(X[i],Y[i])]=='1'&&Attack(i,used[POS(X[i],Y[i]+1)]))++res;
			if(A[POS(X[i],Y[i])]=='2')res+=Dir(X[i],Y[i]+1,0,+1,i);
			if(A[POS(X[i],Y[i])]=='3')Ran(X[i],Y[i]+1,i);
		}
		if(X[i]<n&&B[POS(X[i],Y[i])]!='0'){
			if(B[POS(X[i],Y[i])]=='1'&&Attack(i,used[POS(X[i]+1,Y[i])]))++res;
			if(B[POS(X[i],Y[i])]=='2')res+=Dir(X[i]+1,Y[i],+1,0,i);
			if(B[POS(X[i],Y[i])]=='3')Ran(X[i]+1,Y[i],i);
		}
		while(top)vis[st[top--]]=0;
		used[POS(X[i],Y[i])]=i;
		printf("%d\n",res);
	}
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)used[POS(i,j)]=0;
	for(i=0;i<=n+1;++i)for(j=0;j<=m+1;++j)A[POS(i,j)]=' ';
	for(i=0;i<=n+1;++i)for(j=0;j<=m+1;++j)B[POS(i,j)]=' ';
}
inline void Solve(void){
	int i,j;n=read(),m=read(),q=read();
	for(i=1;i<=n;++i)for(j=1;j<m;++j)A[POS(i,j)]=gc();
	for(i=1;i<n;++i)for(j=1;j<=m;++j)B[POS(i,j)]=gc();
	if(n*m<=5000&&q<=2000)return Solve1();
}
int main(void){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	Case=read();
	while(Case--)Solve(); 
	return 0;
}

