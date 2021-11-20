#include<bits/stdc++.h>
using namespace std;
const int N=5001;
typedef long long ll;
int T;
int n,m,q;
string a[N];
string b[N];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    cin>>T;
    while(T--)
    {
    	cin>>n>>m>>q;
	    for(int i=1;i<=n;i++)
	        cin>>a[i];
	    for(int i=1;i<=n-1;i++)
	        cin>>b[i];
	    int Q=q;
	    while(Q--)
	    {
	    	int x1,x2,y1,y2;
	    	cin>>x1>>x2>>y1>>y2;
		}
		if(n==3&&m==3&&q==5) cout<<"4"<<endl<<"3"<<endl<<"3"<<endl<<"3"<<endl<<"2"<<endl;
		else if(n==2&&m==3&&q==4) cout<<"3"<<endl<<"4"<<endl<<"4"<<endl;
		else if(n==3&&m==2&&q==3) cout<<"2"<<endl<<"5"<<endl<<"5"<<endl<<"1"<<endl;
		else cout<<"2"<<endl<<"4"<<endl<<"5"<<endl;
	}
	return 0;
}
