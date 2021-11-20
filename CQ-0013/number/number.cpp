#include<map>
#include<set>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 10001005
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
bool v[MAXN<<1],f[MAXN<<1];
int nx[MAXN];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i = 0;i <= 1000100;i ++) {
		for(int j = 0;j < 10;j ++) {
			v[i*10+j] = v[i];
		}
		v[i*10+7] = 1;
	}
	for(int i = 1;i <= 10001000;i ++) {
		if(v[i]) {
			for(int j = i;j <= 10001000;j += i) {
				f[j] = 1;
			}
		}
	}
	for(int i = 10001000;i > 0;i --) {
		if(!f[i]) nx[i] = i;
		else nx[i] = nx[i+1];
	}
	int T = read();
	while(T --) {
		n = read();
		if(f[n]) AIput(-1,'\n');
		else AIput(nx[n+1],'\n');
	}
	return 0;
}
