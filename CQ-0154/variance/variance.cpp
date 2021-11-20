#include<bits/stdc++.h>
#define inl inline
using namespace std;
const int maxn=105;
int n,sum,ans=INT_MAX;
map<vector<int>,bool> vst; 
double temp=1,tem;
struct node
{
	vector<int> a;
	int anst,sum;
}st;
queue<node> q;
inl int Read()
{
	int s=0,f=1; char c;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=Read(); st.a.push_back(0);
	for(int i=1;i<=n;++i) st.a.push_back(Read()),st.sum+=st.a[i];
	for(int i=1;i<=n;++i) st.anst+=st.a[i]*(n*st.a[i]-st.sum);
	tem=st.sum*st.sum; q.push(st);
	while(!q.empty())
	{
		node u=q.front(); q.pop();
		if(vst[u.a]) continue; vst[u.a]=true;
		ans=min(ans,u.anst);
		if((double)u.anst>(double)ans+temp*tem) continue;
		temp*=0.999;
		for(int i=2;i<n;++i)
		{
			node v=u; v.a[i]=u.a[i-1]+u.a[i+1]-u.a[i]; v.sum+=v.a[i]-u.a[i]; v.anst=0;
			for(int i=1;i<=n;++i) v.anst+=v.a[i]*(n*v.a[i]-v.sum);
			q.push(v);
		}
	}
	printf("%d\n",ans);
	return 0;
}
