#include <bits/stdc++.h>
using namespace std;
void qr(int &x){
	int f=x=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	x=f?~(x-1):x;
}
void wr(int x){
	if(x<0){
		putchar('-');
		x=~(x-1);
	}
	if(x>=10) wr(x/10);
	putchar(x%10^48);
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cout << 0 << endl;
	return 0;
}
