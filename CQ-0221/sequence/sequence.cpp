#include <bits/stdc++.h>

using namespace std;
const int MAXN=105,MAXS=1005;
int n,m,k;

int a[MAXN],s[MAXS][MAXN],Top,P=998244353;
int v[MAXN];

long long Pow(long long x,long long y)
{
	long long ans=1;
	while(y)
	{
		if(y&1)
		{
			ans=ans*x%P;
		}
		x=x*x%P;
		y>>=1;
	}
	return ans;
}
long long C[MAXN][MAXN];
long long ans=0;
bool PopCount()
{
	int Cnt=0;
	long long S=0;
	for(int i=0;i<=m;i++)
	{
		S+=a[i]*(1<<i);
	}
	
	while(S)
	{
		if(S&1)
		Cnt++;
		S>>=1;
	}
//	cout<<"Cnt:"<<Cnt<<" "<<S<<endl;
	return Cnt<=k;
}
void dfs(int step,int Lose)
{
	if(step==m)
	{
		a[step]=Lose;
		if(PopCount()==true)
		{
		/*	
		for(int i=0;i<=m;i++)
		cout<<a[i]<<" ";
		cout<<endl; 
		*/
			long long Now=1;
			int Sum=n;
			for(int i=0;i<=m;i++)
			{
				Now=(Now*Pow(v[i],a[i])%P*C[Sum][a[i]])%P;
				Sum-=a[i];
			}
			ans=(ans+Now)%P;
		}
		return;
	}
	Top++;
	for(int i=0;i<=step;i++)
	s[Top][i]=a[i];
	for(int i=0;i<=Lose;i++)
	{
		a[step]=i;
		dfs(step+1,Lose-i);
		for(int j=0;j<=step;j++)
		a[j]=s[Top][j];
	}
	Top--;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	{
		scanf("%d",&v[i]);
	}
	C[0][0]=1;
	for(int i=1;i<=100;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=100;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
		}
	}
	dfs(0,n);
	cout<<ans;
	return 0;
}
/*
I Love CQ-266 Forever!
*/
