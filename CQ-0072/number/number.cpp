#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e7+105,M=2e5+105;
int ne[N],pd[N],n,a[M];
int re(){
	int a=0,b=0;
	b=getchar();
	while(b>'9' || b<'0') b=getchar();
	a=b-'0';
	b=getchar();
	while(b<='9' && b>='0'){
		a=a*10+b-'0';
		b=getchar();
	}
	return a;
}
void wr(int a){
	if(!a) return;
	wr(a/10);
	putchar(a%10+'0');
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=re();
	int ma=0;
	for(int i=1;i<=n;i++){
		a[i]=re();
		ma=max(ma,a[i]);
	}
	ma+=10;
	for(int i=1;i<=ma;i++){
		if(i%10==7 || ne[i/10]) ne[i]=1;
	}
	for(int i=1;i<=ma;i++){
		if(pd[i] || !ne[i]) continue;
		pd[i]=1;
		for(int j=i;j<=ma;j+=i) pd[j]=1;
	}
	for(int i=ma;i>=1;i--){
		if(!pd[i+1]) ne[i]=i+1;
		else ne[i]=ne[i+1];
	}
	for(int i=1;i<=n;i++){
		if(pd[a[i]]) puts("-1");
		else{
			wr(ne[a[i]]);
			putchar('\n');
		}
	}
	return 0;
}
