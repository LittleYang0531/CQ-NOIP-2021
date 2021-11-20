#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10005
#define LL long long
#define ENDL putchar('\n')
#define DB double
#define lowbit(x) (-(x) & (x))
#define FI first
#define SE second
LL read() {
	LL f = 1,x = 0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s = getchar();}
	while(s >= '0' && s <= '9') {x = (x<<1) + (x<<3) + (s^48);s = getchar();}
	return f*x;
}
void putpos(LL x) {if(!x)return ;putpos(x/10);putchar((x%10)^48);}
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) putchar('-'),x = -x;
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

int n,m,s,o,k;
int a[MAXN],b[MAXN];
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i ++) {
		a[i] = read();
		if(i > 1) b[i-1] = a[i]-a[i-1];
	}
	sort(b + 1,b + n);
	LL ans = 1e18;
	for(int A = a[1]*3;A <= a[n]*3;A ++) {
		LL cna = a[1]+a[n],cn2 = a[1]*a[1] + a[n]*a[n];
		DB av = A/3.0;
		DB ct1 = av-a[1],ct2 = a[n]-av;
		int c1 = a[1],c2 = a[n];
		for(int i = n-1;i > 1;i --) {
			if(ct1 > ct2) {
				c1 += b[i]; ct1 -= b[i];
				cna += c1; cn2 += c1*c1;
//				printf("%d\n",c1);
			}
			else {
				c2 -= b[i]; ct2 -= b[i];
				cna += c2; cn2 += c2*c2;
//				printf("%d\n",c2);
			}
		}
//		printf("cna: %lld   cn2: %lld\n",cna,cn2);
		ans = min(ans,cn2*n - cna*cna);
	}
	AIput(ans,'\n');
	return 0;
}
