#include <bits/stdc++.h>
using namespace std;
int nex[11000000] , f[11000000] , T , n;
int main()
{
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	for(int i = 1 ; i <= 10000010 ; i++ ) 
	{
		if(f[i]) continue;
		int u = i;
		while(u)
		{
			if(u % 10 == 7) f[i] = 1;
			u /= 10;
		}
		if(!f[i]) continue;
		for(int j = i ; j <= 10000010 ; j += i ) f[j] = 1;
	}
	int las = 0;
	for(int i = 1 ; i <= 10000010 ; i++ )
	{
		if(!f[i])
		{
			for(int j = las ; j < i ; j++ ) nex[j] = i;
			las = i;
		}
	}
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n);
		if(f[n]) printf("-1\n");
		else printf("%d\n" , nex[n]);
	}
	return 0;
}
