#include <bits/stdc++.h>
using namespace std;
int _() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
