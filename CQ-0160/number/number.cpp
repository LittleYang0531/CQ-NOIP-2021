#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool f[10000015];
int q[10000015];
int tot=0;


bool Check(int x){
	while(x){
		int now=x%10;
		x/=10;
		if(now==7) return 1;
	}
	return 0;
}

void SZS(int n){
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		if(Check(i)){
			for(int j=1;j*i<=n;j++){
				int now=i*j;
				f[now]=1;
			}
		}
	}
	for(int i=1;i<=n;i++) if(!f[i]) q[++tot]=i;
}

void File(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}

int main(){
	File();
	SZS(1e7+5);
	int T;cin>>T;
	while(T--){
		int x;scanf("%d",&x);
            int now=lower_bound(q+1,q+tot+1,x)-q;
            if(x!=q[now]) printf("-1\n");
            else printf("%d\n",q[now+1]);
	}
	return 0;
}
/*
2
9999998
9999999
*/
