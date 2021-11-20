#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

const int MAXN=1e7+5;

int T,x;

int p[MAXN],ans[MAXN];
bitset <MAXN> vis;

bool f(int x){
	while(x){
		if (x%10==7) return 1;
		x/=10;
	}
	return 0;
}

void init(int n){
	for (int i=2;i<n;i++){
		if (f(i)){
			for (int j=i;j<n;j+=i){
				vis[j]=1;
			}
		}
	}
}

void write(int x){
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init(MAXN);
	for (int i=1;i<MAXN;){
		if (vis[i]){
			ans[i]=-1;
			continue;
		}
		int j;
		for (j=i+1;vis[j];j++);
		ans[i]=j;
		for (int k=i+1;k<j;k++) ans[k]=-1;
		i=j;
	}
	read(T);
	while(T--){
		read(x);
		if (ans[x]==-1){
			puts("-1");
			continue;
		}
		write(ans[x]);
		putchar('\n');
	}
	return 0;
}

// Sto Orz %%% CJG ÉúÈÕ¿ìÀÖ CJG AK NOIP
