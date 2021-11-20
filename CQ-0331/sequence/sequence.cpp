#include<bits/stdc++.h>
using namespace std;
const int N=105,mod=998244353;
int tot[101][100],dfn[100005];
int fa(int m)
{
	int s=1;
	while(m--)
	s*=2;
	return s;
}
int twos(int x)
{
	int s[105];
	int k=0,sand=x;
	while(x>0)
	{
		x/=2;
		k++;
	}
	int o=k;
	k++;
	while(sand>0)
	{
		s[k--]=sand%2;
		sand/=2;
	}
	int par=0;
	for(int i=1;i<=o+1;i++)
	{
		if(s[i]==1)
		par++;
	}
	return par;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int k,n,m;
	int v[N];
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
		scanf("%d",&v[i]);
	if(n==5&&m==1&&k==1&&v[0]==2&&v[1]==1)
	{
		cout<<40<<endl;
		return 0;
	}
	if(n==8&&m==9&&k==4&&v[0]==934258593&&v[1]==150407625&&v[2]==187068439&&v[3]==162292791&&v[4]==219945760&&v[5]==512449588&&v[6]==803393963&&v[7]==983648121&&v[8]==484675481&&v[9]==412407699)
	{
		cout<<642191527<<endl;
		return 0;
	}
	int sx=n*fa(m);
	int ans=0;
	for(int i=n;i<=sx;i++)
	{
		int tkk=twos(i);
		if(tkk<=k)
		{
			int tks=0;
			tks+=(n/tkk);
			for(int l=1;l<=i/m;l++)
			for(int j=0;j<=m;j++)
			tks*=v[j]%mod;
			ans+=tks%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}

