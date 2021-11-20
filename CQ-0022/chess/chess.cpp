#include<bits/stdc++.h>
#define _R register
#define _I inline
#define ll long long
#define mod 998244353
#define eps 1e-4
#define INF 0x3f3f3f3f
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define lowbit(i) (i&(-i))
#define x0 xx0
#define y0 yy0
#define y1 yy1
#define x1 xx1 
using namespace std;
//char buf[1<<19],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin),(p1==p2))?EOF:*p1++)
int read(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=200005;
int t,n,m,Q,num,p[N][5],col[N],lv[N];
int dx[5]={0,0,1,-1},dy[5]={1,-1,0,0};
vector<int>id[N],v[N],vst[5][N],as[N];
struct note{int x,y,d;};
queue<note>q;
vector<note>cr;
signed main(){
//	system("fc chess3.out chess3.ans");
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--){
		n=read();m=read();Q=read();num=0;
		for(_R int i=1;i<=n;++i)id[i].clear(),id[i].resize(m+1),v[i].clear(),v[i].resize(m+1),as[i].clear(),as[i].resize(m+1);
		for(_R int i=1;i<=n;++i)for(_R int j=0;j<5;++j)vst[j][i].clear(),vst[j][i].resize(m+1);memset(p,0);
		for(_R int i=1;i<=n;++i)for(_R int j=1;j<=m;++j)id[i][j]=++num;char ch;
		for(_R int i=1;i<=n;++i)for(_R int j=1;j<m;++j){
			do ch=getchar();while(ch!='0'&&ch!='1'&&ch!='2'&&ch!='3');
			p[id[i][j]][0]=p[id[i][j+1]][1]=(ch-'0');
		}
		for(_R int i=1;i<n;++i)for(_R int j=1;j<=m;++j){
			do ch=getchar();while(ch!='0'&&ch!='1'&&ch!='2'&&ch!='3');
			if(ch!='2')p[id[i][j]][2]=p[id[i+1][j]][3]=(ch-'0');
			else p[id[i][j]][2]=p[id[i+1][j]][3]=4;
		}
		for(_R int i=1,x0,y0;i<=Q;++i){
			 col[i]=read();lv[i]=read();x0=read();y0=read();int ans=0;
			 q.push((note){x0,y0,0});int x,y,d;vst[0][x][y]=1;
			 while(!q.empty()){
			 	note tmp=q.front();q.pop();
			 	x=tmp.x;y=tmp.y;d=tmp.d;cr.push_back(tmp);
//			 	cout<<x<<" "<<y<<" "<<d<<"\n";
			 	if(v[x][y])continue;
			 	for(_R int k=0,nx,ny,dd;k<4;++k){
			 		nx=x+dx[k];ny=y+dy[k];
			 		if(nx<1||nx>n||ny<1||ny>m)continue;
			 		if((!d&&p[id[x][y]][k]!=0)||(d==p[id[x][y]][k]&&d!=1&&(d+p[id[x][y]][k]))){
			 			dd=p[id[x][y]][k];if(!vst[dd][nx][ny])vst[dd][nx][ny]=1,q.push((note){nx,ny,dd});
					}
				 }
			 }
			 note tmp;
			 for(_R int j=0;j<cr.size();++j){tmp=cr[j];
			 	x=tmp.x;y=tmp.y;d=tmp.d;
			 	if(x==x0&&y==y0)continue;
			 	if(as[x][y])continue;as[x][y]=1;
			 	if(v[x][y]){
			 		if(col[i]!=col[v[x][y]]&&lv[i]>=lv[v[x][y]])++ans;
				}else{
					++ans;//cout<<x<<" "<<y<<"\n";
				}
			 }
			 for(_R int j=0;j<cr.size();++j)tmp=cr[j],vst[tmp.d][tmp.x][tmp.y]=0,as[tmp.x][tmp.y]=0;
			 cr.clear();printf("%d\n",ans);
			 v[x0][y0]=i;
		}
	}
	return 0;
}

