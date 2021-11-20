#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
using namespace std;
int n,a[10005];
double ans=2e9;
const int Mod=1e8+7,p=107;//¹şÏ£³£Êı 
bool vis[Mod+5];
int get(int x[]){
	ll Hash=0;
	rep(i,1,n){
		Hash=Hash*p+x[i];
		Hash%=Mod;
	}
	return Hash;
}
void dfs(int penguin){
	int volue=get(a);
	if(vis[volue]) {return;}
	else vis[volue]=true;
	double eve=0,sum=0;
	rep(i,1,n) eve+=a[i];
	eve/=n*1.0;
	rep(i,1,n) sum+=(eve-a[i])*(eve-a[i]);
	ans=min(ans,sum);
	//ËÑË÷-»ØËİ
	//cout << ans*n << endl; 
	rep(i,2,n-1){
		int m=a[i];
		a[i]=a[i+1]+a[i-1]-a[i];
		dfs(penguin+1);
		a[i]=m;
		dfs(penguin+1);
	} 
	return;
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	memset(vis,0,sizeof(vis));
	cin >> n;
	rep(i,1,n) cin >> a[i];
	double eve=0,sum=0;
	rep(i,1,n) eve+=a[i];
	eve/=n*1.0;
	rep(i,1,n) sum+=(eve-a[i])*(eve-a[i]);
	dfs(1);	
	cout << ans*n;	
	return 0;
} 
/*
10
6 19 34 35 56 63 82 82 83 99
*/
