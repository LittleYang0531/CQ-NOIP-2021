#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull mod=100000007,jz=37;
priority_queue<int >Q;
inline int read(){
	int x=0,f=0;
	char p=getchar();
	while (p<'0'||p>'9')f|=(p=='-'?1:0),p=getchar();
	while(p>='0'&&p<='9')x=(x<<3)+(x<<1)+(p^48),p=getchar();
	return f?-x:x;
}
inline void print(int x){
	if (x>9)print(x/10);
	putchar(x%10+'0');
}
int a[1004],n,has[mod+10];
inline ull ha(){
	ull r=7;
	for (ull i=1;i<=n;i++)r=r*jz%mod+1ull*a[i]%mod;
	return r%mod;
}
inline int fc(){
	int sum=0,sums=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	for(int i=1;i<=n;i++)sums+=(n*a[i]-sum)*(n*a[i]-sum);
	return sums/n;
}
inline void search(){
	if (has[ha()])return;
	Q.push(-fc()),has[ha()]=1;
	for (int i=2;i<n;i++){
		int t=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		search();
		a[i]=t;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	search();
	print(-Q.top());
	return 0;
}
