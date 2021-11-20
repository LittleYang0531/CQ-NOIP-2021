#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=10005;
int n,a[maxn],ch[maxn],ans=2000000000;
int calc(){
	int sum=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		sum2+=(sum-a[i]*n)*(sum-a[i]*n);
	}
	return sum2;
}
bool cmp(int a,int b){
	return a>b;
}
bool c[15];
int cnt=0;
void baoli(int d){
	cnt++;
	if(d>n){
		ans=min(ans,calc()/n);
		return;
	}
	//b[1]=a[1];
	for(int i=1;i<n;i++){
		if(!c[i]){
			c[i]=1;
			a[d]=a[d-1]+ch[i];
			baoli(d+1);
			c[i]=0;
		}
	}
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			ch[i-1]=a[i]-a[i-1];
		}
	}
	if(n<=10){
		baoli(2);
		cout<<ans;
		return 0;
	}
	sort(ch+1,ch+n,cmp);
	int l=0,r=0,lp=1,rp=n;
	int sum=a[lp]+a[rp];
	for(int i=1;i<n;i++){
		if((i+1)*(a[rp]+a[lp])<sum*2){//    a[rp]-sum/(i+1)<sum/(i+1)-a[lp] (i+1)*(a[rp]+a[lp])<sum*2
			l+=ch[i];
			lp++;
			a[lp]=a[lp-1]+ch[i];
			sum+=a[lp];
		}
		else
		{
			r+=ch[i];
			rp--;
			a[rp]=a[rp+1]-ch[i];
			sum+=a[rp];
		}
	}
	ans=calc();
	cout<<ans/n;
	return 0;
}
/*
wrong tanxin
fuck sample 2
*/
