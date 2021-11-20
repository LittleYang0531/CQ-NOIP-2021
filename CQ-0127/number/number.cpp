#include<bits/stdc++.h>
using namespace std;
int t,a[200005],b[10000005];
int judge(int x)
{
	if(b[x]==1) return 1;
	if(b[x]==5) return 0;
	int xx=x;
	while(xx!=0)//是否7 
	{
		if(xx%10==7) {b[x]=1;return 1;}
		xx/=10;
	}
	
	for(int i=2;i<sqrt(x);i++)//乘积数中是否有7 
	{
		if(x%i==0)
		{
			if(judge(x/i)==1) {b[x/i]=1;return 1;}
			if(judge(i)==1) {b[i]=1;return 1;}
		}
	}
	
	b[x]=5;
	return 0;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++) scanf("%d",&a[i]);
	
	for(int i=1;i<=t;i++)
	{
		if(judge(a[i])==1) {cout<<"-1"<<endl;continue;}
		int ans=a[i]+1;
		while(judge(ans)==1)
		{
			ans++;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
