#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
#define N 10000005
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int T,vst[N],sum[N];
bool check(int x) {
	while(x) {
		if(x%10 == 7)return 1;
		x /= 10;
	}return 0;
}
void init(int n) {
	for(int i=7; i<=n; ++i)if(!vst[i] && check(i)) {
		for(int j=i; j<=n; j+=i)vst[j] = 1;
	}
	for(int i=1; i<=n; ++i)sum[i] = sum[i-1]+(!vst[i]);
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("number");
	init(10000001);
	read(T);
	while(T--) {
		int x;read(x);
		if(sum[x]-sum[x-1] == 0)puts("-1");
		else {
			int l = x+1,r = 10000001,mid,rec = -1;
			while(l <= r) {
				mid = l+r>>1;
				if(sum[mid]-sum[x] >= 1)rec = mid,r = mid-1;
				else l = mid+1;
			}
			cout << rec << '\n';
		}
	}
}
