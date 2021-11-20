#include<bits/stdc++.h>
using namespace std;

int N;
int M;
int K;
int v[105];

void deal(int x)
{
	int k=1;
	int i=1;
	for(i;i<=x;i++)
	{
		k*=2;
		if(k>=x)
		{
			break;
		}
	}
	
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(false);	
	cin>>N>>M>>K;
	int L=N;
	int R=1;
	for(int i=1;i<=M+1;i++)
	{
		cin>>v[i];
		R*=2;
	}
	R/=2;
	for(int i=L;i<=R;i++)
	{
		int x=i;
		int k=0;
		while(x)
		{
			if(x&1)
			{
				k++;
			}
			x/=2;
		}
		if(k<=K)
		{
			deal(i);
		}
	}
	cout<<4*L*R<<endl;
	return 0;
}
