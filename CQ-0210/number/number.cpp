#include <bits/stdc++.h>
#define max(x,y) (x>y?x:y)
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
int zqw,n=0,a[200005],nxt[20000000],pre[20000000];
bool flag[20000000];
bool p(int x){
	while(x) {
		if(x%10==7) return 0;
		x/=10;
	}
	return 1;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	qr(zqw);
	for(int i=1;i<=zqw;i++){
		qr(a[i]);
		n=max(n,a[i]);
	}
	n+=10;
	for(int i=1;i<=n;i++) pre[i]=i-1,nxt[i]=i+1;
	for(int i=7;i<=n;++i){
		if(flag[i]) continue;
		if(p(i)) continue;
		flag[i]=1;
		for(int j=2;j*i<=n;++j){
			flag[j*i]=1;
		}
	}
//	cout << clock() << endl;
	for(int i=1;i<=zqw;i++){
		if(flag[a[i]]) putchar('-'),putchar('1');
		else {
			int next=nxt[a[i]];
			while(flag[next]){
				pre[nxt[next]]=pre[next],nxt[pre[next]]=nxt[next];
				next=nxt[next];
			}
			wr(nxt[a[i]]);
		}
		putchar('\n');
	}
	return 0;
}
