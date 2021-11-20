//Never stop ACing.
#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int ans=0x7fffffff/2;
int n;
int a[401];
struct rf
{
	int a[401];
}fi;
vector<rf> v;
queue<rf> q;
void push(rf a)
{
	v.push_back(a);
	q.push(a);
}
bool check(rf no)
{
	for(int i=0;i<v.size();i++)
	{
		bool flag=false;
		for(int j=1;j<=n;j++)
		{
			if(v[i].a[j]!=no.a[j])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)return false;
	}
	return true;
}
void zcy()
{
	rf wh=q.front();
	q.pop();
	for(int i=1;i<=n-2;i++)
	{
		int l=i,mid=i+1,r=i+2;
		int vl=wh.a[l],vmid=wh.a[mid],vr=wh.a[r],nmid=vl+vr-vmid;
		if(nmid==vmid)continue;
		rf no;
		for(int j=1;j<=l;j++)no.a[j]=wh.a[j];
		no.a[mid]=nmid;
		for(int j=r;j<=n;j++)no.a[j]=wh.a[j];
		if(check(no)==true)
		{
			push(no);
		}
	}
}
int solve(rf x)
{
	double sum=0,al=0;
	for(int i=1;i<=n;i++)sum+=x.a[i];
	sum=sum/(double(n));
	for(int i=1;i<=n;i++)al+=((double(x.a[i]))-sum)*((double(x.a[i]))-sum);
	al=al*(double(n));
	return al;
}
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		fi.a[i]=a[i];
	}
	push(fi);
	while(!q.empty())zcy();
	for(int i=0;i<v.size();i++)
	{
		int an=solve(v[i]);
		ans=min(ans,an);
	}
	cout<<ans;
	return 0;
}
//ÎÒ¸ÃAFOÁË 
