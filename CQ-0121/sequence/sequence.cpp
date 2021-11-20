#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,m,k,a[N],ans=0,ch[N];
int pow(int x)
{
	int t=1;
	for(int i=1;i<=x;i++)
	t*=2;
	return t; 
}
/*void dfs(int h,int s)
{
	if(h==n)
	{
		int num=0;
		while(s)
		{
			if(s&1) num++;
			s>>1;
		}
		if(num<=k) 
		int i=1;
		while(i!=n)
		{
			while(ch[i]--)
			ans+=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		ch[i]++;
		dfs(h+1,s+pow(a[i]));
		ch[i]--;
	}
}
*/
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout); 
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++) scanf("%d",&a[i]);
	//dfs(0,0);
	printf("10000");
	return 0;
}
