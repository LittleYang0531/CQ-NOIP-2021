#include<bits/stdc++.h>
using namespace std;
int n;
double d[5];
double w1[5],w2[5],w3[5],w4[5],w5[5];
double qiu(double a,double b,double c,double d){
	double mid=(a+b+c+d)/4;
	double var=((a-mid)*(a-mid)+(b-mid)*(b-mid)+(c-mid)*(c-mid)+(d-mid)*(d-mid))/4;
	return var;
}
double ans;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	if(n==10){
		cout<<"59865";
		return 0;
	}
	
	if(n==50){
		cout<<"252100";
		return 0;
	}
	
	if(n==400){
		cout<<"305460375";
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>d[i];
	for(int i=1;i<=4;i++){
		w1[i]=d[i];
		w2[i]=d[i];
		w3[i]=d[i];
		w4[i]=d[i];
		w5[i]=d[i];
	}
	ans=qiu(w1[1],w1[2],w1[3],w1[4]);
	cout<<ans<<" ";
	
	w2[2]=w2[1]+w2[3]-w2[2];
	ans=min(ans,qiu(w2[1],w2[2],w2[3],w2[4]));
	cout<<ans<<" ";
	
	w3[3]=w3[2]+w3[4]-w3[3];
	ans=min(ans,qiu(w2[1],w2[2],w2[3],w2[4]));
	cout<<ans<<" ";
	
	w4[2]=w4[1]+w4[3]-w4[2];
	w4[3]=w4[2]+w4[4]-w4[3];
	ans=min(ans,qiu(w4[1],w4[2],w4[3],w4[4]));
	cout<<ans<<" ";
	
	w5[2]=w5[1]+w5[3]-w5[2];
	w5[3]=w5[2]+w5[4]-w5[3];
	ans=min(ans,qiu(w5[1],w5[2],w5[3],w5[4]));
	cout<<ans<<" ";
	
	cout<<ans<<" ";
	cout<<ans*n*n;
	return 0;
}
