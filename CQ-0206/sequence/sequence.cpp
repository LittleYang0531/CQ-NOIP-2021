#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 111;
const int mod = 998244353;

void file(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}
int read(){
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

int v[N],a[N],tong[N],jc[N],invj[N];
int n,m,k,ans=0;

int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		a=a*a%mod,b>>=1;
	}
	return res;
}
int count(int x){
	int res=0;
	while(x)res+=x&1,x>>=1;
	return res;
}
int C(int n,int m){
	return jc[n]*invj[m]%mod*invj[n-m];
}
int calc(){
	int s=0,val=1;
	memset(tong,0,sizeof(tong));
	for(int i=1;i<=n;++i)
		s+=(1<<a[i]),tong[a[i]]++,
		(val*=v[a[i]])%=mod;
	int cnt=0;
	for(int i=0;i<=m;++i)if(cnt+tong[i]!=n)
		(val*=C(n,tong[i]))%=mod,cnt+=tong[i];
	return (count(s)<=k)*val;
}
void dfs(int pos,int last){
	if(pos==n+1)return (ans+=calc())%=mod,void();
	for(int i=last;i<=m;++i)a[pos]=i,dfs(pos+1,i),a[pos]=0;
}

void subtask1(){
	dfs(1,0);
	printf("%lld\n",ans);
}

signed main(){
	file();
	srand(time(0));
	n=read(),m=read(),k=read();
	for(int i=jc[0]=1;i<=100;++i)jc[i]=jc[i-1]*i%mod;
	invj[100]=ksm(jc[100],mod-2);
	for(int i=99;~i;--i)invj[i]=invj[i+1]*(i+1)%mod;
	for(int i=0;i<=m;++i)v[i]=read();
	subtask1();
	//else printf("%lld\n",rand()%mod);
	return 0;
}
