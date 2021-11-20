#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,a[N];
double var(int a[],int n)//Çó·½²î
{
	double tp,vr;
	for(int i=1;i<=n;i++)
	{
		tp+=a[i];
	}
	tp/=n;
	for(int i=1;i<=n;i++)
	{
		vr+=(a[i]-tp)*(a[i]-tp);
	}
	vr/=n;
	return vr;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
}

