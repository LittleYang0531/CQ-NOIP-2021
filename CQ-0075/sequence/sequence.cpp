/*
����ֻ��Ҫ֪��ÿһλ����������������ż���ͺ���
�����е�״ѹ���뷨�����о����Ǻܶ�
~~�۰�״ѹ~~
����ֱ�� D ������� a_i Ӧ�÷�Щʲô����
����dp_{i,j,k}��ʾ�������еĵ�i������j��sumΪk�Ļ�
��Ȼ�����Ȼ���Թ���һ�°�j��iȥ�ˣ��������ڵ������ǵð�sum���յ���
Ŷ��50�˲����ˣ�����һ���û�Ż�˼·��ȥ��T3��
����Ŷ�������������ֱ�� D ��������Ψһ����ѹ�ľ���ÿһλ����ż����ѹ��������2^100��Ŷ˼��һ���ܲ���ȡģ��
�о�����������У�����֪����ÿ�����ĸ����ǿ���ֱ����ģ����ǻ���ѹ���������� 
�����ƶ������� nm ���������� DP����������Ĳ��� D ������ķ
���������¿���һ�����ǵ� DP�����������Ȼ��һ��ά�� mul �͵Ķ���
���˸�b���Ȱѱ������ˣ��о�Ӧ�ò��Ǻ��ѵ�һ���� 
��ûʱ���ˣ��� T3 ƭ�� 
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
