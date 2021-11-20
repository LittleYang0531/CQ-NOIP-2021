#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
bool vis[maxn];
void qishai(int n){
		for(int i=1;i<=n/7;++i){
		vis[7*i]=1;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		if(i==70||i==700||i==7000||i==70000||i==700000||i==7000000){
			int k=i,to=0;
			while(k){
				k/=10;
				to++;
			}
		    int j=i+pow(10,to-1);
		    for(int o=i;o<=j;++o) vis[o]=1;
		    i=j;
		}
		int k=i;
		while(k){
			if(k%10==7){
				vis[i]=1;
				break;
			}
			k/=10;
		}
	}
    for(int i=17;i<=maxn/2;++i){
    	if(!vis[i]||i%7==0) continue;
    	for(int j=2;i*j<=maxn;++j) vis[i*j]=1;
	}
}
int t,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	qishai(maxn);
	for(int i=1;i<=t;++i){
		n=read();
		if(vis[n]){
			print(-1);
			putchar('\n');
			continue;
		}
		else{
			int j;
			for(j=n+1;vis[j];++j){}
			print(j);
			putchar('\n');
		}
	}
	return 0;
}
