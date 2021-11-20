#include<bits/stdc++.h>
using namespace std;
int js=0,cs[200005],l[10005],maxn=0;
bool vis[200005];
void find1() {
	js=0;
	for(int i=7; i<=10500; i++) {
		int j=i;
		while(j) {
			int yu=j%10;
			if(yu==7) {
				vis[i]=1;
				cs[++js]=i;
				break;
			} else j/=10;
		}
	}
	for(int i=1; i<=js; i++) {
		int w=cs[i]*2;
		for(; w<=10500; w+=cs[i]) {
			vis[w]=1;
		}
	}
}
void find2() {
	js=0;
	for(int i=7; i<=200010; i++) {
		int j=i;
		while(j) {
			int yu=j%10;
			if(yu==7) {
				vis[i]=1;
				cs[++js]=i;
				break;
			} else j/=10;
		}
	}
	for(int i=1; i<=js; i++) {
		int w=cs[i]*2;
		for(; w<=200010; w+=cs[i]) {
			vis[w]=1;
		}
	}
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&l[i]);
		maxn=max(l[i],maxn);
	}
	if(maxn<=10000) {
		find1();
		for(int i=1; i<=n; i++) {
			int kk=l[i]+1;
			if(vis[l[i]]) {
				puts("-1");
				continue;
			} else {
				while(vis[kk]==1) {	
					kk++;
				}
				printf("%d\n",kk);
			}
		}
	}
    else{
		find2();
		for(int i=1; i<=n; i++) {
			int kk=l[i]+1;
			if(vis[l[i]]) {
				puts("-1");
				continue;
			} else {
				while(vis[kk]) {
					kk++;
					if(!vis[kk]) {
						printf("%d\n",kk);
						break;
					}
				}
			}
		}
	}
}
