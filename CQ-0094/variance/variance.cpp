/*Don't want to say anything*/

#include <iostream>
#include <cstdio>

using namespace std;

int readInt()
{
	bool neg = 0;
	int num = 0;
	
	char c = getchar();
	
	while(c==' ' || c=='\n')	c = getchar();
	while(c == '-')	neg = !neg,	c = getchar();
	while(c>='0' && c<='9')	num += (num<<1) + (num<<3) + c - '0',	c = getchar();
	
	return neg ? -num : num;
}

const int N = 1e4 + 2;

int n;
int a[N];

int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n = readInt();
	
	for(int i=1; i<=n; ++i)
		a[i] = readInt();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
