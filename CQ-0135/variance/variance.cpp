#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int n,a[maxn];
int zi[maxn];
int mu[maxn];
int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
void yue(int x){
	int s=gcd(zi[x],mu[x]);
	zi[x]=zi[x]/s;
	mu[x]=mu[x]/s;
}
/*int add(int x,int y){
	int s=mu[x]*mu[y];
	zi[x]*=mu[y];
	mu[x]=s;
	zi[y]*=mu[x];
	mu[y]=s;
	
}*/
int ans;
int fczi=maxn,fcmu=1;
void jian(int p){
	int q=mu[p]*mu[0];
	zi[p]*=mu[0];
	zi[0]*=mu[p];
	mu[p]=q;
	mu[0]=q;
	zi[n+1]=(zi[p]-zi[0])*(zi[p]-zi[0]);
	mu[n+1]=q*q;//fc
	yue(n+1);
	yue(p);
	yue(0);
}
void qfc(){
	for(int i=1;i<=n;i++){
		jian(i);
		//cout<<zi[n+1]<<" "<<mu[n+1]<<endl;
		int r=mu[n+2]*mu[n+1];
		zi[n+2]*=mu[n+1];
		zi[n+1]*=mu[n+2];
		mu[n+1]=r;
		mu[n+2]=r;
		zi[n+2]=zi[n+2]+zi[n+1];
		yue(n+2);
		yue(n+1);
		//cout<<zi[n+2]<<" "<<mu[n+2]<<endl;
	}
	mu[n+2]*=n;
	yue(n+2);
}
void yf(){
	int b=gcd(fczi,fcmu);
	fczi=fczi/b;
	fcmu=fcmu/b;
}
void judge(){
	int c=mu[n+2]*fcmu;
	fczi*=mu[n+2];
	zi[n+2]*=fcmu;
	mu[n+2]=c;
	if(zi[n+2]<fczi){
		fczi=zi[n+2];
		fcmu=c;
	}
	yue(n+2);
	yf();
}
void dfs(int t){
	if(t>n-2){
		return;
	}
	mu[0]=n;
	zi[0]=0;
	for(int i=1;i<=n;i++){
		zi[0]+=a[i];
	}
	yue(0);
	//cout<<zi[0]<<" "<<mu[0]<<endl;
	zi[n+2]=0;
	mu[n+2]=1;
	qfc();
	//cout<<zi[n+2]<<" "<<mu[n+2]<<endl;
	judge();
	for(int i=2;i<n;i++){
		int f=a[i];
		if(a[i-1]+a[i+1]-a[i]!=a[i]){
			a[i]=a[i-1]+a[i+1]-a[i];
			dfs(t+1);
		}
		a[i]=f;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	mu[n+1]=mu[n+2]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		zi[i]=a[i];
		mu[i]=1;
		zi[0]+=a[i];
	}
	mu[0]=n;
	//cout<<zi[0]<<" "<<mu[0]<<endl;
	yue(0);
    dfs(0);
    //cout<<fczi<<" "<<fcmu<<endl;
    fczi*=n*n;
    yf();
    cout<<fczi<<endl;
}
