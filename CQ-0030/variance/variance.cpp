#include<bits/stdc++.h>
#define RI register int
using namespace std;
const long long N=10005;
template<typename T>
void Read(T &t){
	t=0;
	int f=1;
	char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	while(c>='0'&&c<='9')(t*=10)+=c-'0',c=getchar();
	t*=f;
}
double mymin(double x,double y){
	return x>y?y:x;
}
int n,a[N],b[N],fians=0x3f3f3f3f;
/*struct node{
	int fz,fm;
}zcans,zcn,zca1,zcpj,zcai,zcaj,zcak;
void pjs(){
	double zcans=((n*a[1]-pj)*(a[1]-pj/n)+(n*a[n]-pj)*(a[n]-pj/n)+(n-2)*(n*a[i]+n*a[j]-n*a[k]-pj)*(a[i]+a[j]-a[k]-pj/n));

}*/
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	Read(n);
	for(RI i=1;i<=n;i++){
		Read(a[i]);
	}
	for(RI i=1;i<=n;i++){
		for(RI j=1;j<=n;j++){
			if(j==i)continue;
			for(RI k=1;k<=n;k++){
				if(k==j||k==i)continue;
				double pj=(a[1]+a[n]+(n-2)*(a[i]+a[j]-a[k]));
				///
				double zcans=((n*a[1]-pj)*(n*a[1]-pj)+(n*a[n]-pj)*(n*a[n]-pj)+(n-2)*(n*a[i]+n*a[j]-n*a[k]-pj)*(n*a[i]+n*a[j]-n*a[k]-pj))/n;
				fians=mymin(zcans,fians);
			}
		}
	}
	printf("%d\n",fians);
	return 0;
}
