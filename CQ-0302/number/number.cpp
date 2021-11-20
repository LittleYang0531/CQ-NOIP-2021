#include<bits/stdc++.h>
using namespace std;
const int M=1e7+1e6+1,N=1e7+1,MAX=0x7fffffff/2;
int t,x;
int Max,num;
int q[M];
bool n[M];
int check(int a) {
	int num=0;
	while (a!=0) {
		num=a%10;
		a=a/10;
		if(num==7) return 1;
	}
	return 0;
}
void st(int a) {
	for(int i=1; i<=a; i++) {
		if(n[i]==1) continue;
		if(check(i)) {
			for(int j=1; i*j<=a; j++) {
				n[i*j]=1;
			}
		}
	}
}
void st1(int a) {//Ê§°Ü 
	for(int i=2;i<=a;i++) {
		if(check(i)) n[i]=1,q[++num]=i;
	}
	for(int i=2;i<=a;i++) {
		for(int j=1;j<=num&&i*q[j]<=N;j++) {
			q[++num]=i*q[j];
			n[i*q[j]]=1;
			return ;
		}
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int x[200001];
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%d",&x[i]);
		Max=max(Max,x[i]);
	}
	Max=Max*1.1;
	st(Max);
//	for(int i=165;i<=185;i++) printf("(%d %d) ",q[i],n[i]);
	for(int i=1; i<=t; i++) {
		if(n[x[i]]==1) printf("-1\n");
		else {
			for(int j=x[i]+1; ; j++) if(n[j]==0) {
					printf("%d\n",j);
					break;
				}
		}
	}
	return 0;
}

