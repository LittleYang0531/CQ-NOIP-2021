#include<iostream>
#include<cstdio>
using namespace std;
int t;
bool mo[10000001];
void init() {
	for(int j=0; j<=999999; j++) {
		int ij=j*10+7;
		if(mo[ij]) continue;
		for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
	}
	for(int j=0; j<=99999; j++) for(int k=1; k<=9; k++) {
			int ij=j*100+70+k;
			if(mo[ij]) continue;
			for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
		}
	for(int j=0; j<=9999; j++) for(int k=1; k<=99; k++) {
			int ij=j*1000+700+k;
			if(mo[ij]) continue;
			for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
		}
	for(int j=0; j<=999; j++) for(int k=1; k<=999; k++) {
			int ij=j*10000+7000+k;
			if(mo[ij]) continue;
			for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
		}
	for(int j=0; j<=99; j++) for(int k=1; k<=9999; k++) {
			int ij=j*100000+70000+k;
			if(mo[ij]) continue;
			for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
		}
	for(int j=0; j<=9; j++) for(int k=1; k<=99999; k++) {
			int ij=j*1000000+700000+k;
			if(mo[ij]) continue;
			for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
		}
	for(int k=1; k<=999999; k++) {
		int ij=7000000+k;
		if(mo[ij]) continue;
		for(int i=ij; i<=10000000; i+=ij) mo[i]=1;
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	scanf("%d",&t);
	for(int x,i=1; i<=t; i++) {
		scanf("%d",&x);
		if(mo[x]) printf("-1\n");
		else {
			while(mo[++x]);
			printf("%d\n",x);
		}
	}
}
