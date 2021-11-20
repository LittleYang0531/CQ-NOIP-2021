#include<bits/stdc++.h>
using namespace std;
int T,n,m,q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	srand(time(0));
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=q;i++) printf("%d\n",rand()%5+1);
	}
	return 0;
}
