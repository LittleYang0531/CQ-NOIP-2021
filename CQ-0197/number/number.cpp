#include <bits/stdc++.h>

using std :: upper_bound;

const int siz_1 = 1e7 + 10;

int T;
int num[siz_1],l;
bool p[siz_1];

bool P (int);

int main () {
   	freopen ("number.in","r",stdin);	
   	freopen ("number.out","w",stdout);
    
    for (int i = 1;i < siz_1;++ i) {
		if (! (P (i) || p[i])) num[++ l] = i;
		else {
			p[i] = true;
			for (int j = 2;i * j < siz_1;++ j) p[i * j] = true;
		}
	}
    
    scanf ("%d",&T);
    
    while (T --) {
		int x;
		scanf ("%d",&x);
		if (p[x]) printf ("-1\n");
		else {
			x = * upper_bound (num + 1,num + 1 + l,x); 
			printf ("%d\n",x);
		}
	}
    
	return 0; 
}

bool P (int n) {
	while (n) {
		if (n % 10 == 7) return true;
		n /= 10;
	}
	return false;
}
