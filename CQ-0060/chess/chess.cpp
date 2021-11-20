#include <cstdio>
const int M = 200005;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<=9)
	{
		putchar(x+'0');
		return ;
	}
	write(x/10);
	putchar(x%10+'0');
}
int T,n,m,q,a[M],b[M],c[M],d[M],vis[M];
int col,lv,k,t,ans,clr[M],qx[M],qy[M];char s[M];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int id(int x,int y) {return m*(x-1)+y;}
int in(int x,int y)
{
	if(c[id(x,y)]!=-1)
	{
		if(c[id(x,y)]==col) return 0;
		if(d[id(x,y)]>lv) return 0;
	}
	return x>=1 && x<=n && y>=1 && y<=m;
}
int type(int xa,int ya,int xb,int yb)
{
	if(xa!=xb)
	{
		if(xa<xb) return b[id(xa,ya)];
		return b[id(xb,yb)];
	}
	if(ya<yb) return a[id(xa,ya)];
	return a[id(xb,yb)];
}
void reach(int x,int y)
{
	if(vis[id(x,y)]) return ;
	vis[id(x,y)]=1;clr[++k]=id(x,y);ans++;
}
void reach2(int x,int y)
{
	if(vis[id(x,y)]==2) return ;
	if(!vis[id(x,y)]) clr[++k]=id(x,y),ans++;
	vis[id(x,y)]=2;
}
void clear()
{
	while(k) vis[clr[k--]]=0;
}
void bfs()
{
	ans=0;col=read();lv=read();
	int x=read(),y=read();
	for(int i=0;i<4;i++)
	{
		int tx=x+dx[i],ty=y+dy[i],lx=x,ly=y;
		if(in(tx,ty) && type(tx,ty,x,y)==1)
			reach(tx,ty);
		while(in(tx,ty) && type(tx,ty,lx,ly)==2)
		{
			reach(tx,ty);
			if(c[id(tx,ty)]!=-1) break;//stop
			lx=tx;ly=ty;
			tx=tx+dx[i];ty=ty+dy[i];
		}
	}
	reach2(x,y);qx[++t]=x;qy[t]=y;
	while(t)
	{
		int nx=qx[t],ny=qy[t];t--;
		for(int i=0;i<4;i++)
		{
			int tx=nx+dx[i],ty=ny+dy[i];
			if(in(tx,ty) && type(tx,ty,nx,ny)==3)
			{
				if(vis[id(tx,ty)]!=2
				&& c[id(tx,ty)]==-1)
					qx[++t]=tx,qy[t]=ty;
				reach2(tx,ty);
			}
		}
	}
	clear();c[id(x,y)]=col;d[id(x,y)]=lv;
	write(ans-1),puts("");
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();m=read();q=read();
		for(int i=1;i<=n*m;i++) c[i]=-1;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<m;j++)
				a[id(i,j)]=s[j]-'0';
		}
		for(int i=1;i<n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				b[id(i,j)]=s[j]-'0';
		}
		for(int i=1;i<=q;i++) bfs();
	}
	return 0;
}
