#include<bits/stdc++.h>
using namespace std;
void read(int &x)
{
	x=0;
	int f=1;
	char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-')
		{
			f*=-1;
		}
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=(x*10)+(s-'0');
		s=getchar();
	}
	x*=f;
	return;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	printf("cjgnb\n");
	return 0;
}
