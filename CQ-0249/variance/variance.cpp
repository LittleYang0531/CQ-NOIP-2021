#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char c;
	int x=0,f=0;
	c=getchar();
	while(!isdigit(c)){if(c=='-') f=1;c=getchar();}
	while(isdigit(c)){x=x*10+c-48;c=getchar();}
	return f==0?x:-x;
}
void out(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) out(x/10);
	putchar(x%10+'0');
}
signed main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);

	return 0;
}

