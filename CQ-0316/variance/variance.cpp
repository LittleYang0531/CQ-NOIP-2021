#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,cnt,minn=INF;
double Ja;
int a[10005],c[10005];
int SV() {
	int ans=0,ans2=0;
	cnt=0;
	for(int i=1; i<=n; i++) {
		ans=ans+(n-1)*(a[i]*a[i]);
		cnt+=a[i];
	}
	for(int i=1; i<=n; i++) {
		ans2+=a[i]*(cnt-a[i]);
	}
	return ans-ans2;
}
signed main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(unsigned(time(0)));
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		cnt+=a[i];
		c[i]=a[i];
//		sum[i]=sum[i-1]+a[i];
	}
//	Ja=cnt/(double(n));
	for(int i=1; i<=1000; i++) {
		for(int j=1; j<=n; j++) a[j]=c[j];
		for(int j=1; j<=500; j++) {
			int g=rand()%(n-2)+2;
			a[g]=a[g-1]+a[g+1]-a[g];
			int ANS=SV();
			if(minn>ANS) minn=ANS;
		}
	}
	cout<<minn;
	return 0;
}

// CCF 10 年单身换我得分！ 
// ZRF 祝愿我能 rand 出 20~48！ 
