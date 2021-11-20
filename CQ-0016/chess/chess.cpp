#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAXN 200005
#define pb push_back
#define mkpr make_pair
#define fir first
#define sec second
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int T,n,m,Q,mp[MAXN][5],tim;
int col[MAXN],lv[MAXN],vis[MAXN];
int dx[5]={0,0,1,-1},dy[5]={1,-1,0,0};
char str[MAXN];
int Id(int x,int y){return (x-1)*m+y;}
set<int>sx[MAXN],sy[MAXN];
set<int>::iterator it;
queue<pii>q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	while(T--){
		read(n);read(m);read(Q);
		for(int i=1;i<=n;i++){
			scanf("\n%s",str+1);
			for(int j=1;j<m;j++)
				mp[Id(i,j)][0]=mp[Id(i,j+1)][1]=str[j]-'0',str[j]=0;
		}
		for(int i=1;i<n;i++){
			scanf("\n%s",str+1);
			for(int j=1;j<=m;j++)
				mp[Id(i,j)][2]=mp[Id(i+1,j)][3]=str[j]-'0',str[j]=0;
		}
		for(int i=1;i<=n;i++){
			sx[i].insert(0);sx[i].insert(m+m);
			for(int j=1;j<m;j++)
				if(mp[Id(i,j)][0]!=2)
					sx[i].insert(j+j);
		}
		for(int j=1;j<=m;j++){
			sy[j].insert(0);sy[j].insert(n+n);
			for(int i=1;i<n;i++)
				if(mp[Id(i,j)][2]!=2)
					sy[j].insert(i+i);
		}
		for(int i=1;i<=n*m;i++)col[i]=-1;
		for(int i=1;i<=Q;i++){
			int a,b,x,y,res=0;read(a);read(b);read(x);read(y);tim++;
			
			it=sx[x].lower_bound(y+y-1);int tmp=(*it),lx=0,ly=0,rx=0,ry=0;
			res+=(tmp/2-y);ry=tmp/2;
			if((tmp&1)&&col[Id(x,(tmp+1)/2)]==(a^1)&&b>=lv[Id(x,(tmp+1)/2)])res++,ry++;
			it--;tmp=(*it);ly=(tmp+1)/2+1;
			res+=(y-(tmp+1)/2-1);
			if((tmp&1)&&col[Id(x,(tmp+1)/2)]==(a^1)&&b>=lv[Id(x,(tmp+1)/2)])res++,ly--;
			
			it=sy[y].lower_bound(x+x-1);tmp=(*it);
			res+=(tmp/2-x);rx=tmp/2;
			if((tmp&1)&&col[Id((tmp+1)/2,y)]==(a^1)&&b>=lv[Id((tmp+1)/2,y)])res++,rx++;
			it--;tmp=(*it);lx=(tmp+1)/2+1;
			res+=(x-(tmp+1)/2-1);
			if((tmp&1)&&col[Id((tmp+1)/2,y)]==(a^1)&&b>=lv[Id((tmp+1)/2,y)])res++,lx--;
			
			//printf("until:%d %d %d %d %d\n",res,lx,rx,ly,ry);
			while(!q.empty())q.pop();q.push(mkpr(x,y));vis[Id(x,y)]=tim;
			while(!q.empty()){
				pii u=q.front();q.pop();int p=Id(u.fir,u.sec);
				for(int j=0;j<4;j++)if(mp[p][j]==3){
					int tx=u.fir+dx[j],ty=u.sec+dy[j];
					if(vis[Id(tx,ty)]==tim||tx<1||tx>n||ty<1||ty>m)continue;
					int pp=Id(tx,ty);vis[pp]=tim;//printf("try %d %d %d\n",tx,ty,col[pp]);
					if(col[pp]!=-1){
						if(tx==x&&ly<=ty&&ty<=ry)continue;
						if(ty==y&&lx<=tx&&tx<=rx)continue;
						if(col[pp]==(a^1)&&lv[pp]<=b)
							res++;
						continue;
					}
					q.push(mkpr(tx,ty));res++;
					if(tx==x&&ly<=ty&&ty<=ry)res--;
					if(ty==y&&lx<=tx&&tx<=rx)res--;
				}
			}
			for(int j=0;j<4;j++)
				if(mp[Id(x,y)][j]==1){
					int tx=x+dx[j],ty=y+dy[j];if(vis[Id(tx,ty)]==tim)continue;
					if(col[Id(tx,ty)]==-1)res++;
					if(col[Id(tx,ty)]==(a^1)&&b>=lv[Id(tx,ty)])res++;
				}
			printf("%d\n",res);
			sx[x].insert(y+y-1);
			sy[y].insert(x+x-1);
			col[Id(x,y)]=a;lv[Id(x,y)]=b;
		}
		for(int i=1;i<=n;i++)sx[i].clear();
		for(int i=1;i<=m;i++)sy[i].clear();
		for(int i=1;i<=n*m;i++){
			for(int k=0;k<4;k++)mp[i][k]=0;
			col[i]=lv[i]=0;	
		}
	}
	return 0;
}
/*
God bless my king,
it's a bright light day.
Let us worship in your triumph.
*/
