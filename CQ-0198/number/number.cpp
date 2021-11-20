#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 10000000
inline void read(int &x) {
	x=0;
	int f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1;
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	c*=f;
}
inline void write(ll x) {
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
bool vis[10000005];
int can[1000005], cnt=0;
bool cheak(int x) {
	while(x) {
		if(x%10==7) return 0;
		x/=10;
	}
	return true;
}
void yc() {
	for(int i=1; i<=maxn; ++i) {
		if(!vis[i]) {
			if(cheak(i)) {
				can[++cnt]=i;
			} else {
				for(ll j=2; i*j<=maxn; ++j) {
					vis[i*j]=1;
				}
			}
		}
	}
	can[++cnt]=10000001;
}
int find(int x) {
	int l=1, r=cnt, mid;
	while(l<=r) {
		mid=(l+r)/2;
		if(can[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main() {
//	cout << sizeof(can)*1.0/1024/1024;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int t;
	yc();
//	cout << cnt << endl;
//	cout << can[cnt];
//	return 0;
//	for(int i=1; i<=cnt; ++i){
//		printf("%d ", can[i]);
//	}
//	return 0;
	read(t);
	int x, tmp;
	while(t--) {
		read(x);
		tmp=find(x);
		if(can[tmp]!=x) {
			putchar('-');
			putchar('1');
			putchar('\n');
		} else {
			write(can[tmp+1]);
			putchar('\n');
//			printf("%d\n", can[tmp+1]);
		}
	}
	return 0;
}
