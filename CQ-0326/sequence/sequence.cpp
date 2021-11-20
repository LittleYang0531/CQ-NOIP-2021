#include <iostream>
#include <cstdio>
using namespace std;
inline int rd()
{
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')
	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
int n,m,k,v[105],sum[105];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=rd(),m=rd(),k=rd();
	sum[0]=1;
	for(int i=1;i<=m+1;i++)
		v[i]=rd();
//	if(k==1){
//		for(int i=1;i<=n;i++)
//		{
//			
//		}
//	}
	return 0;
}
