#include<bits/stdc++.h>
using namespace std;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define N 10000005
char buf[1<<21],*p1=buf,*p2=buf;
inline int rd(){
	int x=0,f=1;char c=gc();
	for(;c>'9'||c<'0';c=gc()) if(c=='-') f=0;
	for(;c>='0'&&c<='9';c=gc()) x=x*10+c-48;
	return f?x:-x;
}int mk[N],nxt[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=10;i<=10000001;i*=10){
		for(int j=7*i/10;j<=10000001;j+=i){
			int mx=j+i/10-1;
			for(int k=j;k<=mx&&k<=10000001;k++) mk[k]=1;
		}
	}for(int i=10000000;i;i--){
		if(!mk[i]) continue;
		for(int j=2;j*i<=10000001;j++) mk[i*j]=1;
	}for(int i=10000000,lst=10000001;i;i--){
		if(!mk[i]) nxt[i]=lst,lst=i;
		else nxt[i]=-1;
	}int T;T=rd();
	while(T--) printf("%d\n",nxt[rd()]);
	return 0;
}
