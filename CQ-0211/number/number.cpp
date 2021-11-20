#include <bits/stdc++.h>
#define SIZE 1000000
using namespace std;
const int limit=1000000;
int t,x;
bool ok[SIZE];
queue<int> q;
queue<int> k;
int p,temp;
int st=1;
int ls[SIZE],id;
void init()
{
	for(int i=0;i<=9999;i++)
	{
		if(ok[i*10+7]) continue;
		while((i*10+7)*st<=limit)
		{
			q.push((i*10+7)*st);
			ok[(i*10+7)*st]=1;
			while(!q.empty())
			{
				p=q.front();q.pop();
				for(int i=0;i<=9;i++)
				{
					if(p*10+i*st<=limit)
					{
						ok[p*10+i*st]=1;
						q.push(p*10+i*st);
					}
				}
			}
			st++;
		}
		st=1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	init();
	while(t--)
	{
		cin>>x;
		if(ok[x]==1||x<=0)
		{
			cout<<-1<<endl;
			continue;
		}
		while(ok[++x]);
		cout<<x<<endl;
	}
	return 0;
}
