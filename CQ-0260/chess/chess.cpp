#include<iostream>
#include<windows.h>
using namespace std;
int T,n,m,q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>q;
		int cnt=n*m-q+n+m;
		while(q--){
			srand(cnt);
			cnt=rand()%(cnt+1)+1; 
	 		cout<<cnt<<endl;
		}
	}
	return 0;
}
