#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const int maxn=10005;
int n;
double pj;
double fc;
long long ans=100000005;
int a[maxn];
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(NULL));
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	int tot=0;
	for(int t=1;t<=6800000;t++){  
		int k=rand()%(n-2)+2;               //RP++!
		fc=0;
		a[k]=a[k+1]+a[k-1]-a[k];
		int tot=0;
		for(int i=1;i<=n;++i) tot+=a[i];
		pj=1.0*tot/n;
		for(int i=1;i<=n;++i){
			fc+=(a[i]-pj)*(a[i]-pj)*n;
		}
		ans=min(ans,(long long)fc);
	}
	print(ans);
	/*int tot=0;
	for(int i=1;i<=tot;++i) tot+=a[i];
	pj=1.0*tot/n;
	for(int t=1;t<=1000;++t){
		for(int i=2;i<=n-1;++i){
			if(pj-(a[i+1]+a[i-1]-a[i])<pj-a[i]) pj=(pj*n+(a[i+1]+a[i-1]-a[i]-a[i]))/n,a[i]=a[i+1]+a[i-1]-a[i];
		}
		for(int i=1;i<=n;++i) fc+=(a[i]-pj)*(a[i]-pj)*n;
		ans=min(ans,fc);
	}*/
	return 0;
}
