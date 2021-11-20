#include<bits/stdc++.h>
using namespace std;
bool is_prime[20000003];
long long Num[20000003];
int tot;
bool check(int x){
	bool flag=false;
	while(x){
		int ans=x%10;x/=10;
		if(ans==7)flag=true;
	}
	return flag;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000020;i++){
		if(Num[tot]>10000000)break;
		if(is_prime[i])continue;
		if(check(i)){
			is_prime[i]=1;
			for(int j=2*i;j<=10000020;j+=i)is_prime[j]=1;
		}
		if(!is_prime[i])Num[++tot]=i;
	}
	int T;
	cin>>T;
	while(T--){
		int x;scanf("%d",&x);
		int now=lower_bound(Num+1,Num+tot+1,x)-Num;
		if(Num[now]!=x)printf("-1\n");
		else{
			printf("%d\n",Num[now+1]);
		}
	}
	return 0;
}
