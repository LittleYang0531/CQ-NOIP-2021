#include<bits/stdc++.h>
using namespace std;
#define re register int
#define LL long long
#define gc() getchar()
inline int rd()
{
	int x=0,f=1;
	char c=gc();
	for(; c<'0'||c>'9'; c=gc())if(c=='-')f=0;
	for(; '0'<=c&&c<='9'; c=gc())x=(x<<1)+(x<<3)+c-'0';
	return f?x:-x;
}
struct node{int s1, s2, s;};
bool operator<(const node&p, const node&q){
	return p.s1==q.s1?p.s2==q.s2?p.s<q.s:p.s2<q.s2:p.s1<q.s1;
}
map<node,int>f[2];
bool cmp(int x, int y){return x>y;}
void ins(int x, node p, int val)
{
	if(!f[x].count(p))f[x][p]=val;
	else f[x][p]=min(f[x][p], val);
}
int n, a[405], b[405], sum, ans=1e9;
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=rd();
	for(re i=1;i<=n;++i)a[i]=rd();
	for(re i=2;i<=n;++i)b[i-1]=a[i]-a[i-1], sum+=b[i-1];
	a[n]=a[n]-a[1];
	a[1]=0;
	sort(b+1,b+n,cmp);
	f[0][(node){0,0,a[1]+a[n]}]=a[1]*a[1]+a[n]*a[n];
	for(re p=0;p<n-1;++p)
	{
		int i=(p&1);
		f[i^1].clear();
		map<node,int>::iterator it;
		it=f[i].begin();
		while(it!=f[i].end())
		{
			node temp=(*it).first;
			int val=(*it).second;
			it++;
			int s1=temp.s1, s2=temp.s2, s=temp.s;
			if(p==n-2){ans=min(ans, n*val-s*s);continue;}
			int x=a[1]+(s1+b[p+1]);
			int y=a[n]-(s2+b[p+1]);
			node p1=(node){s1+b[p+1], s2, s+x};
			node p2=(node){s1, s2+b[p+1], s+y};
			ins(i^1, p1, val+x*x);
			ins(i^1, p2, val+y*y);
		}
	}
	printf("%d\n", ans);
	return 0;
}
