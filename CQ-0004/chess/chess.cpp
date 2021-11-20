#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
int gnum()
{
	char c;
	while((c=getchar())>'9'||c<'0');
	return c-'0';
}
int n,m,q;
int id(int x,int y){return (x-1)*m+y;}
int R[200005],D[200005],L[200005],U[200005];
int vs[200005],col[200005],lev[200005],dx[]={-1,1,0,0},dy[]={0,0,-1,1};//上下左右 
bool check(int x,int y)
{
	if(x<=0||y<=0||x>n||y>m)return false;
	return true;
}
int get(int a,int b,int op)
{
	if(op==0)return U[id(a,b)];
	if(op==1)return D[id(a,b)];
	if(op==2)return L[id(a,b)];
	return R[id(a,b)];
}
bool win(int a,int b,int c,int d)
{
	if(!vs[id(c,d)])return 1;
	if(col[id(c,d)]==col[id(a,b)])return 0;
	if(lev[id(c,d)]>lev[id(a,b)])return 0;
	return 1;
}
struct pr{int x,y;pr(){}pr(int a,int b):x(a),y(b){}};
int rc[200005];
int bfs(int a,int b)
{
//	cout<<a<<" "<<b<<"\n";
	memset(rc,0,sizeof(rc[0])*(n*m+1));
	rc[id(a,b)]=1;
	queue<pr>q;
	int ans=0;
	for(int i=0;i<4;i++)
	{
//		cout<<get(a,b,i)<<" "<<a+dx[i]<<" "<<b+dy[i]<<"\n";
		if(check(a+dx[i],b+dy[i])&&get(a,b,i)==3)//现在只走3 
		{
			if(win(a,b,a+dx[i],b+dy[i]))
			{
				ans++;
				rc[id(a+dx[i],b+dy[i])]=1;
				if(!vs[id(a+dx[i],b+dy[i])])
					q.push(pr(a+dx[i],b+dy[i]));
			}
		}
	}
	
	while(!q.empty())//下面只走3 
	{
		pr w=q.front();
//		cout<<w.x<<" "<<w.y<<"\n";
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=w.x+dx[i],ty=w.y+dy[i];
			if(!check(tx,ty))continue;
			if(get(w.x,w.y,i)!=3)continue;
			if(!rc[id(tx,ty)]&&win(a,b,tx,ty))
			{
				rc[id(tx,ty)]=1;
				ans++;
				if(!vs[id(tx,ty)])
					q.push((pr){tx,ty});
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		if(check(a+dx[i],b+dy[i])&&get(a,b,i)==1)//现在只走1 
		{
			if(win(a,b,a+dx[i],b+dy[i]))
			{
				ans+=(rc[id(a+dx[i],b+dy[i])]==0);
				rc[id(a+dx[i],b+dy[i])]=1;
			}
		}
	}
	for(int i=0;i<4;i++)//现在只走2 
	{
		int tx=a,ty=b;
		while(get(tx,ty,i)==2&&check(tx+dx[i],ty+dy[i]))
		{
			tx+=dx[i],ty+=dy[i];
			if(!win(a,b,tx,ty))break;
			ans+=(rc[id(tx,ty)]==0);
			rc[id(tx,ty)]=1;
			if(vs[id(tx,ty)])break;
		}
	}
	return ans;
}
int bfs1(int a,int b)
{
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(check(a+dx[i],b+dy[i])&&get(a,b,i)==1)//现在只走1 
		{
			if(win(a,b,a+dx[i],b+dy[i]))
				ans++;
		}
	}
	return ans;
}
int yh(int a,int b)
{
	vector<int>Rc;
	memset(rc,0,sizeof(rc[0])*(n*m+1));
	rc[id(a,b)]=1;
	Rc.push_back(id(a,b));
	queue<pr>q;
	int ans=0;
	for(int i=0;i<4;i++)
	{
		if(check(a+dx[i],b+dy[i])&&get(a,b,i)==3)//现在只走3 
		{
			if(win(a,b,a+dx[i],b+dy[i]))
			{
				ans++;
				Rc.push_back(id(a+dx[i],b+dy[i]));
				rc[id(a+dx[i],b+dy[i])]=1;
				if(!vs[id(a+dx[i],b+dy[i])])
					q.push(pr(a+dx[i],b+dy[i]));
			}
		}
	}
	
	while(!q.empty())//下面只走3 
	{
		pr w=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int tx=w.x+dx[i],ty=w.y+dy[i];
			if(!check(tx,ty))continue;
			if(get(w.x,w.y,i)!=3)continue;
			if(!rc[id(tx,ty)]&&win(a,b,tx,ty))
			{
				rc[id(tx,ty)]=1;
				Rc.push_back(id(tx,ty));
				ans++;
				if(!vs[id(tx,ty)])
					q.push((pr){tx,ty});
			}
		}
	}
	
	for(int i=0;i<4;i++)
	{
		if(check(a+dx[i],b+dy[i])&&get(a,b,i)==1)//现在只走1 
		{
			if(win(a,b,a+dx[i],b+dy[i]))
			{
				ans+=(rc[id(a+dx[i],b+dy[i])]==0);
				rc[id(a+dx[i],b+dy[i])]=1;
				Rc.push_back(id(a+dx[i],b+dy[i]));
			}
		}
	}
	for(int i=0;i<4;i++)//现在只走2 
	{
		int tx=a,ty=b;
		while(get(tx,ty,i)==2&&check(tx+dx[i],ty+dy[i]))
		{
			tx+=dx[i],ty+=dy[i];
			if(!win(a,b,tx,ty))break;
			ans+=(rc[id(tx,ty)]==0);
			rc[id(tx,ty)]=1;
			Rc.push_back(id(tx,ty));
			if(vs[id(tx,ty)])break;
		}
	}
	for(auto it:Rc)rc[it]=0;
	return ans;
}
set<int>h[200005];
set<int>l[200005];
int size[200005][4];
int main(){
	srand(time(0));
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(vs,0,sizeof(vs));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		memset(U,0,sizeof(U));
		memset(D,0,sizeof(D));
		n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++)
				R[id(i,j)]=L[id(i,j+1)]=gnum();
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++)
				D[id(i,j)]=U[id(i+1,j)]=gnum();
