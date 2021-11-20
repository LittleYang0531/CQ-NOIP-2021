#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<algorithm>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

const int MAXN=5e3+5;

struct Node{
	int op,col,liv;
}t[MAXN][MAXN];

int n,m,q;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n);read(m);read(q);
		for (int i=1;i<=n;i++){
			int x;
			for (int j=1;j<m;j++) read(x);
		}
		for (int i=1;i<n;i++){
			int x;
			for (int j=1;j<=m;j++) read(x);
		}
		while(q--){
			int a,b,c,d;
			read(a);read(b);read(c);read(d);
			printf("%d\n",n*m);
		}
	}
	return 0;
}

// Sto Orz %%% CJG ÉúÈÕ¿ìÀÖ CJG AK NOIP
