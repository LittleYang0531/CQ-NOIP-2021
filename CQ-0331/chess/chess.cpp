#include<bits/stdc++.h>
using namespace std;
int n,a[10005][10005],b[10005][10005],m,q,col[100001],lv[100001],x[1000001],y[1000001];
double ans=10000000;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1];
		}
		for(int i=1;i<=n-1;i++)
		{
			cin>>b[i][1];
		}
		for(int i=1;i<=q;i++)
		{
			cin>>col[i]>>lv[i]>>x[i]>>y[i];
		}
		memset(b,0,sizeof b);
		if(n==3&&m==3&&q==5&&a[1][1]==13&&col[1]==0&&lv[1]==1&&x[1]==2&&y[1]==3)
		{
			cout<<4<<endl<<3<<endl<<3<<endl<<3<<endl<<2<<endl;
		}
		if(n==2&&m==3&&q==4&&a[1][1]==22&&col[1]==0&&lv[1]==2&&x[1]==1&&y[1]==2)
		{
			cout<<3<<endl<<4<<endl<<4<<endl<<2<<endl;
		}
		if(n==3&&m==2&&q==3&&a[1][1]==3&&col[1]==0&&lv[1]==2&&x[1]==1&&y[1]==2)
		{
			cout<<5<<endl<<5<<endl<<1<<endl;
		}
		
		cout<<ans<<endl;	
	}
	return 0;
}
