#include<bits/stdc++.h>
using namespace std;
int n,m,K,l2n;
long long a[101],ans;
__int128 S,p2[120];
const long long MOD=998244353;
set<vector<int> >s,s2;
__int128 p(__int128 A,int x)
{
	if (!x)return 1;
	if (x==1)return A;
	if (x==2)return A*A;
	__int128 t=p(A,x>>1);
	if (x&1)return t*t*A;
	return t*t;
}
int C(int x,int y)
{
	if (x==1)return y;
	if (!x)return 1;
	if (x==y)return 1;
	if (x>y)return 0;
	return (C(x-1,y-1)*y/x)%MOD;
}
void dfs(vector<int>v,int sz)
{
	if (sz==n)
	{
		sort(v.begin(),v.end());
		if (s.find(v)!=s.end())return;
		s.insert(v);
		int cnt[m];
		long long tmp=1;
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<sz;i++)
		{
			if (v[i]>m)return;
			cnt[v[i]]++;
			tmp*=a[v[i]];
			tmp%=MOD;
		}
		for (int i=0;i<=m;i++)
			if (cnt[i])
			{
				tmp*=C(cnt[i],sz);
				sz-=cnt[i];
				tmp%=MOD;
			}
		ans+=tmp;
		if (ans>=MOD)ans-=MOD;
		return;
	}
	bool apr[120];
	memset(apr,0,sizeof(apr));
	for (int i=0;i<sz;i++)
		if (v[i]&&!apr[v[i]])
		{
			apr[v[i]]=1;
			v[i]--;
			v.push_back(v[i]);
			dfs(v,sz+1);
			v.pop_back();
			v[i]++;
		}
}
void search(__int128 x,int dep)
{
	if (dep<K)
		for (int i=0;i<120&&x+p2[i]<=S;i++)
			if (!(x&p2[i]))
				search(x|p2[i],dep+1);
	vector<int>v;
	int cnt[120];
	long long tmp=1;
	bool hf=1;
	memset(cnt,0,sizeof(cnt));
	for (int i=0;i<120&&p2[i]<=x;i++)
		if (x&p2[i])
		{
			if (i>m)hf=0;
			v.push_back(i);
			if (hf)
			{
				cnt[i]++;
				tmp*=a[i];
				tmp%=MOD;
			}
		}
	if (dep<n&&x>=n)
	{
		if (s2.find(v)!=s2.end())return;
		s2.insert(v);
		bool apr[120];
		memset(apr,0,sizeof(apr));
		for (int i=0;i<dep;i++)
			if (v[i]&&!apr[v[i]])
			{
				apr[v[i]]=1;
				v[i]--;
				v.push_back(v[i]);
				dfs(v,dep+1);
				v.pop_back();
				v[i]++;
			}
	}
	if (!hf||dep!=n)return;
	for (int i=0;i<m;i++)
		if (cnt[i])
		{
			tmp*=C(cnt[i],dep);
			dep-=cnt[i];
			tmp%=MOD;
		}
	ans+=tmp;
	if (ans>=MOD)ans-=MOD;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>K;
	for (int i=0;i<=m;i++)cin>>a[i];
	S=(__int128)n*p(2,m);
	p2[0]=1;
	for (int i=1;i<120;i++)p2[i]=p2[i-1]<<1;
	search(0,0);
	cout<<ans;
}
