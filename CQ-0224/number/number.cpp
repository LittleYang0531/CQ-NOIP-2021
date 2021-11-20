#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e7+10,MAXS = 1e7+8,MAXA = 1e6+10;
int T,n,cnt;
int a[MAX],ans[MAX];
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7) return true;
		x /= 10;
	}
	return false;
}
void write(int x)
{
	if(x<0)
	{
		x = -x;
		putchar('-');
	} 
	if(x>=10) write(x/10);
	putchar(x%10^48);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0,sizeof(a));
	for(int i = 1;i<=MAXS;i++)
	{
		if(a[i]!=0) continue;
		if(check(i))
			for(int j = i;j<=MAXS;j+=i)
				a[j] = -1;
		else 
			ans[++cnt] = i,a[i] = cnt;
	}
	T = read();
	while(T--)
	{
		n = read();
		if(a[n]==-1) write(-1);
		else write(ans[a[n]+1]);
		putchar('\n');
	}
	return 0;
}
