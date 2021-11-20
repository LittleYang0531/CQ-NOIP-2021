#include<bits/stdc++.h>
using namespace std;
int T,n,m,q;
string a1[200005],a2[200005];
struct node
{
	int col,lv,x,y;
}a[1000005];
map<int,int>mp[200005];
string b[200005];
struct nood
{
	int x,y,lim1,lim2;
};
int dx[5]={0,0,0,-1,1};
int dy[5]={0,1,-1,0,0};
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)cin>>a1[i];
		for(int i=1;i<n;i++)cin>>a2[i];
		
		for(int i=1;i<=q;i++)
		{
			cin>>a[i].col>>a[i].lv>>a[i].x>>a[i].y;
			cout<<bfs(a[i].x)<<'\n';
			mp[a[i].x][a[i].y=i;
		}
	}
}
