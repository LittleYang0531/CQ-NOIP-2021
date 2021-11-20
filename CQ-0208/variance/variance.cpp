#include<bits/stdc++.h>
#define INF 0x7fffffff/2
#define js() ((3*b[1]-b[2]-b[3]-b[4])*(3*b[1]-b[2]-b[3]-b[4])+(3*b[2]-b[1]-b[3]-b[4])*(3*b[2]-b[1]-b[3]-b[4])+(3*b[3]-b[2]-b[1]-b[4])*(3*b[3]-b[2]-b[1]-b[4])+(3*b[4]-b[2]-b[1]-b[3])*(3*b[4]-b[2]-b[1]-b[3]))/4
using namespace std;
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while('0'<=ch&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*w;
}
int n;
int a[10005],b[10005];
int smin=INF;
inline void make(){
	int pj=0,sum=0;
	for(int i=1;i<=n;i++)pj+=b[i];
	//cout<<pj<<endl;
	for(int i=1;i<=n;i++){
		sum+=(b[i]*n-pj)*(b[i]*n-pj);
		//cout<<(b[i]*n-pj)*(b[i]*n-pj)<<" ";
	}	
	//cout<<endl<<sum<<endl;
	smin=min(smin,sum);
}
inline void dfs(int x){
	if(x>n){
		make();
		return;
	}
	dfs(x+1);
	if(x>1&&x<n&&b[x]!=b[x-1]+b[x+1]-b[x]){
		b[x]=b[x-1]+b[x+1]-b[x];
		dfs(x+1);
	}
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		b[i]=a[i];
	}
	if(n==1){
		puts("0");
		return 0;
	}
	if(n==2){
		printf("%d",(a[1]-a[2])*(a[1]-a[2]));
		return 0;
	}
	if(n==3){
		int sum1=((2*b[1]-b[2]-b[3])*(2*b[1]-b[2]-b[3])
					+(2*b[2]-b[1]-b[3])*(2*b[2]-b[1]-b[3])
					+(2*b[3]-b[2]-b[1])*(2*b[3]-b[2]-b[1])
					)/3;
		b[2]=b[1]+b[3]-b[2];
		int sum2=((2*b[1]-b[2]-b[3])*(2*b[1]-b[2]-b[3])
					+(2*b[2]-b[1]-b[3])*(2*b[2]-b[1]-b[3])
					+(2*b[3]-b[2]-b[1])*(2*b[3]-b[2]-b[1])
					)/3;
		printf("%d",min(sum1,sum2));
		return 0;
	}
	if(n==4){
		int sum=js();
		smin=min(sum,smin);
		b[2]=a[1]+a[3]-a[2];
		sum=js();
		b[2]=a[2];
		smin=min(sum,smin);
		b[3]=a[2]+a[4]-a[3];
		sum=js();
		b[3]=a[3];
		smin=min(sum,smin);
		b[2]=a[1]+a[3]-a[2];b[3]=a[1]+a[4]-a[2];
		sum=js();
		b[2]=a[2],b[3]=a[3];
		smin=min(sum,smin);
		b[2]=a[1]+a[4]-a[3];b[3]=a[2]+a[4]-a[3];
		sum=js();
		smin=min(sum,smin);
		printf("%d",smin);
		return 0;
	}
	dfs(1);
	cout<<smin/4;
	return 0;
}
