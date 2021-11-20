#include<bits/stdc++.h>
using namespace std;
long long n,m,k,q[105],ml = 998244353;
bool vis[105];
char as[200],bs[200],cs[200];
long long ans;
stack<int> ls,ly;
void dps(int le){
	if(le == n){
		for(int i = 0;i < 200;i++)
			cs[i] = as[i];
		long long l = 0;
		for(int i = 0;i < 199;i++){
			cs[i+1] += cs[i]/2;
			cs[i] %= 2;
			l += cs[i];
		}
		if(l > k)
			return;
		else{
			l = 1;
			ly = ls;
			while(!ly.empty()){
				l *= q[ly.top()];
				ly.pop();
			}
			ans = (ans+l%ml)%ml;
		}
		return;
	}
	for(int i = 0;i <= m;i++){
		as[i] += 1;
		ls.push(i);
		dps(le+1);
		as[i] -= 1;
		ls.pop();
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 0;i <= m;i++)
		scanf("%lld",&q[i]);
	for(int i = 0;i <= m;i++){
		for(int j = 0;j < 200;j++)
			as[j] = bs[j];
		as[i] = 1;
		ls.push(i);
		dps(1);
		while(!ls.empty())
			ls.pop();
	}
	cout << ans;
	return 0;
}
