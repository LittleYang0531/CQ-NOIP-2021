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
const int inf=1e7;
int T,k;
bool p[inf+5];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=inf;++i){
		if(!p[i]){
			int num=i;
			bool flag=0;
			while(num)flag|=num%10==7,num/=10;
			p[i]|=flag;
			if(flag)for(int j=2;j*i<=inf;++j)p[i*j]=1;
		}
	}
	read(T);
	while(T--){
		int x,i;
		read(x),i=x;
		if(p[i])puts("-1");
		else{
			while(p[++i]);
			write(i),putchar('\n');
		}
	}
	return 0;
}
