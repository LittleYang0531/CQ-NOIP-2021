#include<bits/stdc++.h>
using namespace std;
int T,x,maxval=0;
int q[200010];
int nxt[20000010];
bool banned[20000010];
inline bool check(int x) {
	if (x==0) return 0;
	if (x%10==7) return 1;
	return check(x/10);
}
void work1() {
	for (int i=1;i<=200000;i++) {
		if (check(i)) 
		    for (int j=i;j<=400000;j+=i) banned[j]=1;
	}
	for (int i=400000;i>=1;i--) {
		if (banned[i]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
}
void work2() {
	for (int i=1;i<=10000000;i++) {
		if (check(i)) {
			int up=11000000/i;
		    for (int j=1;j<=up;j++) banned[i*j]=1;
		}
	}
	for (int i=11000000;i>=1;i--) {
		if (banned[i]) nxt[i]=nxt[i+1];
		else nxt[i]=i;
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	for (int i=1;i<=T;i++) {
		scanf("%d",&q[i]);
		maxval=max(maxval,q[i]);
	}
	if (maxval<=200000) work1();
	else work2();
	for (int i=1;i<=T;i++) {
		if (banned[q[i]]) printf("-1\n");
		else printf("%d\n",nxt[q[i]+1]);
	}
	return 0;
}
