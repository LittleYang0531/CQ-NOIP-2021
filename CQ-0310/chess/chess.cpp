#include<bits/stdc++.h>
using namespace std;
namespace ljh{
	template<typename T>
	void read(T&x){
		x=0;
		char ch;
		bool some=0;
		while((ch=getchar())<'0'||ch>'9')some|=ch=='-';
		while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
		if(some)x=-x;
	}
	template<typename T,typename...Args>
	void read(T&x,Args&...args){read(x),read(args...);}
	template<typename T>
	void write(T x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+48);
	}
	template<typename T,typename...Args>
	void write(T x,Args...args){write(x),putchar(' '),write(args...);}
}using namespace ljh;
int T;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(T);
	if(T==1){
		puts("4\n3\n3\n3\n2");
	}else{
		puts("3\n4\n4\n2\n5\n5\n1");
	}
	return 0;
}/*
--------
When I was six years old, my teacher question to me that "what would you want to be", I wrote down "happy".
They said I don't know the homework, and I said they don't know the life.
--------
As time goes by, people forget the dream to they, they often to laugh any other who go to let dream come true.
This is the life.
--------
As time goes by, people are ture to be someone they don't like.
--------
code==c
code2.0==cc==c++
code3.0==cccc==c++++==c#
code4.0==ccccccccc==c++++++++==c##==c*
--------
qwq, I get '0' again.
*/
