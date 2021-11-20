#include<stdio.h>
#include<algorithm>
#define R register int
#define I inline void
#define INF 999999999
I Min(int&x,const int y){
	if(x>y){
		x=y;
	}
}
int f[101][101][4001],a[10001],s[10001],d[10001];
I DFS(int x,int pre,int sum,int cur,const int n,int&ans){
	if(x==n-1){
		cur=cur*n-sum*sum;
		if(cur<ans){
			ans=cur;
		}
	}else{
		int t=a[1]+pre+d[x];
		DFS(x+1,pre+d[x],sum+t,cur+t*t,n,ans);
		t=a[n]-s[x]+pre;
		DFS(x+1,pre,sum+t,cur+t*t,n,ans);
	}
}
I Solve1(int n){
	int ans=INF;
	DFS(1,0,a[1]+a[n],a[1]*a[1]+a[n]*a[n],n,ans);
	printf("%d",ans);
}
I Solve2(int n){
	for(R i=0;i<=n;i++){
		for(R j=0;j<=a[n];j++){
			for(R k=0;k<=n*a[n];k++){
				f[i][j][k]=999999999;
			}
		}
	}
	f[0][0][a[1]+a[n]]=a[1]*a[1]+a[n]*a[n];
	for(R i=1;i!=n-1;i++){
		for(R j=0;j<=a[n];j++){
			for(R k=(i+1)*a[n];k!=-1;k--){
				if(f[i-1][j][k]!=INF){
					int t=a[1]+j+d[i];
					Min(f[i][j+d[i]][k+t],f[i-1][j][k]+t*t);
					t=a[n]-s[i]+j;
					Min(f[i][j][k+t],f[i-1][j][k]+t*t);
				}
			}
		}
	}
	int ans=INF;
	for(R i=0;i<=a[n];i++){
		for(R j=0;j<=n*a[n];j++){
			if(f[n-2][i][j]!=INF){
				Min(ans,f[n-2][i][j]*n-j*j);
			}
		}
	}
	printf("%d",ans);
}
I Solve3(int n){
	long long s2=a[1]*a[1]+a[n]*a[n];
	int s1=a[1]+a[n],pre=0,suf=0,t;
	for(R i=1;i!=n-1;i++){
		if(pre<suf){
			pre+=d[i];
			t=pre+a[1];
		}else{
			suf+=d[i];
			t=a[n]-suf;
		}
		s1+=t;
		s2+=t*t;
	}
	printf("%lld",s2*n-(long long)s1*s1);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(R i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(R i=1;i!=n;i++){
		d[i]=a[i+1]-a[i];
	}
	std::sort(d+1,d+n);
	std::reverse(d+1,d+n);
	for(R i=1;i!=n;i++){
		s[i]=s[i-1]+d[i];
	}
	if(n<21){
		Solve1(n);
	}else if(n<101){
		Solve2(n);
	}else{
		Solve3(n);
	}
	return 0;
}
