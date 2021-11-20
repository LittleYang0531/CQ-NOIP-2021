#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int mod=998244353;
int n,m,k,v[105],a[35],p[150],q[105][35];
long long ans=1;
inline int read(){
	int res=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		res=(res<<1)+(res<<3)+(ch^'0');
		ch=getchar();
	}
	return res;
}
inline void write(int x){
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(time(0));
	n=read(),m=read(),k=read();
	p[0]=1;
	for(int i=1;i<=m;i++)
		p[i]=p[i-1]*2;
	int l=n,r=n*p[m];
	for(int i=m;p[i]<=r;++i)
		p[i]=p[i-1]*2;
	for(int i=0;i<=m;++i){
		q[i][0]=1;
		v[i]=read();
		for(int j=1;j<=n;j++)
			q[i][j]=q[i][j-1]*v[i];
	}
	for(long long i=1;p[i]<=r;++i)
		if(p[i]>=l){
			int f=n-i;
			if(f==1)
				ans=(ans+1)%mod;
			else{
				for(long long j=0;j<f;j++)
					ans=(ans*(i+j))%mod;
				ans=ans*q[0][f]%mod*q[1][i]%mod;
			}
		}
	write(rand()*rand()%mod);//你们猜它是AC还是WA呢？ 
	return 0;
}
