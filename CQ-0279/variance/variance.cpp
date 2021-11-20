#include<bits/stdc++.h>
using namespace std;
int v[100];
int n;
int sum=0,sum2=0;
int a,b,m,ans;
long long T=9743865;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);	
	srand(time(0));
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
		sum+=v[i];
		sum2+=v[i]*v[i];
	}
	ans=n*sum2-sum*sum;
	int j;
	while(T--){
		j=rand()%(n-2)+1;
		a=v[j-1]+v[j+1]-v[j];
		sum+=a-v[j];
		sum2+=a*a-v[j]*v[j];
		v[j]=a;
		ans=min(n*sum2-sum*sum,ans);
	}		
	cout<<ans;
	return 0;
}
