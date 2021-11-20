#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const unsigned int N=10000;
int a[N],n,sum,mid;
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=y;
}
int query(){
	int pjz=0,fc=0;
	for(register int i=1;i<=n;i++)
	pjz+=a[i];
	for(register int i=1;i<=n;i++)
	fc+=(a[i]*n-pjz)*(a[i]*n-pjz);
	return fc/n;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(register int i=1;i<=n;i++){
		read(a[i]);
		sum+=a[i];
	}
	mid=a[1]+a[n]/2;
	//printf("%d\n",query());
	while(true){
		bool flag=false;
		for(register int i=2;i<n;i++){
			int x=a[i+1]+a[i-1]-a[i];
			if(abs(mid-x)<abs(mid-a[i])){
				a[i]=x;
				flag=true;
			}
		}
		if(!flag)
		break;
 }
	printf("%d\n",query());
	return 0;
}
//I'm CQ-00266
//I Will Always Love Xiaoting
//AFOed
