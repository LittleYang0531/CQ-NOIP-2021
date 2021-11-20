#include<bits/stdc++.h>
using namespace std;

int N;
int K;
int cnt;
int a[10004];
int b[10004];
int vis[100005];
int ans[100005];
queue<int > q;
queue<int > q1;
//a[i]+...a[N]=k;

void doit()
{
	while(!q.empty())
	{
		K=q.front();
		q.pop();
		memset(b,0,sizeof b);
		for(int i=N;i>=1;i--)
		{
			b[i]=K%10;
			K/=10;
		}
		for(int i=2;i<=N-1;i++)
		{
			K=0;
			int x=b[i+1]+b[i-1]-b[i];
			if(x==b[i])
			{
				continue;
			}
			for(int j=1;j<=N;j++)
			{
				if(i==j)
				{
					K=K*10+x;
				}
				else
				{
					K=K*10+b[j];
				}
			}
			if(!vis[K])
			{
				vis[K]=1;
				q.push(K);
				q1.push(K);
			}
		}
	}
	while(!q1.empty())
	{	
		cnt++;
		int sum=0;
		K=q1.front();
		q1.pop();
		memset(b,0,sizeof b);
		for(int i=N;i>=1;i--)
		{
			b[i]=K%10;
			K/=10;
			sum+=b[i];
		}
		for(int i=1;i<=N;i++)
		{
			ans[cnt]+=(sum-N*b[i])*(sum-N*b[i]);
		}
		ans[cnt]/=N;
	}
}

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>a[i];
		K=K*10+a[i];
	}
	q.push(K);
	q1.push(K);
	vis[K]=1;
	doit();
	int num=1e8;
	for(int i=1;i<=cnt;i++)
	{
		num=min(num,ans[i]);
	}
	cout<<num<<endl;
	return 0;
}
