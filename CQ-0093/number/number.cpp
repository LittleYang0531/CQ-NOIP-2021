#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,t,q[200005],ma,qwq[15],an[1000005],tot,p[1000005],cnt;
bool v[10000005],v0[10000005];
int maxx(int x,int y){return x<y?y:x;}
void js(int now,int bj,int d)
{
	int i,j;
//	cout<<"QAQ"<<" "<<now<<endl;
	if(!now){if(bj)v[d]=1;return ;}
	for(i=0;i<=9;++i)
	{
		if(i==7)js(now-1,1,d+i*qwq[now]);
		else js(now-1,bj,d+i*qwq[now]);
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,j,l,r;
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		scanf("%d",&q[i]);
		ma=maxx(ma,q[i]);
	}
	ma*=9;
	if(ma>10000001){ma=10000001;n=7;}
	qwq[1]=1;
	for(i=2;i<=8;++i)
	{
		qwq[i]=qwq[i-1]*10;
		if(qwq[i]>ma&&!n)n=i-1;
	}
//	cout<<"qwq"<<n<<endl;
	js(n,0,0);v0[1]=1;
	for(i=1;i<=ma;++i)
	{
		if(!v[i])an[++tot]=i;
		if(!v0[i])p[++cnt]=i;
		for(j=1;j<=cnt&&p[j]<=(ma*1.0/i);++j){v0[p[j]*i]=1;if(v[i]||v[p[j]])v[p[j]*i]=1;}
//		for(j=1;j<=cnt&&p[j]<=(ma*1.0/i);++j)
//		{
//			v0[p[j]*i]=1;
//			if(v[i]||v[p[j]])v[p[j]*i]=1;
//			if(!(i%p[j]))break;
//		}
	}
//	for(i=1;i<=tot;++i)cout<<"QAQ"<<an[i]<<endl;
	for(i=1;i<=t;++i)
	{
		if(v[q[i]]){puts("-1");continue;}
		l=1;r=tot;
		while(l<r)
		{
			int mid=l+r>>1;
//			cout<<"QAQ"<<mid<<" "<<an[mid]<<endl;
			if(q[i]>an[mid])l=mid+1;
			else r=mid;
		}
		printf("%d\n",an[l+1]);
	}
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169
*/
