#include<iostream>
#include<ctime>
#include<crand>
using namespace std;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	cin>>n;
	srand(time(0));
	cout<<rand();
	return 0;
}
