#include<bits/stdc++.h>
using namespace std;
const int L=1e7+1,N=L+5;
int T,c,p[N],t[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=L;i++){
		if(p[i])continue;
		for(int x=i;x!=0;x/=10)
		if(x%10==7){p[i]=1;break;}
		if(!p[i]){t[c]=i;c=i;continue;}
		for(int j=i;j<=L;j+=i)p[j]=1;
	}
	for(scanf("%d",&T);T--;){
		int x;scanf("%d",&x);
		printf("%d\n",t[x]?t[x]:-1);
	}
	return 0;
}
