#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
int n,m,K;
//最后留几位放前面进位 
const int mod=998244353;
int f[109][32][32][32];
ll v[109];
ll c[109][109];
ll pw[109][55];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int main(){
//	cout<<sizeof(f)/1024/1024<<"\n";
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	for(int i=0;i<=105;i++)c[i][0]=1;
	for(int i=1;i<=105;i++)
		for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	n=read(),m=read(),K=read();
	for(int i=0;i<=m;i++)
	{
		v[i]=read();
		pw[i][0]=1;
		for(int j=1;j<=50;j++)pw[i][j]=pw[i][j-1]*v[i]%mod;
	}
	for(int i=0;i<=m+6;i++)pw[i][0]=1;
	for(int w=0;w<=n;w++)
		f[0][w][w&1][w]=pw[0][w];
	for(int i=0;i<=m+5;i++)//在m+6位置统计贡献 
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=n;k++)
			{
				for(int s=0;s<=n;s++)
				{
					if(!f[i][j][k][s])continue;
					if(i+1>m)
					{
						int w=0;//只留进位了 
						ad(f[i+1][j+w][k+((s/2+w)&1)][s/2+w],1ll*f[i][j][k][s]*c[j+w][j]%mod*pw[i+1][w]%mod);
					}
					else 
					{
						for(int w=0;w+j<=n;w++)//枚举下一个位置填多少个 
							ad(f[i+1][j+w][k+((s/2+w)&1)][s/2+w],1ll*f[i][j][k][s]*c[j+w][j]%mod*pw[i+1][w]%mod);
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=K;i++)
		ad(ans,f[m+6][n][i][0]);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}
/*
1
9999998
*/
/*IronHeart@413A*/
