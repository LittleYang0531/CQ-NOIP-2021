#include<bits/stdc++.h>
#define min(x,y) (x<y?x:y)
using namespace std;
int n,fc,sum=0,ans=0,ttt;
vector<int> a;
map<vector<int> , bool> used;
int sq(int k)
{
	return k*k;
}
void dfs()
{
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
//	if(used.find(a)==used.end())
	{
		fc=sum=0;
		for(int i=0;i<n;sum+=a[i],++i);
		for(int i=0;i<n;++i)
			fc+=sq((n*a[i])-sum);
		ans=min(ans,fc/n);
	}
	for(int i=1;i<n-1;++i)
	{
		if(a[i]!=(a[i-1]+a[i+1]-a[i]))
		{
			int tmp=a[i];
			a[i]=(a[i-1]+a[i+1]-a[i]);
			if(used.find(a)==used.end())
			{
				used[a]=1;
				dfs();
			}
			a[i]=tmp;
		}
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&ttt),a.push_back(ttt);
	for(int i=0;i<n;sum+=a[i],++i);
	for(int i=0;i<n;++i)
		ans+=sq((n*a[i])-sum);
	dfs();
	printf("%d",ans);
	return 0;
}

