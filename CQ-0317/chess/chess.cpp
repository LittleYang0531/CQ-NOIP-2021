#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d%d%d",&a,&b,&n);
		while(n--){
			cout<<rand()%5<<endl;
		}
	}
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
