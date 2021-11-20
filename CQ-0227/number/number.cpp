#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxm=1e7+1;
const int Maxn=2e5;
bool mark[Maxm+5];
int ans[Maxm+5];
int a[Maxn+5];
int s[10],top;
int T,mx;
inline int read() {
	ri x=0;
	char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57) {
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x;
}
inline void output(int x) {
	if(x<0)putchar('-'),x=-x;
	top=0;
	while(x) {
		s[++top]=x%10;x/=10;
	}
	for(ri i=top;i>=1;i--)putchar(s[i]+48);
	putchar('\n');
}
inline bool judge(int x) {
	while(x) {
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
void calc() {
	for(ri i=1;i<=mx;i++)mark[i]=1; 
	for(ri i=1;i<=mx;i++) {
		if(judge(i)&&mark[i]) {
			for(ri j=i;j<=mx;j+=i)mark[j]=0;
		}
	}
	int now=1;
	for(ri i=1;i<=mx-1;i++) {
		if(!mark[i])ans[i]=-1;
		else {
			while(!mark[now]||now<=i)++now;
			ans[i]=now;
		}
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	mx=0;
	for(ri i=1;i<=T;i++)a[i]=read(),mx=max(mx,a[i]);
	if(mx<=200000)mx=200000+2;
	else mx=10000000+1;
	calc();
	for(ri i=1;i<=T;i++)output(ans[a[i]]);
	return 0;
}

