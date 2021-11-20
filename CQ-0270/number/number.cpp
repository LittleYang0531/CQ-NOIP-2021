#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int T,mark[N+5],mx;
struct List
{
	int pre[N+5],nxt[N+5],siz;
	void erase(int x)
	{
		--siz;pre[nxt[x]]=pre[x];nxt[pre[x]]=nxt[x];
	}
	void push_front(int x)
	{
		++siz;nxt[x]=nxt[0];pre[x]=0;pre[nxt[0]]=x;nxt[0]=x;
	}
	int front() {return nxt[0];}
} l1,l2;
int check(int x)
{
	while(x) if(x%10==7) return 1;else x/=10;
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=N; i>=1; i--) l1.push_front(i);
	for(int i=1; i<=N; i++)
		if(check(i)&&!mark[i])
		{
			for(int j=l1.nxt[0]; j; j=l1.nxt[j])
				if(j>N/i) break;
				else
				{
					if(!mark[i*j]) l2.push_front(i*j);mark[i*j]++;
				}
			while(l2.siz) l1.erase(l2.front()),l2.erase(l2.front());
		}
	scanf("%d",&T);
	while(T--)
	{
		int x;scanf("%d",&x);
		if(mark[x]) puts("-1");
		else printf("%d\n",l1.nxt[x]);
	}
	return 0;
}
/*
4
6
33
69
300
*/
