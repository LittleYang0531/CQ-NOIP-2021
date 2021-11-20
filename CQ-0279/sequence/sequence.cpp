#include<bits/stdc++.h>
using namespace std;
int MOD=998244353;
long long A(int b,int a){
	int ans=1;
	for(int i=0;i<a;i++){
		ans*=b-a+i+1;
		ans/=i+1;
		ans%=MOD;
	}
	return ans;
}
long long n,m,k,ans=1;
long long v[100];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
		ans*=v[i];
		ans%=MOD;
	}
	cout<<A(n,m-k+1)*ans*(m+1)*A(m+1,k)%MOD;
	return 0;
}
