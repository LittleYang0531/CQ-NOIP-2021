#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,num,c,ccc,f,F,FF,Ff,FFF,CF;
	cin>>T;
	for(int i=1;i<=T;i=i+1)
	{
		F=0;
		f=0;
		cin>>num;
		for(int j=1;j<=num;j=j+1)
		{
			f=0;
			c=j;
			while(c!=0)
			{
				ccc=c%10;
				c=c/10;
				if(ccc==7)
				{
					f=1;
				}
				
			}
			if(num%j==0&&f==1)
			{
				F=1;
				break;
			}
		}
		if(F==1)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int j=num+1;j<=999999999;j=j+1)
		{
			FFF=0;

			FF=0;
			for(int C=1;C<=j;C=C+1)
			{
				Ff=0;
				c=C;
				while(c!=0)
				{
					ccc=c%10;
					c=c/10;
					if(ccc==7)
					{
						Ff=1;
					}
				}
				if(j%C==0&&Ff==1)
				{
					FFF=1;
					break;
				}
			}
			if(FFF==1)
			{
				continue;
			}else
			{
				CF=1;
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
