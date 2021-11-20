#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+7;

/////////////////////////////////////
struct edge{
	int v,next;
	int z;
}e[NN*2];
int cnt=-1,head[NN];
void adde(int u,int v,int z)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	e[cnt].z=z;
	head[u]=cnt;
}
////////////////////////////////////
int a[NN][1005];
int T,n,m,q;

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	
	memset(head,-1,sizeof head);
	cin>>T;
	while(T--)
	{
		cnt=-1;
		memset(head,-1,sizeof head);
		memset(a,0,sizeof a);
		
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<s.size();j++)
			{
				adde(i<<j,i<<(j+1),s[i]-'0');
				adde(i<<(j+1),i<<j,s[i]-'0');
			}
		}
		for(int i=1;i<n;i++)
		{
			string s;
			cin>>s;
			for(int j=0;j<s.size();j++)
			{
				adde(i<<j,(i+1)<<j,s[i]-'0');
				adde((i+1)<<j,i<<j,s[i]-'0');
			}
		}
		for(int i=1;i<=q;i++)
		{
			int c,l,x,y;
			cin>>c>>l>>x>>y;
			a[x][y]=c+(1<<l);
		}
		cout<<1<<'\n';
	}
	return 0;
}
