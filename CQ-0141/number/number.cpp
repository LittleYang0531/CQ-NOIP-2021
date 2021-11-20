#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2;
int T,ii;
const int MAXN=200000;
bool shi7(int x)
{
	for(int i=1;i<=10;i++)
	{
		int a=x/pow(10,i-1);
		if(a%10==7) return true;
	}
	return false;
}
void pZd(int x,int xx,int sum)
{
	if(xx>MAXN) return; 
	v1[xx]=1;
	pZd(x,x*sum,sum+1);
}
void initz()
{
	for(ii=0;ii<=MAXN;ii++)
	{
		v1.push_back(0);
		v2.push_back(ii);
	}
		
	for(ii=1;ii<=MAXN;ii++)
	{
		if(v1[ii]==1) continue;
		if(shi7(ii)) pZd(ii,ii,2);//数字包含7 
		else v1[ii]=0;
	}
	int q=MAXN;
	for(int ii=MAXN;ii>=1;ii--)
	{ 
		if(v1[ii]==1) v2[ii]=q;
		else
		{
			v2[ii]=ii;
			q=ii;
		}
	}
}
bool checkz(int x)
{
	if(v1[x]==1) return true;
	return false;
}
int findz(int x)
{
	return v2[x];
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	initz(); 
	cin>>T;
	for(ii=1;ii<=T;ii++)
	{
		int x;
		scanf("%d",&x);
		if(checkz(x))//不能报出
		{
			cout<<-1<<endl;
			continue;
		}
		printf("%d\n",findz(x+1));
	}
	return 0;
}
