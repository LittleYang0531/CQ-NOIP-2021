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
const int N=31,M=102,P=998244353;
int C[N][N];
I int add(const int &a,const int &b){return a+b>=P?a+b-P:a+b;}
I void pls(int &a,const int &b){a+=b;if(a>=P)a-=P;}
void init(int n)
{
	for(R i=0;i<=n;i++)
		for(R j=0;j<=i;j++)
			C[i][j]=j?add(C[i-1][j],C[i-1][j-1]):1;
	
//	for(R i=0;i<=n;i++)
//		for(R j=0;j<=i;j++)
//			printf("%d%c",C[i][j]," \n"[j==i]);
}
int f[M][N][N+1][N][N],cs[N],n,m,k;
int main()
{
//	freopen("seq.in","r",stdin);
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	cout<<sizeof(f)/1024/1024<<endl;
	scanf("%d%d%d",&n,&m,&k);
	init(n);
	for(R i=0;i<=m;i++)scanf("%d",cs+i);
	f[m+1][n][0][0][0]=1;
	int h=floor(log2(n))+1,o=1<<h;
	for(R i=m+1;i;i--)
	{
		for(R j=0;j<=n;j++)
		{
			for(R a=0;a<o;a++)
			for(R b=0;b<=n;b++)
			for(R c=0;c<=b;c++)if(f[i][j][a][b][c])
			{
//				printf("! %d %d %d %d %d %d\n",i,j,a,b,c,f[i][j][a][b][c]);
				const ll w=f[i][j][a][b][c];
				for(R u=0,v=1;u<=j;u++,v=1ll*v*cs[i-1]%P)
				{
					int aa=a<<1,bb,cc;
					if(aa&o)bb=b+1,cc=c+1;
					else bb=b,cc=0;
					aa&=o-1;aa+=u;
					if(aa&o)
					{
						if(cc)bb=bb-cc+1,cc=0;
						else bb++,cc++;
						aa&=o-1;
					}
					if(bb<=n)f[i-1][j-u][aa][bb][cc]=(f[i-1][j-u][aa][bb][cc]+C[j][u]*w%P*v)%P;
				}
			}
		}
	}
	int ans=0;
	for(R a=0;a<o;a++)
		for(R b=0;__builtin_popcount(a)+b<=k;b++)
			for(R c=0;c<=b;c++)
				pls(ans,f[0][0][a][b][c]);
	printf("%d\n",ans);
	return 0;
}
