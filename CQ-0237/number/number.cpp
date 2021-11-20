#include <cstdio>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define rg register
using namespace std;
const int maxn=10000050;
int a[200001],to[maxn],m;
bool ip[maxn],jz[maxn];
inline int read(){
	rg int x=0;
	rg char p=getchar();
	while (p<'0'||p>'9')p=getchar();
	while(p>='0'&&p<='9')x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return x;
}
inline void print(int x){
	if (x>9)print(x/10);
	putchar(x%10+'0');
}
inline void jzs(int x){
	for (rg int q=10,lq=1;q<=x;q*=10){
		for (rg int k=0;k<=x/q;k++){
			for (rg int j=0;j<lq;j++){
				int qi=k*q+7*lq+j;
				if (qi<=maxn)jz[qi]=1;
			}
		}
		lq=q;
	}
}
inline void sev(int m){
	for (rg int i=7,last=6;i<=m;i++){
		if (jz[i]&&!ip[i])for (rg int k=1;k<=m/i;k++)if (!ip[k])ip[i*k]=1;
		if (ip[i])to[last]=i+1;
		else last=i,to[last-1]=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	rg int t=read();
	for (rg int i=1;i<=t;i++)a[i]=read(),m=max(m,a[i]);
	jzs(min(m*2,maxn));
	sev(min(m*2,maxn));
	for (rg int i=1;i<=t;i++){
		if(ip[a[i]])puts("-1");
		else print(to[a[i]]),putchar('\n');
	}
	return 0;
}
