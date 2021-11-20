#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while('0'<=ch&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*w;
}
int t;
int ans;
int n,m,q;
int cnt;
int h[MAXN];
int num[5005][5005];
bool blog[5005][5005],mmap[5005][5005],bb[5005][5005],nb[5005][5005];
struct work{
	int next,to,val;
}w[MAXN*4];
inline void qxx(int x,int y,int z){
	w[++cnt]=(work){h[x],y,z};
	h[x]=cnt;
}
inline void dfs(int x,int y,int flag,int fx,int lvv,bool coll,int sum){
	bb[x][y]=true;
	int u=(x-1)*m+y;
	for(int i=h[u];i;i=w[i].next){
		int e=w[i].to;
		int dx=e/n+1,dy=e%n;
		if(dy==0)dy=m,dx--;
		if(flag!=0&&flag!=w[i].val)continue;
		if(flag==1&&sum!=0)continue;
		if(bb[dx][dy]==true)continue;
		if(w[i].val==2&&(flag==2||flag==0)&&bb[dx][dy]==false){
			int nx;
			if(u==e+1)nx=1;
			if(u==e-1)nx=3;
			if(u==e+m)nx=2;
			if(u==e-m)nx=4;
			if(fx==0){
				if(blog[dx][dy]==coll&&mmap[dx][dy]==true)continue;
				if(blog[dx][dy]!=coll&&mmap[dx][dy]==true&&lvv>=num[dx][dy]){
					ans++;continue;
				}
				fx=nx;
				bb[dx][dy]=true;
				nb[dx][dy]=true;
				dfs(dx,dy,w[i].val,fx,lvv,coll,sum+1);
				bb[dx][dy]=false;
				fx=0;
			}
			if(nx!=fx)continue;
		}
		if(blog[dx][dy]==coll&&mmap[dx][dy]==true)continue;
		if(blog[dx][dy]!=coll&&mmap[dx][dy]==true&&lvv>=num[dx][dy]){
			ans++;continue;
		}
		if(bb[dx][dy]==true)continue;
		if((w[i].val==flag||flag==0)&&blog[dx][dy]==false){
			bb[dx][dy]=true;
			nb[dx][dy]=true;
			dfs(dx,dy,w[i].val,fx,lvv,coll,sum+1);
			bb[dx][dy]=false;
		}
	}
}
signed main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--){
		memset(mmap,false,sizeof(mmap));
		memset(bb,false,sizeof(bb));
		memset(nb,false,sizeof(nb));
		memset(blog,false,sizeof(bb));
		memset(num,0,sizeof(nb));
		cnt=0;
		memset(h,0,sizeof(h));
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				char c;
				cin>>c;
				int a=(i-1)*m+j,b=a+1;
				if(c=='1')qxx(a,b,1),qxx(b,a,1);
				if(c=='2')qxx(a,b,2),qxx(b,a,2);
				if(c=='3')qxx(a,b,3),qxx(b,a,3);
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				char c;
				cin>>c;
				int a=(i-1)*m+j,b=a+m;
				if(c=='1')qxx(a,b,1),qxx(b,a,1);
				if(c=='2')qxx(a,b,2),qxx(b,a,2);
				if(c=='3')qxx(a,b,3),qxx(b,a,3);
			}
		}
		for(int i=1;i<=q;i++){
			memset(nb,false,sizeof(nb));
			memset(bb,false,sizeof(bb));			
			ans=0;
			int col,lv,x,y;
			col=read(),lv=read(),x=read(),y=read();
			blog[x][y]=col==0?false:true;
			num[x][y]=lv;
			mmap[x][y]=true;
			dfs(x,y,0,0,lv,col,0);
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(nb[j][k]==false||(j==x&&k==y))continue;
					ans++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
