#include<bits/stdc++.h>
using namespace std;
long long n,k,dang,bj=0,len;
void her(int x) {
	while(1) {
		if(x%10==7) {
			bj=1;
			break;
		}
		x=x/10;
		if(x<1) {
			break;
		}
	}
}
void himself(int x) {
	dang=x;
	if(x%7==0) {
		bj=1;
	}
	if(bj==0) {
		her(x);
	}
}
void kkk(int x) {
	for(int i=1; i<=sqrt(x); i++) {
		if(x%i==0) {
			himself(x/i);
			himself(i);
		} else {
			continue;
		}
		if(bj==1) {
			break;
		}
	}
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	while(n--) {
		bj=0;
		scanf("%d",&k);
		kkk(k);
		if(bj==1) {
			printf("-1");
			printf("\n");
		} else {
			while(1) {
				k++;
				bj=0;
				kkk(k);
				if(bj==0) {
					printf("%d\n",k);
					break;
				}
			}
		}
	}
	return 0;
}
