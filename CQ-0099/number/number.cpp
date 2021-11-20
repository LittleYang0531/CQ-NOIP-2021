#include<bits/stdc++.h>
using namespace std;
int T,n,a[200010],naxx=0,ans[1000010],top=0;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct ban
{
	int sum,base;
};
bool operator < (const ban &a,const ban &b)
{
	return a.sum>b.sum;
}
priority_queue<ban> q;
bool check(int x)
{
	while(x)
	{
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=T;i++) a[i]=read(),naxx=max(naxx,a[i]);
	for(int i=1;i<=naxx*2;i++)
	{
		int f=0;
		if(check(i))
		{				
			//if(!mc[i+i]){
				q.push((ban){i+i,i});
				f=1;
			//	cout<<"->1push:"<<i+i<<endl;
			//}
		//	cout<<i<<" "<<q.top().sum<<endl;
		}
		if(!q.empty()&&q.top().sum==i)
		{
		//	cout<<i<<endl;
			ban now=q.top();
			int Genshin=now.sum;
			//if(!mc[now.sum+now.base]){
			while(now.sum==Genshin)
			{
				q.pop();
				q.push((ban){now.sum+now.base,now.base});
			//	cout<<"->2push:"<<now.sum+now.base<<endl;
				now=q.top();				
			}
			f=1;			
			//}
		}
		if(f) continue;
		ans[++top]=i;
	}
	for(int i=1;i<=T;i++)
	{
		
		int yy=lower_bound(ans+1,ans+top+1,a[i])-ans;
		if(ans[yy]!=a[i]) 
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n",ans[yy+1]);
	}
	return 0;
}
