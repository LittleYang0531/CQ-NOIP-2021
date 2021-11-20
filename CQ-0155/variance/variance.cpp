#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#define int long long
using namespace std;

const int N = 10005;
class Ayaka{
	public:
		int num[N];
		int sum;
		Ayaka(){
			memset(num,0,sizeof(num));
			sum = 0;
		}
		Ayaka(int *tmp,int sum_=0):sum(sum_){
			memcpy(num,tmp,sizeof(num));
		}
}; 
unordered_map<int,bool> b;
int a[N];
int n;

namespace stb1{
	int ans = 0x3f3f3f3f3f3f3f3f;
	inline int getdis(int *num){
		double tmp = 0;
		for(int k=1;k<=n;k++)
			tmp += num[k];
		tmp /= n;
		double res = 0;
		for(int k=1;k<=n;k++)
			res += (num[k]-tmp)*(num[k]-tmp);
		res *= n;
		ans = min(ans,(int)res);
		return (int)res;
	}
	inline void bfs(){
		queue<Ayaka> q;
		int tmp = getdis(a);
		q.push(Ayaka(a,tmp));
		b[tmp] = true;
		while(q.size()){
			auto u = q.front();
			q.pop();
			for(int k=2;k<n;k++){
				int ttmp = u.num[k];
				u.num[k] = u.num[k+1]+u.num[k-1]-u.num[k];
				tmp = getdis(u.num);
				if(!b[tmp]){
					b[tmp] = true;
					q.push(u);
				}
				u.num[k] = ttmp;
			}
		}
	}
	int main(){
		bfs();
		printf("%lld",ans);
		return 0;
	}
}

signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int k=1;k<=n;k++)
		scanf("%lld",a+k);
	if(n<=20){
		stb1::main();
		return 0;
	}
	return 0;
}
