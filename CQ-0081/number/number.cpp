#include<bits/stdc++.h>
#define N 10000005
using namespace std;
int n,is[N],is2[N],nx[N];
int read() {
	int s=0,f=0;
	char ch=getchar();
	while(ch<48||ch>57)f|=(ch=='-'),ch=getchar();
	while(ch>47&&ch<58)s=s*10+(ch^48),ch=getchar();
	return f?-s:s;
}
void Dfs(int x,int num,int op) {
	if(x==7)return is[num]=op,void();
	for(int i=0; i<10; ++i)Dfs(x+1,num*10+i,op|(i==7));
}
bool Check(int n) {
	for(int i=1; i<n; ++i)
		if(is[i]&&n%i==0)return false;
	return true;
}
void Pre(int n) {
	for(int i=1; i<=n; ++i)
		if(is[i]&&!is2[i])for(int j=i; j<=n; j+=i)is2[j]=1;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Dfs(0,0,0),Pre(N-5);
	int nxt=10000001;
	for(int i=10000000; i; --i) {nx[i]=nxt;if(!is2[i])nxt=i;}
	for(int T=read(),n; T; --T) {
		n=read();
		if(n==0||is2[n])puts("-1");
		else cout<<nx[n]<<"\n";
	}
	return 0;
}
