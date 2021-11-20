#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define int long long
#define inf 0x7fffffff/2
using namespace std;
int T;
int bn[500005],bn1[2000005];
int cnt=0,cnt1=0;
int ycl() {
	for (int i=1; i<=500005; ++i) {
		int ts=i;
		bool bj=false,bj2=false;
		while (ts!=0) {
			if (ts%10==7) {
				bn[++cnt]=i;
				bj2=true;
				break;
			}
			ts/=10;
		}
	}
	for (int i=1; i<=20005; ++i) {
		for (int j=1; j<=100; ++j) {
			bn1[++cnt1]=bn[i]*j;
		}
	}
	for (int i=1; i<=10000; ++i) {
		bn1[++cnt]=7*i;
	}
	for (int i=2; i<=50; ++i) {
		for (int j=1; j<=1000; ++j) {
			bn1[++cnt1]=bn[i]*j;
		}
	}
	sort(bn1+1,bn1+1+520500);
	for (int i=1; i<=cnt1; ++i) {
		if (bn1[i]==bn1[i+1]) {
			bn1[i]=inf;
		}
	}
	sort(bn1+1,bn1+1+520500);
}
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&T);
	ycl();
	for (; T; --T) {
		int n;
		bool bj=false;
		scanf("%lld",&n);
		for (int i=1; i<=cnt; ++i) {
			if (n==bn[i]) {
				bj=true;
				puts("-1");
				break;
			}
			if (bn[i]>n) break;
		}
		if (bj==true) continue;
		int rj=0;
		for (int i=1; i<=cnt1; ++i) {
			if (n==bn1[i]) {
				bj=true;
				puts("-1");
				break;
			}
			if (bn1[i]>n) {
				rj=i;
				break;
			}
		}
		if (bj==true) continue;
		n+=1;
		for (int i=1; i<=cnt; ++i) {
			if (bn[i]==n) {
				n++;
			}
			if (bn1[rj]<n) rj++;
			if (bn1[rj]==n) {
				n++;
			}
		}
		printf("%lld\n",n);
	}
	return 0;
}
//I am AKed NOIP
// sto crn & gyh orz
