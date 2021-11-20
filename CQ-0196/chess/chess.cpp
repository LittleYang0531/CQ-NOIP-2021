#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=N<<2;
struct ok{
	int x,y;
};
int n,m,q,now1,now2;
int first[N],to[M],nxt[M],lth[M],cnt;
int col[N],lv[N];
char a;
bool biao[N];
queue<int>Q;
inline int id(int x,int y) {return (x-1)*max(n,m)+y;}
inline void inc(int x,int y,int l) {nxt[++cnt]=first[x],to[cnt]=y,first[x]=cnt,lth[cnt]=l;}
void bfs(int x,int &res)
{
	if(biao[x]) return;
	Q.push(x);
	biao[x]=true;
	res++;
	while(!Q.empty())
	{
		int k=Q.front();
		Q.pop();
		for(int i=first[k],v;i;i=nxt[i]) if(lth[i]>1&&!biao[v=to[i]])
		{
			if(lv[v])
			{
				if(now2^col[v]&&now1>=lv[v]) biao[v]=true,res++;
				continue;
			}
			Q.push(v);
			biao[v]=true;
			res++;
		}
	}
}
int solve(int x,int y)
{
	int k=id(x,y),res=0;
	memset(biao,false,sizeof(biao));
	biao[k]=true;
	for(int i=first[k],v;i;i=nxt[i]) if(lth[i]>1)
	{
		if(lv[v=to[i]]) {if(lv[v]<=lv[k]&&col[v]^col[k]) res+=!biao[v];}
		else bfs(v,res);
		biao[v]=true;
	}
	for(int i=first[k],v;i;i=nxt[i]) if(lth[i])
	{
		if(lv[v=to[i]]) {if(lv[v]<=lv[k]&&col[v]^col[k]) res+=!biao[v];}
		else res+=!biao[v];
		biao[v]=true;
	}
	return res;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	memset(col,0,sizeof(col));
	memset(lv,0,sizeof(lv));
	getchar();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%c",&a);
			int k=a-'0';
			inc(id(i,j),id(i,j+1),k);
			inc(id(i,j+1),id(i,j),k);
		}
		getchar();
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&a);
			int k=a-'0';
			inc(id(i,j),id(i+1,j),k);
			inc(id(i+1,j),id(i,j),k);
		}
		getchar();
	}
	while(q--)
	{
		int A,B,x,y;
		scanf("%d%d%d%d",&A,&B,&x,&y);
		col[id(x,y)]=A,lv[id(x,y)]=B;
		now1=A,now2=B;
		printf("%d\n",solve(x,y));
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
