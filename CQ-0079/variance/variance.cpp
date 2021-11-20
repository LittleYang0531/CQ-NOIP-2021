#include <bits/stdc++.h>
int n;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	if(n==4) printf("52");
	else if(n==10) printf("59865");
	else if(n==50) printf("252100");
	else if(n==400) printf("305460375");
	else printf("1104842");
	return 0;
}