//			cerr<<n<<" "<<m<<" "<<q<<"\n";
		if(n*m<=10000&&q<=2000)
		{
			while(q--)
			{
				int O=read(),P=read();
				int a=read(),b=read();
				col[id(a,b)]=O,lev[id(a,b)]=P;
				vs[id(a,b)]=1;
				cout<<bfs(a,b)<<'\n';
			}
			continue;
		}
		int vs2=0,vs3=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<m;j++)
			{
				if(R[id(i,j)]==2)vs2=1;
				if(R[id(i,j)]==3)vs3=1;
			}
		for(int i=1;i<n;i++)
			for(int j=1;j<=m;j++)
			{
				if(D[id(i,j)]==2)vs2=1;
				if(D[id(i,j)]==3)vs3=1;
			}
		if(!vs2&&!vs3)
		{
			while(q--)
			{
				int O=read(),P=read();
				int a=read(),b=read();
				col[id(a,b)]=O,lev[id(a,b)]=P;
				vs[id(a,b)]=1;
				cout<<bfs1(a,b)<<'\n';
			}
			continue;
		}
		if(!vs3)
		{
			for(int i=1;i<=m;i++)
				l[i].clear();
			for(int i=1;i<=n;i++)
				h[i].clear();
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)//处理0/2 
				{
					size[id(i,j)][0]=size[id(i,j)][2]=1;
					if(L[id(i,j)]==2)size[id(i,j)][2]+=size[id(i,j-1)][2];
					if(U[id(i,j)]==2)size[id(i,j)][0]+=size[id(i-1,j)][0];
				}
			}
			for(int i=n;i>=1;i--)
			{
				for(int j=m;j>=1;j--)//处理1/3 
				{
					size[id(i,j)][1]=size[id(i,j)][3]=1;
					if(R[id(i,j)]==2)size[id(i,j)][3]+=size[id(i,j+1)][3];
					if(D[id(i,j)]==2)size[id(i,j)][1]+=size[id(i+1,j)][1];
				}
			}
			while(q--)
			{
				int O=read(),P=read();
				int a=read(),b=read();
				h[a].insert(b);
				l[b].insert(a);
				col[id(a,b)]=O,lev[id(a,b)]=P;
				vs[id(a,b)]=1;
				ll re=bfs1(a,b);
				set<int>::iterator now=h[a].find(b);
				if(now!=h[a].begin())//向左有阻碍 
				{
					int L=*--now;
					++now;
					re+=min(size[id(a,b)][2]-1,b-L-1);
					if(L>=b-size[id(a,b)][2]+1&&win(a,b,a,L))re++;
				}
				else re+=size[id(a,b)][2]-1;
				if(now!=--h[a].end())//向右有阻碍 
				{
					int R=*++now;
					--now;
					re+=min(size[id(a,b)][3]-1,R-b-1);
					if(R<=b+size[id(a,b)][3]-1&&win(a,b,a,R))re++;
				}
				else re+=size[id(a,b)][3]-1;
//				cout<<re<<" "<<size[id(a,b)][3]<<'\n';
				now=l[b].find(a);
				if(now!=l[b].begin())//向上右阻碍 
				{
					int U=*--now;
					++now;
					re+=min(size[id(a,b)][0]-1,a-U-1);
					if(U>=a-size[id(a,b)][0]+1&&win(a,b,U,b))re++;
				}
				else re+=size[id(a,b)][0]-1;
				if(now!=--l[b].end())//向下右阻碍 
				{
					int D=*++now;
					--now;
					re+=min(size[id(a,b)][1]-1,D-a-1);
					if(D<=a+size[id(a,b)][1]-1&&win(a,b,D,b))re++;
				}
				else re+=size[id(a,b)][1]-1;
				cout<<re<<'\n';
			}
			continue;
		}
		
		
		while(q--)
		{
			int O=read(),P=read();
			int a=read(),b=read();
			col[id(a,b)]=O,lev[id(a,b)]=P;
			vs[id(a,b)]=1;
			cout<<yh(a,b)<<'\n';
		}
		continue;
	}
	pc('1',1);
	return 0;
}
/*
1
9999998
*/
/*IronHeart@413A*/
