#include <bits/stdc++.h>
bool Mark[1000005];
int n,Next[1000005],lst;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1,*p2;
inline int read()
{
	char ch;int x(0);while((ch=gc)<48);
	do x=x*10+ch-48;while((ch=gc)>=48);
	return x;
}
inline bool Check(int x)
{
	while(x) {if(x%10==7) return 1;x/=10;}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(register int i=1;i<=1000000;++i)
		if(Check(i)) for(register int j=i;j<=1000000;j+=i) Mark[j]=i;
	for(register int i=1;i<=1000000;++i) if(!Mark[i]) Next[lst]=i,lst=i;
	n=read();
	for(register int i=1,x;i<=n;++i)
	{
		x=read();
		if(Next[x]) printf("%d\n",Next[x]);
		else printf("-1\n");
	}
	return 0;
}
