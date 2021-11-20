#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
int t,n,m,q;
string a,b;
int aa[10005],bb[10005];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	for(int i=1;i<=t;++i){
	n=read(),m=read(),q=read();
    srand(time(NULL));
    for(int i=1;i<=q;++i){
    	print(rand()%(n*m));
    	putchar('\n');
	  }
	}
	return 0;
}
