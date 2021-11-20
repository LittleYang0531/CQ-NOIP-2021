#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9') c=getchar();
	while(c>='0' and c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
int T;
int x;
int p[10000005];
inline bool check(int x){
	int c=x;
	while(c){
		if(c%10==7) return false;
		c/=10;
	}
	return true;
}
bool dfs(int x){
	if(p[x]==-1) return false;
	else if(!check(x)){
		p[x]=-1;
		for(register int j=1;j<=10000000/x;j++) p[x*j]=-1;
		return false;
	}
	
	for(register int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			if(p[i]==-1) return false;
			else if(!check(i)){
				p[i]=-1;
				for(register int j=1;j<=10000000/i;j++) p[i*j]=-1;
				return false;
			}
			
			if(p[x/i]==-1) return false;
			else if(!dfs(x/i)){
				p[x/i]=-1;
				return false;
			}
		}
	}
	return true;
}
//bool check1(int x){
//	for(int i=1;i<=81903;i++){
//		if(num[i]>x) break;
//		if(x%num[i]==0) return false;
//	}
//	return true;
//}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	T=read();
//	for(register int i=1;i<=10000000;i++){
//		if(p[i]==-1) continue;
//		
//		if(!check(i)) for(register int j=1;j<=10000000/i;j++) p[i*j]=-1;
////		else p[i]=1;
//	}
	while(T--){
		x=read();
		if(p[x]==-1){
			printf("-1\n");
			continue;
		}else if(!dfs(x)){
			p[x]=-1;
			for(register int j=1;j<=10000000/x;j++) p[x*j]=-1;
			printf("-1\n");
			continue;
		}else p[x]=1;
		for(register int i=x+1;;i++){
			if(p[i]==-1) continue;
			else if(!check(i)){
				p[i]=-1;
				for(register int j=1;j<=10000000/i;j++) p[i*j]=-1;
				continue;
			}
			
			if(p[i]==1){
				printf("%d\n",i);
				break;
			}else if(dfs(i)){
				p[i]=1;
				printf("%d\n",i);
				break;
			}
//			else{
//				for(register int j=1;j<=10000000/i;j++) p[i*j]=-1;
////				break;
//			}
		}
	}
	return 0;
}
