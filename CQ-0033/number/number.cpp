#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;bool vis=0;
	char k;
	do (k=getchar())=='-'&&(vis=1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
bool vis[11000005],vl[11000005];
int s,prime[11000005];
void init(const int N){
	for(int i=7;i<=N;++i){
		if(i%10==7)vis[i]=1;
		vis[i]|=vis[i/10];
	}for(int i=7;i<=N;++i)
		if(vis[i]&&!vl[i])
			for(int j=2;j*i<=N;++j)
				vis[i*j]|=vl[i*j]=1;
	for(int i=N;--i;)
		if(vis[i+1])prime[i]=prime[i+1];
		else prime[i]=i+1;
}
void Write(int x){
	if(x>9)Write(x/10);
	putchar(x%10^'0');
}
int main(){fre("number");
	init(11000000);
	for(int T=read;T--;){
		int x=read;
		if(vis[x])puts("-1");
		else Write(prime[x]),putchar('\n');
	}
	return 0;
}
