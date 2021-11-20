#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int t,flag;
int a[maxn],s[10];
int vis[maxn];
void dj(int x)
{
	int cnt=1;
	while(cnt*x<=200000)
	{
		vis[cnt*x]=1;
		cnt++;
	}
}
void zh(int x)
{
	flag=1;
	while(x>=10)
	{
		s[flag]=x%10;
		x/=10;
		flag++;
	}
	s[flag]=x;
}
void cl()
{
	dj(7);
	for(int i=1;i<=200000;i++)
	{
		if(vis[i]==1) continue;
		zh(i);
		for(int j=flag;j>=1;j--)
		{
			if(s[j]==7)
			{
				dj(i);
				break;
			 }
			
		}
	}
}
int find(int x)
{
	while(1)
	{
		x++;
		if(vis[x]==0) break;
	}
	return x;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a[i];		
	 }	
	 cl();
	// for(int i=1;i<=a[t];i++) cout<<vis[i];
	 for(int i=1;i<=t;i++)
	{
		if(vis[a[i]]==1) cout<<-1<<endl;
		else cout<<find(a[i])<<endl;
	}
	return 0;
}
