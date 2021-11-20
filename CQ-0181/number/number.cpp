#include<bits/stdc++.h>
#define Re register
using namespace std;

const int T = 200005, N = 10000005;

int t, q[T];
int mark[N], ans[N];

inline bool check(int x){
	for( ; x ; ){
		if(x % 10 == 7) return 1;
		x /= 10;
	} return 0;
}

void init(int maxn){
	for(Re int i=1;i<=maxn;++i)
		if( check(i) ) mark[i] = 1;
		
	for(Re int i=1;i<=maxn;++i){
		if( mark[i] == 0 || mark[i] == 2 ) continue;
		for(Re int j=(i<<1);j<=maxn;j=i+j){
			mark[j] = 2;
		}
	}
	
	int las = 10000001;
	for(Re int i=maxn;i>=1;--i)
		if(mark[i] == 0){
			ans[i] = las; las = i;
		}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	scanf("%d",&t);
	
	for(Re int i=1;i<=t;++i)
		scanf("%d",&q[i]);
	
	init( 10000000 );
	
	for(Re int i=1;i<=t;++i){
		if(mark[ q[i] ] == 0) printf("%d\n",ans[ q[i] ]);
		else puts("-1");
	}
	
	return 0;
}
