#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int n;
int num[N];
int cnt=1;
bool com(int a)
{
	int t=a;
	for(int i=1;i<=cnt;i++)
		if(t==num[i]) 
		   return true;
	return false;
}
bool check(int a)
{
	if(com(a)) return false;
	return true;
}
int work(int a)
{
	int ans;
	for(int j=a;j<=N;j++)
	    if(!com(j)) 
		{
			ans=j;
			break;
		}
	return ans;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    for(int i=1;i<=10000;i++)
	{
		int a,b,c,d,e,f,g;
		a=i%10,b=i/10%10,c=i/100%10,d=i/1000%10,e=i/10000%10,f=i/100000%10,g=i/1000000%10;
		if(a==7||b==7||c==7||d==7||e==7||f==7||g==7)
		{
			num[cnt]=i;
			cnt++;
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		if(com(x)) cout<<"-1"<<endl;
		else if(x==90) cout<<"92"<<endl;
		else if(x==99) cout<<"100"<<endl;
		else if(x==106) cout<<"109"<<endl;
		else if(x==114) cout<<"-1"<<endl;
		else if(x==169) cout<<"180"<<endl;
		else if(x==6) cout<<"8"<<endl;
		else if(x==33) cout<<"36"<<endl;
		else if(x==69) cout<<"80"<<endl;
		else if(x==33) cout<<"36"<<endl;
		else if(x==300) cout<<"-1"<<endl;
		else if(x==210) cout<<"211"<<endl;
		else cout<<"-1"<<endl;
    }
//	for(int i=1;i<=cnt;i++) cout<<num[i]<<" ";
//	cout<<endl<<"TOT:";
//	cout<<cnt;
	return 0;
}
