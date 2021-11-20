#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
bool bj[10000001];
int ans[1000001],unans[1000001];
int n;
int a[200001],maxx;
bool check(int x)
{
	while(x)
	{
		int y=x%10;
		if(y==7)return true;
		x=x/10;
	}
	return false;
}
void mt()
{
	for(int i=1;i<=maxx;i++)
	{
		if(bj[i]==1)
		{
			unans[++unans[0]]=i;
			continue;
		}
		if(check(i)==true)bj[i]=1;
		if(bj[i]==1)
		{
			unans[++unans[0]]=i;
			for(int j=2;i*j<=maxx;j++)bj[i*j]=1;
		}
		else ans[++ans[0]]=i;
	}
	int no=maxx;
	do
	{
		no++;
		if(check(no)==true)
		{
			bj[no]=1;
			continue;
		}
		for(int i=1;i<=unans[0];i++)
		{
			if(no%unans[i]==0)
			{
				bj[no]=1;
				break;
			}
		}
	}while(bj[no]==1);
	ans[++ans[0]]=no;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxx)maxx=a[i];
	}
	mt();
	for(int i=1;i<=n;i++)
	{
		int cnt=ans[0];
		if(bj[a[i]]==1)cout<<-1<<endl;
		else cout<<ans[lower_bound(ans+1,ans+cnt+1,a[i]+1)-ans]<<endl;
	}
	return 0;
}
