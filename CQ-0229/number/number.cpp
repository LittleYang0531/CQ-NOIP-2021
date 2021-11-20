#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool p[10000005];
int f[10000005],tot,T,xb[10000005];
bool k(int x){
	while(x>0){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=10000000;i++){
		if(p[i])continue;
		if(!k(i))continue;
		for(int j=i;j<=10000000;j+=i){
			p[j]=1;
		}
	}
	for(int i=1;i<=10000000;i++)
		if(!p[i])f[++tot]=i,xb[i]=tot;
	while(T--){
		int m;
		scanf("%d",&m);
		if(m==9999998){
			puts("10000001");
		}
		else if(p[m])puts("-1");
		else{
			printf("%d\n",f[xb[m]+1]);
		}
	}
	return 0;
}
