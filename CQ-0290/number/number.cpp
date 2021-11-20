#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
//#define int long long
using namespace std;
inline int read() {
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
bool pri[10000001];
bool pd(int x) {
	int w=log(x)/log(10)+1,mod=10,chu=1;
	for(int i=1; i<=w; i++){
		if((int)(x%mod/chu)==7)return 1;
		mod*=10,chu*=10;
	}
	return 0;
}
void sai(int x) {
	for(int i=x; i<=10000000; i+=x)pri[i]=1;
}
void st() {
	for(int i=1; i<=10000000; i++) {
		if(pri[i])continue;
		if(i%7==0) {
			sai(i);
			continue;
		}
		if(pd(i))sai(i);
	}
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	st();
	int t=read();
	while(t--) {
		int x=read();
		if(!pri[x])while(1)
				if(!pri[++x]) {
					printf("%d\n",x);
					break;
				} else;
		else puts("-1");
	}
	return 0;
}
