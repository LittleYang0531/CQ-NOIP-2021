#include<bits/stdc++.h>
#define isdigit(x) ('0'<=x && x<='9')
#define id(x,y) ((x-1)*m+y)
#define U 0
#define D 1
#define L 2
#define R 3
using namespace std;
inline int read()
{
	int w=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while isdigit(ch)
	{
		w=(w<<1)+(w<<3)+ch-'0';
		ch=getchar(); 
	}
	return w;
}
void out(int x)
{
	if(x) out(x/10),putchar(x%10 + '0');
	return ;
}
struct node
{
	int opt[4],nxt[4];
}poi[400005];
int T,n,m,q,lv[400005],c,l,topt,inx,iny,now,ans,from;
bitset<400005> col,have,vis,kv;
inline void case1(int k)
{
	for(int i=0;i<4;++i)
	{
		if(!poi[k].nxt[i]) continue;//没有路 
		if(poi[k].opt[i]!=1) continue;//opt不是1 
		if(have[poi[k].nxt[i]] && (!(col[poi[k].nxt[i]]^col[k]) || lv[poi[k].nxt[i]]>lv[k])) continue;//有子不能吃 
		++ans;
		kv[poi[k].nxt[i]]=0;
	}
}
inline void case2(int k)
{
	for(int i=0;i<4;++i)
	{
		k=now;
		while(1)
		{
			if(poi[k].opt[i]!=2) break;//opt不是2 
			k=poi[k].nxt[i];
			if(have[k])//有子
			{
				if((col[now]^col[k]) && lv[now]>=lv[k]) ++ans,kv[k]=0;//可以吃 
				break;
			}
			++ans;
			kv[k]=0;
		}
	}
}
void case3(int k)
{
	
	vis[k]=1;
	if(have[k] && (col[now]^col[k]) && lv[now]>=lv[k])//有子可以吃
	{
		return ;
	}
	for(int i=0;i<4;++i)
	{
		if(!poi[k].nxt[i]) continue;//没有路 
		if(poi[k].opt[i]!=3 || vis[poi[k].nxt[i]]) continue;//opt不是3 或 走过了 
		if(have[poi[k].nxt[i]] && (!(col[now]^col[poi[k].nxt[i]]) || lv[now]<lv[poi[k].nxt[i]])) continue;//有子不能吃 
		ans+=kv[poi[k].nxt[i]];
		case3(poi[k].nxt[i]);
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read(),++T;
	while(--T)
	{
		n=read(),m=read(),q=read();
		for(int i=0;i<400005;++i) poi[i]=(node){{0,0,0,0},{0,0,0,0}};
		have.reset(),vis.reset();
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<m;++j)
			{
				topt=getchar()-'0';
				poi[id(i,j)].opt[L]=poi[id(i,j+1)].opt[R]=topt;
				poi[id(i,j)].nxt[L]=id(i,j+1),poi[id(i,j+1)].nxt[R]=id(i,j);
			}
			getchar();
		}
		for(int i=1;i<n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				topt=getchar()-'0';
				poi[id(i,j)].opt[D]=poi[id(i+1,j)].opt[U]=topt;
				poi[id(i,j)].nxt[D]=id(i+1,j),poi[id(i+1,j)].nxt[U]=id(i,j);
			}
			getchar();
		}
		++q;
		while(--q)
		{
			vis.reset(),kv.set();
			c=read(),l=read(),inx=read(),iny=read();
			now=id(inx,iny),col[now]=c,lv[now]=l,have[now]=1;
			ans=0;
			case1(now);
			case2(now);
			case3(now);
			if(ans==0) putchar('0');
			else out(ans);
			putchar('\n');
		}
	}
	return 0;
}

