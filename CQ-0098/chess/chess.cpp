#include<bits/stdc++.h>
using namespace std;
template<typename F>inline void read(F &n){
	F w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	while("while(while(while(while(...))))"){
		puts("puts(puts(puts(...)))");
	}
	return 0;
}
