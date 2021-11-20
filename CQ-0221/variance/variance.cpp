/*
其实我会做
Qi Shi Wo Hui Zuo
但来不及了
Dan Lai Bu Ji Le

/kk 
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e4+50;
const double eps=1e-3;

int n;
int a[MAXN];

double Min,l=1000.0,r,Mid1,Mid2;

double Check(double Now)
{
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=((double)a[i]-Now)*((double)a[i]-Now);
	}
	return ans;
}
int NowSum;


double Middle;

struct Dot
{
	int id,l,r,Len;
	Dot(){}
	Dot(int _id,int _l,int _r,int _Len)
	{
		id=_id;
		l=_l;
		r=_r;
		Len=_Len;
	}
};

bool operator > (Dot x,Dot y)
{
	return x.Len>y.Len;
}
bool Cant[MAXN];

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout); 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		l=min(l,(double)a[i]);
		r=max(r,(double)a[i]);
	}
	/*
	for(int i=1;i<=n;i++)
	{
		double Now=0;
		for(int j=1;j<=n;j++)
		{
			
		}
	}
	*/	
	/*
	Middle=(a[1]+a[n])*0.50;
	priority_queue<Dot,vector<Dot>,greater<Dot> >q;
	for(int i=2;i<n;i++)
	{
		q.push(Dot(i,i-1,i+1,(Middle-a[i])-(a[i-1]+a[i+1]-a[i])));
	}
	while(!q.empty())
	{
		while(!q.empty()&&Cant[q.top().id])
		q.pop();
		Dot Now=q.top();
		
		q.pop();
		
	}
	*/
	
	while(r-l>=eps)
	{
		Mid1=l+(r-l)/3.0;
		Mid2=l+2*(Mid1-l);
	//	cout<<l<<" "<<Mid1<<" "<<Mid2<<" "<<r<<" "<<Check(Mid1)<<" "<<Check(Mid2)<<endl;
		if(Check(Mid1)>Check(Mid2))
		{
			Min=Mid2;
			l=Mid1+eps;
		}
		else
		{
			r=Mid1-eps;
		}
	}
	cout<<Check((int)(Min+0.5))*n<<endl;
	return 0;
}
