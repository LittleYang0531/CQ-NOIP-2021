#include<bits/stdc++.h>
using namespace std;
int n,ans=2000000000;
set<vector<int> >s;
vector<int>v;
double ave=0;
void dfs(vector<int>v,double aver)
{
	double tot=0;
	for (int i=0;i<n;i++)tot+=pow((double)v[i]-aver,2);
	if (tot*(double)n>ans)return;
	ans=tot*(double)n;
	for (int i=1;i<n-1;i++)
		if (v[i]!=v[i-1]+v[i+1]-v[i])
		{
			v[i]=v[i-1]+v[i+1]-v[i];
			if (s.find(v)!=s.end())
			{
				v[i]=v[i-1]+v[i+1]-v[i];
				continue;
			}
			s.insert(v);
			dfs(v,aver+(double)((v[i]<<1)-v[i-1]-v[i+1])/(double)n);
		}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		v.push_back(t);
		ave+=t;
	}
	ave/=(double)n;
	s.insert(v);
	dfs(v,ave);
	cout<<ans;
}
