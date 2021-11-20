#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int T,n;
bool vis[15000005];
vector<int>G;
bool pd(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
void pre(){
	for(int i=1;i<=15000000;i++){
		if(!vis[i]){
			if(pd(i)){
				for(int j=i;j<=15000000;j+=i)vis[j]=1;
			}else G.push_back(i);

		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	pre();
	while(T--){
		n=read();
		if(vis[n])puts("-1");
		else {
			int x=upper_bound(G.begin(),G.end(),n)-G.begin();
			printf("%d\n",G[x]);
		}
	}
	return 0;
}
