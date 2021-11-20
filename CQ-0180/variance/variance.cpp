#include<bits/stdc++.h>
using namespace std;
double n,p,an=1e9,t,x;
set<vector<double> > s;
vector<double> q;
void search(vector<double> q,double tot)
{
	if(s.count(q)>0) return;
	s.insert(q);
	p=tot/n;
	double ans=0;
	for(int a=1;a<=int(n);a++)
	{
		ans+=(q[a]-p)*(q[a]-p);
	}
	an=min(an,ans*n);
	for(int b=2;b<n;b++)
	{
		double h=double(q[b]),be=0,be2=0;
		for(int c=1;c<=n;c++) 
		{
			be+=(q[c]-tot/n)*(q[c]-tot/n);
		}
		q[b]=q[b+1]+q[b-1]-q[b];
		tot=tot-h+q[b];
		search(q,tot);
	}
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lf",&n);
	for(int a=1;a<=int(n);a++) scanf("%lf",&x),q.push_back(x),t+=x;
	search(q,t);
	long long ha=an;
	printf("%lld",ha);
	return 0;
}
