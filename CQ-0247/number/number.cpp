#include<bits/stdc++.h>
using namespace std;
int t,n,fl,mi,x[200005],a[11000005],b[11000005];
bool f(int k){
	if(k<10)return (k==7);
	return (k%10==7||f(k/10));
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)scanf("%d",&x[i]),n=max(n,x[i]);
	for(int i=1;;i++){
		if(i>n){fl=1,n++;}
		if(f(i)){
			b[i]=1;
			for(int j=2;i*j<=n+1000002;j++)b[i*j]=1;
		}
		if(fl&&!b[i])break;
	}
	for(int i=n;i>=1;i--)if(!b[i])a[i]=(mi==0?i:mi),mi=i;
	for(int i=1;i<=t;i++)printf("%d\n",(b[x[i]]?-1:a[x[i]]));
	return 0;
}
