#include<bits/stdc++.h>
using namespace std;
const int maxk=2e7+5,maxf=2e5+5;
int T,x[maxf],ans[maxk],nxt[maxk],cnt,now,maxn;
bool prime[maxk];
inline void Prime(int n){
	for(int i=2;i<=n;++i){
		if(!prime[i])
			ans[++cnt]=i;
		for(int j=1;j<=cnt&&ans[j]*i<=n;++j){
			prime[ans[j]*i]=0;
			if(!(i%ans[j]))
				break;
		}
	}
}
inline bool p(int k){
	while(k){
		if(k%10==7)
			return 0;
		k/=10;
	}
	return 1;
}
inline void init(int now){
	while(now<=maxn){
		for(int i=now+1;;++i){
			if(!(i%7)){
				nxt[i]=-1;
			} else if(nxt[i]==-1){
				for(int j=1;j<=cnt&&i*ans[j]<=maxn*2;j++)
					nxt[ans[j]*i]=-1;
			} else if(p(i)){
				nxt[now]=i;	
				now=i;
				break;
			} else{
				nxt[i]=-1;
				for(int j=1;j<=cnt&&i*ans[j]<=maxn*2;j++)
					nxt[ans[j]*i]=-1;
			}
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
		scanf("%d",&x[i]),maxn=max(maxn,x[i]);
	Prime(maxn*2);
	init(0);
	for(int i=1;i<=T;++i)
		printf("%d\n",nxt[x[i]]);
	return 0;
}
