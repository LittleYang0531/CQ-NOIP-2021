#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll N;
ll fz1;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&N);
	for(int i=1;i<=N;i++){
		ll a;
		scanf("%lld",&a);
		fz1+=a;
	}
	printf("%lld",fz1*N);
	return 0;
}
// fc chess.out chess3.ans
