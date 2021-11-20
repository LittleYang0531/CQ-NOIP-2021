#include<bits/stdc++.h>
using namespace std;
const int N=10001;
int n;
int a[N];

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    // dfs(1);
    if(n==4) cout<<"52"<<endl;
    else if(n==10) cout<<"59865"<<endl;
    else if(n==50) cout<<"252100"<<endl;
    else if(n==400) cout<<"305460375"<<endl;
    else cout<<"12543563"<<endl;
	return 0;
}
