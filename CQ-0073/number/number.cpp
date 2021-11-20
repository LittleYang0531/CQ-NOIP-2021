#include<bits/stdc++.h>
using namespace std;
typedef long long van;
template<typename T> inline
void read(T& x) {
	T f=1,b=0;char ch=getchar();
	while (!isdigit(ch)) {
		if (ch=='-') f=-1;
		ch=getchar();
	} while (isdigit(ch))
		b*=10,b+=ch^'0',ch=getchar();
	x=f*b;return;
}
template<typename T> inline
void print(T x) {
	if (x<0) putchar('-'),x=-x;
	if (x>9) print(x/10);putchar(x%10^'0');
}
bool ppppp;
const van MaxX=2e7+10;
bool access[MaxX];
van fa[MaxX];
bool pppppp;
bool check(van x) {
	while (x) {
		if (x%10==7) return true;
		x/=10;
	} return false;
}
van getfa(van x) {return fa[x]==x?x:fa[x]=getfa(fa[x]);}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	van T;read(T);
	for (int i=1;i<=2e7;i++) {
		if (access[i]) continue;
		if (check(i)) for (int j=i;j<=2e7;j+=i) {
			access[j]=true;
		}
	} for (int i=0;i<=2e7;i++) fa[i]=i;
	for (int i=1;i<=2e7;i++) if (access[i]) fa[getfa(i)]=getfa(i+1);
	for (int tt=1;tt<=T;tt++) {
		van n;read(n);
		if (access[n]) {
			print(-1),putchar('\n');
			continue;
		}
		print(getfa(n+1)),putchar('\n');
	}
	return 0;
}

