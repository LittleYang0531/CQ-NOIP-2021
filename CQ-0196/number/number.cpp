#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int t,n,lt,ans[N];
bool check(int x)
{
	while(x)
	{
		int k=x%10;
		if(k==7) return true;
		x/=10;
	}
	return false;
}
void find(int x)
{
	for(int i=x;i<N;i+=x) ans[i]=-1;
	return;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	memset(ans,0,sizeof(ans));
	for(int i=1;i<N;i++) if(check(i)&&(~ans[i])) find(i);
	else if(~ans[i]) ans[lt]=i,lt=i;
	while(t--)
	{
		scanf("%d",&n);
		printf("%d",ans[n]);
		putchar('\n');
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
