#include<bits/stdc++.h>
using namespace std;
int a[10000005],b[10000005],T,t,x,f,tmp;
bool check(int x){
	for(;x;x/=10){
		if(x%10==7)return 1;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=10000000;++i){
		f=check(i)?1:0;
		if(!a[i]&&!f)b[++t]=i;
		if(f){
			for(int j=i;j<=10000000;j+=i){
				a[j]=1;
			}
		}
	}
	for(scanf("%d",&T);T--;){
		scanf("%d",&x);
		if(a[x])printf("-1\n");
		else{
			tmp=lower_bound(b+1,b+t+1,x+1)-b;
			printf("%d\n",b[tmp]);
		}
	}
	return 0;
}
