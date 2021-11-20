#include<bits/stdc++.h>
using namespace std;
const int M=50005;
const double N=0x3f3f;
int n,a[M];
double fan=N;

void ccf(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
}

double va(){
	int ans;
	for(int i=1;i<=n;i++){
		ans+=a[i];
	}
	return ans/double(n);
}

double d(double v){
	double ans;
	for(int i=1;i<=n;i++){
		ans+=(a[i]-v)*(a[i]-v);
	}
	return ans/n;
}

void dfs(int x,int c){
	if(x==n)return ;
	if(c==1&&a[x]!=a[x-1]+a[x+1]-a[x]){
		int u=a[x];
		a[x]=a[x-1]+a[x+1]-a[x];
		fan=min(fan,d(va()));
		
//		cout<<"chang:";
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
		
		dfs(x+1,1);
		dfs(x+1,0);
		a[x]=u;
		return ;
	}
	fan=min(fan,d(va()));
	dfs(x+1,1);
	dfs(x+1,0);
	return ;
}

int main(){
	ccf();
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	dfs(1,0);
	reverse(a+1,a+1+n);
	dfs(1,0);
//	cout<<fan;
//	
//		cout<<"chang:";
//		for(int i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<endl;
	cout<<int (fan*n*n);
	return 0;
}
/*
4
1 2 4 6
*/
