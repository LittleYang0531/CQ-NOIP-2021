#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
int n,m;
int mark[N],p[N];
int check(int x){
	while(x){
		int tmp=x%10;
		if(tmp==7)return 1;
		x/=10;
	}return 0;
}
inline void init(){
	for(int i=1;i<N;i++){
		if(mark[i])continue;
		if(check(i))for(int j=i;j<N;j+=i)mark[j]=1;
		else p[++p[0]]=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(mark[n]){puts("-1");continue;}
		else{
			int po=upper_bound(p+1,p+1+p[0],n)-p;
			printf("%d\n",p[po]);
		}
	}
}
