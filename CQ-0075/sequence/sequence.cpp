/*
我们只需要知道每一位和下来是奇数还是偶数就好了
好像有点状压的想法，但感觉不是很对
~~折半状压~~
考虑直接 D 这个序列 a_i 应该放些什么东西
定义dp_{i,j,k}表示对于序列的第i个数放j且sum为k的积
当然这个显然可以滚动一下把j和i去了？不过现在的重心是得把sum给日掉吧
哦有50了不虚了，再想一会儿没优化思路就去日T3了
捶捶哦，这个根本不能直接 D 啊，现在唯一可以压的就是每一位的奇偶但是压出来还是2^100，哦思考一下能不能取模啊
感觉如果不是序列，我们知道了每种数的个数是可以直接算的，但是还是压不下来（（ 
流汗黄豆，这真 nm 得在序列上 DP，但是我真的不会 D 啊，蕾姆
我们再重新考虑一下我们的 DP，这个东西必然是一个维护 mul 和的东西
麻了个b，先把暴力打了，感觉应该不是很难的一道题 
诶没时间了，被 T3 骗了 
*/
#include "bits/stdc++.h"
using namespace std;
const int MOD = 998244353 , Len = 32 , M = 1.3e5 + 5 , MLen = 1e2 + 5;
int n,m,k,v[MLen];
inline void Mod(long long &x){if(x >= MOD) x -= MOD;}
long long dp[Len][M],ans;
int Count(int x)
{
	int rres = 0;
	while(x) 
	{
		if(x % 2 == 1) rres ++;
		x = x >> 1;
	}
	return rres;
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 0 ; i <= m ; i ++) scanf("%d",&v[i]); 
	dp[0][0] = 1;
	int res = (1 << m);
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j <= i * res ; j ++)
		{
			for(int k = 0 ; k <= m ; k ++)
			{
				dp[i + 1][j + (1 << k)] += 1ll * dp[i][j] * v[k] % MOD;
				Mod(dp[i + 1][j + (1 << k)]);
			}
		}
	for(int i = 0 ; i <= n * res ; i ++) 
	{
		if(Count(i) <= k)
		{
			ans += dp[n][i];
			Mod(ans);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
