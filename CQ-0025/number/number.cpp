#include<bits/stdc++.h>
#define I inline
#define R register int
#define ll long long
using namespace std;
const int bufsz=1<<21;
char buf[bufsz],*p1,*p2;
#define GC (p1==p2&&(p2=(p1=buf)+fread(buf,1,bufsz,stdin),p1==p2)?EOF:*p1++)
//#define GC getchar()
I int read()
{
	int x=0;char c=GC;
	while(c<'0'||c>'9')c=GC;
	while(c>='0'&&c<='9')x=x*10+(c^48),c=GC;
	return x;
}
const int N=1e7+3;
bool a[N];
int nxt[N];
void solve()
{
	int n=read();
//	int n;scanf("%d",&n);
	printf("%d\n",a[n]?-1:nxt[n]);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	a[7]=1;
	for(R i=8;i<N;i++)
	{
		if(i%10==7)a[i]=1;
		else a[i]=a[i/10];
	}
	for(R i=N-1;i;i--)
	{
		if(a[i])
		{
			for(R j=i+i;j<N;j+=i)
				a[j]|=1;
		}
	}
//	for(R i=1;i<=100;i++)printf("%d %d\n",i,a[i]);
	for(R i=N-3,j=N-2;i;i--)
	{
		nxt[i]=j;
		if(!a[i])j=i;
	}
	int t=read();
//	cerr<<t<<endl;
//	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}
