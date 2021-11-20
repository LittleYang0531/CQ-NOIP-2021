/*
可以肯定的是存在一个不依赖值域的O(n^3)做法以及一个依赖值域的做法
~~我肯定想n^3啊~~
我们知道首尾不变
推了个SB式子，先乱搞一下
哦，其实只和所有的a_{i} - a_{i - 1}有关
然后这玩意儿……居然可以瞎调位置？ 
现在就是说一个可以任意交换的 b 数组，求如何分配位置可以使得一个式子的值最小
但是这个也做不来啊
哦，使得生成的a的平均数越接近a_1 + a_n的平均数？ 
*/
#include "bits/stdc++.h"
using namespace std;
const int Len = 1e4 + 5;
const long long Inf = 1e18;
int n,m,a[Len],b[Len],llen,c[Len];
bool cmp(int x,int y){return x > y;}
long long res,suma,Ans,Minn;
long long Calc()
{
	long long pre = a[1];
	for(int i = 1 ; i <= n ; i ++)
	{
		pre += c[i - 1];
		suma += pre;
		res += 1ll * n * pre * pre;
	}
	res -= suma * suma;
	Ans = res;
	res = suma = 0;
	return Ans;
} 
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n); 
	for(int i = 1 ; i <= n ; i ++) 
	{
		scanf("%d",&a[i]);
		if(i >= 2) b[++ llen] = a[i] - a[i - 1];
	}
	sort(b + 1 , b + 1 + llen , cmp);
	//不行了，写随机交换吧
	int l = 0 , r = llen + 1 , opt = 0;
	for(int i = 1 ; i <= llen ; i ++)
	{
		if(!opt) c[++ l] = b[i];
		else c[-- r] = b[i];
		opt ^= 1;
	}
	Minn = Calc();
	int Cha;
	if(n <= 50) Cha = n * 4;
	else Cha = max(1 , 100000000 / n / n / n / 2);
	for(int i = 1 ; i <= Cha ; i ++)
	{
		for(int j = 1 ; j <= llen ; j ++)
			for(int k = j + 1 ; k <= llen ; k ++)
			{
				swap(c[j] , c[k]);
				long long pst = Calc();
				if(pst < Minn) Minn = pst;
				else swap(c[j] , c[k]);
			}
	}
	printf("%lld\n",Calc());
	return 0; 
}
/*
21 16 7 1 1 0 13 15 19
*/
