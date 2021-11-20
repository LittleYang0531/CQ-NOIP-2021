#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int read()
{
	int x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar('0'+x%10);
}
int a[10005],n,d[10005],td[10005];
void makeD()
{
	int L=0,R=0;
	vector<int> SL,SR;
	for(int i=2;i<=n;++i)
	{
		if(L<=R)
		{
			L+=td[i];
			SL.push_back(td[i]);
		}
		else
		{
			R+=td[i];
			SR.push_back(td[i]);
		}
	}
	sort(SL.begin(),SL.end(),greater<int>());
	sort(SR.begin(),SR.end());
	int cnt=1;
	for(auto st:SL)	d[++cnt]=st;
	for(auto st:SR)	d[++cnt]=st;
}
int pt[105];
int main(){
	freopen("variance.in","r",stdin);
//	freopen("variance5.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	int up=0;
	for(int i=1;i<=n;++i)	up=max(up,a[i]=read());
	for(int i=1;i<=n;++i)	td[i]=a[i]-a[i-1];
	srand(time(NULL));
	default_random_engine e(rand());
	LL ans=2e18;
	for(int Case=1;Case<=(n>400?3000:100000);++Case)
	{
		shuffle(td+2,td+1+n,e);
		d[1]=td[1];
		makeD();
		LL sum=0,ret=0,sm=0;
		for(int i=1;i<=n;++i)
		{
			sum+=(n-i+1)*d[i];
			sm+=d[i];
			ret+=sm*sm;
		}
		ret*=n;
		ret-=sum*sum;
		ans=min(ans,ret);
	}
	write(ans);
	return 0;
}
/*
the nonexistent summer...
ÕÒ¹æÂÉÅ£±Æ ¹þ¹þ
*/
