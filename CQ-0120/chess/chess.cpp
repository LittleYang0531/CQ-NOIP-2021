#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t,n,m,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		string a;
		for(int i=1;i<=2*n-1;i++) cin>>a;
		for(int i=1;i<=k;i++){
			int _1,_2,_3,_4;
			scanf("%d%d%d%d",&_1,&_2,&_3,&_4);
		}
		for(int i=1;i<=k;i++) printf("%d\n",rand()%(n*m));
	}
	return 0;
}
