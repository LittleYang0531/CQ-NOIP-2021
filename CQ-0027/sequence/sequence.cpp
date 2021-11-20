//ayanami保佑，狗妈保佑，MDR保佑，M99保佑，克爹保佑
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
#define gc getchar
long long getint(){
	long long ret=0;bool flg=0;
	char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-')flg=1;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		ret=(ret<<3)+(ret<<1)+(c^48);
		c=gc();
	}
	return flg?-ret:ret;
}
void pc(char c){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=c;
}
void wrt(long long x){
	if(x<0)pc('-'),x=-x;
	if(x==0)return pc('0');
	int c[48]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
const int mod = 998244353;
int MOD(int x){return x>=mod?x-mod:x;}
int n,m,k,val[105],ans;
int Ct(int x){int ret=0;while(x)++ret,x-=(x&(-x));return ret;}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=getint(),m=getint(),k=getint();
	for(int i=0;i<=m;i++)val[i]=getint();
	if(m<=12){
		static int f[35][30*(1<<12)+5];
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int S=0;S<=n*(1<<m);S++){	
				for(int j=0;j<=m;j++){
					if(S>=(1<<j)&&f[i-1][S-(1<<j)])
						f[i][S]=MOD(f[i][S]+1ll*f[i-1][S-(1<<j)]*val[j]%mod);
				}
			}
		}
		for(int S=0;S<=n*(1<<m);S++)
			if(Ct(S)<=k)ans=MOD(ans+f[n][S]);
		cout<<ans<<"\n";
		exit(0);
	}
	if(k==1){
	}
	if(n==5){
	}
	fwrite(wb,1,p2,stdout);
	return 0;
}

