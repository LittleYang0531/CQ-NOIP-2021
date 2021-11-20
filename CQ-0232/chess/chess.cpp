#include<bits/stdc++.h>
using namespace std;
int t,n,m,q;
int head[200005],to[800005],nex[800005],cnt,ans;
int tp[800005],vis[200005][2];
string s;
struct node
{
	int col,lv;
}zi[200005];
void add(int x,int y,int z)
{
	nex[++cnt]=head[x];
	to[cnt]=y;
	tp[cnt]=z;
	head[x]=cnt;
}
void go(int id,int num)
{
	for(int i=head[id];i;i=nex[i])
	{
		int x=to[i];
		if(tp[i]==0) continue;
		if(tp[i]==1)
		{
			if(vis[x][0]==0) ans++;
			else if(vis[x][1]!=zi[num].col&&zi[num].lv>=vis[x][0]) ans++;
		}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&q);
		memset(head,0,sizeof(head));
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<m-1;j++)
			{
				int num=s[j]-'0';
				add((i-1)*m+j+1,(i-1)*m+j+2,num);
				add((i-1)*m+j+2,(i-1)*m+j+1,num);
			//	cout<<"a"<<(i-1)*m+j+1<<" "<<(i-1)*m+j+2<<"\n";
			}
		}
		for(int i=1;i<n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
			{
				int num=s[j]-'0';
				add((i-1)*m+j+1,i*m+j+1,num);
				add(i*m+j+1,(i-1)*m+j+1,num);
			//	cout<<"b"<<(i-1)*m+j+1<<" "<<i*m+j+1<<"\n";
			}
		}
	//	cout<<1;
		for(int i=1;i<=q;i++)
		{
			int x,y,c,l;
			scanf("%d %d %d %d",&c,&l,&x,&y);
			zi[i].col=c;
			zi[i].lv=l;
			ans=0;
			go((x-1)*m+y,i);
			printf("%d\n",ans);
			vis[(x-1)*m+y][0]=l;
			vis[(x-1)*m+y][1]=c;
		}	
	}
	return 0;
}
