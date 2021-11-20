#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e7+20;
int a[MAXN],b[MAXN];
char buf[100000],*p1=buf,*p2=buf;
char nc() {
	if(p1==p2)p2=buf+fread(p1=buf,1,100000,stdin);
	if(p1==p2)return -1;
	return *p1++;
}
int read() {
	int x=0;
	char c=nc();
	while(c<'0'||c>'9')c=nc();
	for(; c>='0'&&c<='9'; c=nc())x=x*10+c-'0';
	return x;
}
int c[MAXN],c_;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1; i<MAXN; i++) {
		if(b[i])continue;
		for(int x=i; x; x/=10)if(x%10==7) {
				for(int j=i; j<MAXN; j+=i)b[j]=1;
				break;
			}
	}
	for(int i=1; i<MAXN; i++)if(b[i]==0)c[++c_]=i;
	int n=read();
	for(int i=1; i<=n; i++) {
		int x=read();
		int t=0;
		for(int bj=20; bj>=0; bj--)if(t+(1<<bj)<=c_)
				if(c[t+(1<<bj)]<=x)t+=1<<bj;
		if(c[t]==x)printf("%d\n",c[t+1]);
		else puts("-1");
	}
	return 0;
}
