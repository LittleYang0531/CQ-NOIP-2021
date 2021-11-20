#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;
	int f=1;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f*=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x*10)+(s-'0');
		s=getchar();
	}
	x*=f;
	return;
}
int n;
const int MAXN=1e5+5;
int a[MAXN];
vector<int>v;
struct node{
	vector<int>sta;
	int sum;
	int sum2;
	int date;
};
int get(node x)
{
	return n*x.sum2-x.sum*x.sum;
}
map<vector<int>,int>vis;
int limit=60000;
int tot;
int ans;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	int sum=0;
	int sum2=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
		sum2+=a[i]*a[i];
		v.push_back(a[i]);
	}
	
	queue<node>q;
	node now;
	now.sum=sum;
	now.sum2=sum2;
	now.date=get(now);
	now.sta=v;
	q.push(now);
	vis[v]=1;
	ans=now.date;
	while(q.size()){
		if(tot>limit)
		{
			break;
		}
		node temp=q.front();
		q.pop();
		
		ans=min(ans,temp.date);
		for(int i=1;i<n-1;i++)
		{
			node nex=temp;
			nex.sta[i]=nex.sta[i+1]+nex.sta[i-1]-nex.sta[i];
			nex.sum=temp.sum-temp.sta[i]+nex.sta[i];
			nex.sum2=temp.sum2-temp.sta[i]*temp.sta[i]+nex.sta[i]*nex.sta[i];
			nex.date=get(nex);
			if(vis[nex.sta])
			{
				continue;
			}
			
			vis[nex.sta]=1;
			tot++;
			q.push(nex);
		}
	}
	printf("%d",ans);
	return 0;
}
