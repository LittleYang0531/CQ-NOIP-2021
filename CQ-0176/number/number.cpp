#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
bool mark[N];
int nxt[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T,lst=0,tot=0;
	scanf("%d",&T);
	for(int i=1;i<=1e7+5;i++) {
		bool f=0;
		if(mark[i]) {continue;}
		int x=i;
		while(x) {
			if(x%10==7) {f=1;break;}
			x/=10;
		}
		if(f) {
			mark[i]=1;
			for(int j=i*2;j<=1e7;j+=i) mark[j]=1;
		}
		if(!mark[i]) {nxt[lst]=i;lst=i;}
	}
	while(T--) {
		int x;
		scanf("%d",&x);
		if(mark[x]) printf("-1\n");
		else {
			printf("%d\n",nxt[x]);
		}
	}
	return 0;
}
