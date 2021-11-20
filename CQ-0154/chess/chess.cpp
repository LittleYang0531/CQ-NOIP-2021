#include<bits/stdc++.h>
#define inl inline
typedef long long ll;
using namespace std;
const int maxn=2e5+5;
struct node
{
	int next,to,flag;
}edge[maxn*4];
int T,n,m,Q,cnt,clt,lvt,ans,h[maxn],cl[maxn],lv[maxn];
bool vst[5005];
inl int Read()
{
	int s=0,f=1; char c;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
inl int Readc()
{
	for(char c=getchar();;c=getchar())
		if(isdigit(c)) return c-'0';
}
inl void Write(int x)
{
	short cnt=0,s[40];
	if(x<0) putchar('-'), x=-x;
	do s[++cnt]=x%10; while((x/=10));
	while(cnt--) putchar(s[cnt+1]+'0');
}
inl int Pos(int x,int y)
{
	return (x-1)*m+y;
}
inl void Ask(int p,int &x,int &y)
{
	y=p%m?p%m:m; x=(p-y)/m+1;
}
inl void Add(int x,int y,int flag)
{
	if(!flag) return;
	edge[++cnt]=(node){h[x],y,flag}; h[x]=cnt;
	edge[++cnt]=(node){h[y],x,flag}; h[y]=cnt;
}
void DFS(int p)
{
	if(vst[p]) return; vst[p]=true;
	if(cl[p]) {ans+=(cl[p]==clt?0:(lv[p]>lvt?0:1)); return; }
	++ans;
	for(int i=h[p];i;i=edge[i].next)
		if(edge[i].flag==3) DFS(edge[i].to);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(T=Read();T;--T)
	{
		n=Read(); m=Read(); Q=Read();
		memset(h,0,sizeof(h)); cnt=1;
		memset(cl,0,sizeof(cl));
		memset(lv,0,sizeof(lv));
		for(int i=1;i<=n;++i)
			for(int j=1;j<m;++j) Add(Pos(i,j),Pos(i,j+1),Readc());
		for(int i=1;i<n;++i)
			for(int j=1;j<=m;++j) Add(Pos(i,j),Pos(i+1,j),Readc());
		while(Q--)
		{
			clt=Read()+1; lvt=Read(); int x=Read(),y=Read(),xx,yy,p;
			p=Pos(x,y); cl[p]=clt; lv[p]=lvt; ans=0;
			if(n*m<=5000) memset(vst,false,sizeof(vst)), vst[p]=true;
			for(int i=h[p];i;i=edge[i].next)
			{
				int to=edge[i].to; Ask(to,xx,yy);
				if(edge[i].flag==1)
				{
					if(n*m<=5000)
					if(!vst[to]) ans+=(cl[to]?(cl[to]==clt?0:(lv[to]>lvt?0:1)):1), vst[to]=true;
				}
				else if(edge[i].flag==2)
				{
					Ask(to,xx,yy); bool flag=true; int la=i;
					while(flag)
					{
						if(n*m>5000)
						{
							if(cl[to]) ans+=(cl[to]==clt?0:(lv[to]>lvt?0:1));
							else ++ans;
						}
						else if(!vst[to])
						{
							if(cl[to]) ans+=(cl[to]==clt?0:(lv[to]>lvt?0:1));
							else ++ans; vst[to]=true;
						}
						if(cl[to]) break; flag=false;
						for(int j=h[to];j;j=edge[j].next)
							if(j!=(la^1)&&edge[j].flag==2)
							{
								to=edge[j].to; Ask(to,xx,yy);
								if(xx==x||yy==y) {la=j; flag=true; break; }
							}
					}
				}
				else DFS(to);
			}
			Write(ans); putchar('\n');
		}
	}
	return 0;
}
