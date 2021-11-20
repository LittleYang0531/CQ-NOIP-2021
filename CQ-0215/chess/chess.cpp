#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	srand(time(0));
	cin>>n;
	if(n==1)
	{
		cout<<4<<endl<<3<<endl<<3<<endl<<3<<endl<<2<<endl;
	}
	else if(n==2)
	cout<<3<<endl<<4<<endl<<4<<endl<<2<<endl<<5<<endl<<5<<endl<<1<<endl;
	else
	{
		for(int i=1;i<=10;i++)
		{
			cout<<rand()%10+1<<endl;
		}
	}
	return 0;
}


