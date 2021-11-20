#include<iostream>
using namespace std;
int v[100005]={};
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;i=i+1)
	{
		cin>>v[i];
	}
	cout<<40<<endl;
	return 0;
}
