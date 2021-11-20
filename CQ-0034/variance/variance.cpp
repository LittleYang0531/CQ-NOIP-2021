#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long llong;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; !isdigit(c); c=getchar())
		if(c == '-') f = -f;
	for(; isdigit(c); c=getchar())
		a = (a*10)+(c^48);
	return a*f;
}
void writeint(unsigned x){
	if(x > 9) writeint(x/10);
	putchar(char((x%10)^48));
}
inline void getMin(llong &x,const llong &y){
	if(y < x) x = y;
}

const int MAXN = 10004;
const int MAXA = 603;
int a[MAXN];

# define sqr(x) llong(x)*(x)
llong dp[MAXA], nxt[MAXA];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n = readint(), lst = readint();
	for(int i=1; i!=n; ++i) // read
		a[i] = readint()-lst, lst += a[i];
	sort(a+1,a+n,greater<int>());
	int max_x = 0, min_x = 0, sum_a = 0;
	rep(i,1,n-1) min_x += a[i]*i, sum_a += a[i];
	max_x = sum_a*n-min_x; // good!
	llong ans = LONG_LONG_MAX;
	const int DP_SIZE = (sum_a+1)<<3;
	const int *end_a = a+n-1;
//	printf("sum_a = %d\n",sum_a);
	rep(x,min_x,max_x){
		memset(dp,0x3f,DP_SIZE);
		dp[0] = sum_a*n-x; dp[0] *= dp[0];
		dp[0] += sqr(x); // 2 endpoints
		int mov = sum_a; // total movement
		for(int *i=a+1; i!=end_a; ++i){
			memset(nxt,0x3f,DP_SIZE);
			int low = (*i)*n-x, hig = (mov-(*i))*n-x;
			rep(j,0,sum_a-mov){ // lower one
				getMin(nxt[j+(*i)],dp[j]+sqr(low));
				getMin(nxt[j],dp[j]+sqr(hig));
				low += n, hig += n;
			}
			mov -= *i, memcpy(dp,nxt,DP_SIZE);
//			printf(">>> i = %d\n",i-a);
//			rep(j,0,sum_a) printf("%lld ",dp[j]);
//			puts("");
		}
		rep(j,0,sum_a) getMin(ans,dp[j]);
//		getchar();
	}
	printf("%lld\n",ans/n);
	return 0;
}

/*

classic conclusion: average is the minimum value point

and it's actually swapping slope!

(S+a)^2 - 2(S+a)x <> (S+b)^2 - 2(S+b)x

a^2 + 2a(S-x) <> b^2 + 2b(S-x)

(a-b)(a+b) <> 2(b-a)(S-x)

assume a < b we have

-(a+b)/2 <> (S-x) which is always less when S > x

--------------------------------------

O(n*a) enumerate x, O(n*a), O(n*a) package

no middle segment, but middle point

*/
