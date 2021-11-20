#include<bits/stdc++.h>
using namespace std;
int t,n,m,q1;
struct edge
{
	int next,to,x,y;
	int p;
}e[1000005];
int h[1000005],cnt;
int get_pos(int x,int y)
{
	return ((x-1)*m)+y;
}
void addedge(int x,int y,int z)
{
	e[++cnt].next=h[x];
	e[cnt].p=z;
	e[cnt].to=y;
	h[x]=cnt;
}
struct abc
{
	int col,lv;
	bool flag=0;
}a[1000005],v[1000005];
bool vis[1000005];
struct ab
{
	int pos,p,last;
}q[1000005];
int l=1,r=0;
int ans=0;
void bfs(int col,int lv)
{
	while(l<=r)
	{
//		cout<<"q:";
//		for(int i=l;i<=r;i++)
//		{
//			printf("%d ",q[i].pos);
//		}
//		printf("\n");
//		cout<<l<<" "<<r<<endl;
		if(q[l].p==1)
		{
			l++;
			continue;
		}
		for(int i=h[q[l].pos];i;i=e[i].next)
		{
			int y=e[i].to;
			if(e[i].p!=q[l].p && q[l].p!=-1)continue;
			if(vis[y])continue;
			if(e[i].p==0)continue;
			bool flag1=0;
//				cout<<v[6].lv;
			if(v[y].flag==1)
			{
//				cout<<1;
				if(v[y].col!=col && v[y].lv<=lv)
				{
					q[r].p=0;
					ans++;
				}
			}
			if(e[i].p==2)
			{
				if(q[l].p==2)
				{
//					cout<<q[l].last<<endl;
					if((abs(y-q[l].last)!=2 || (y+2)/m!=(q[l].last+2)/m) && abs(y-q[l].last)!=2*m)continue;
				}
				flag1=1;
				q[++r].last=q[l].pos;
				q[r].p=2;
				ans++;
			}
			if(flag1==0)r++;
			vis[y]=1;
			q[r].pos=y;
			if(e[i].p==1)
			{
				q[r].p=1;
				ans++;
			}
			else if(e[i].p==3)
			{
				q[r].p=3;
				ans++;
			}
		}
		l++;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&q1);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			char x;
			for(int j=1;j<m;j++)
			{
				cin>>x;
				int xx=x-'0';
				cnt++;
				addedge(cnt,cnt+1,xx);
				addedge(cnt+1,cnt,xx);
			}
			cnt++;
		}
		cnt=0;
		for(int i=1;i<n;i++)
		{
			char x;
			for(int j=1;j<=m;j++)
			{
				cin>>x;
//				cout<<j<<endl;
				int xx=x-'0';
				cnt++;
				addedge(cnt,cnt+m,xx);
				addedge(cnt+m,cnt,xx);
			}
//			cout<<i;
		}
//		cout<<1<<endl;
		while(q1--)
		{
//			cout<<q1<<endl;
//			cout<<1;
//			continue;
			int col,lv,x,y;
			memset(vis,0,sizeof(vis));
//			memset(v,0,sizeof(v));
			memset(a,0,sizeof(a));
			ans=0;
//			cout<<1;
			scanf("%d %d %d %d",&col,&lv,&x,&y);
			l=1,r=0;
			int pos=get_pos(x,y);
			vis[pos]=1;
			q[++r].pos=pos;
			q[r].p=-1;
			v[pos].col=col;
			v[pos].lv=lv;
			v[pos].flag=1;
			bfs(col,lv);
			printf("%d\n",ans);
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
