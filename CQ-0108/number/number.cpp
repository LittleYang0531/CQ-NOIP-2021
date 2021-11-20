//1s  512mb
#include<bits/stdc++.h>
using namespace std;
const int NN=10005;
int T,p[NN];

void ycl()
{
	for(int i=1;i<=NN/7;i++)//7的倍数 
		p[i*7]=1;
	for(int i=70;i<=79;i++)
		p[i]=1;
		
	for(int i=17;i<=NN;i+=10)
		p[i]=1;
	for(int i=170;i<=NN;i+=100)
		for(int j=i;j<=i+9;j++)
			p[j]=1;
	for(int i=1700;i<=NN;i+=1000)
		for(int j=i;j<i+100;j++)
			p[j]=1;
	
	for(int i=7000;i<=7999;i++)
		p[i]=1;
	for(int i=700;i<=799;i++)
		p[i]=1;
	for(int i=14;i<=NN;i++)
	{
		if(p[i]==1)
			for(int j=2;i*j<=NN;j++)
				p[i*j]=1;
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	
	ycl();
	cin>>T;
	while(T--)
	{
		int x;
		cin>>x;
		if(p[x]==1)//本来就不能报出
		{
			cout<<-1<<'\n';
			continue;
		}
		for(int i=x+1;;i++)
			if(p[i]!=1)
			{
				cout<<i<<'\n';
				break;
			}
	}
	return 0;
}
