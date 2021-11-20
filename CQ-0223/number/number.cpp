#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(int x){
	char f[50];int cnt=0;
	if(!x)
		putchar('0');
	while(x){
		f[cnt++]=x%10+'0';
		x/=10;
	}
	while(cnt)
		putchar(f[--cnt]);
	putchar('\n');
}
int T,x,v[5000010],t;
bitset<10000010> c;
int tot;
bool L;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=10000000;++i)
		if(!c[i]){
			x=i;L=0;
			while(x>=10){
				if(x%10==7){
					L=1;
					break;
				}
				x/=10;
			}
			if(x==7||L){
				c[i]=1;
				for(int j=2;j*i<=10000000;++j)
					c[j*i]=1;
				v[++t]=i;
				continue;
			}
		}
	while(T--){
		x=read();
		if(c[x])
			puts("-1");
		else{
			int y=x+1;
			while(c[y])
				++y;
			write(y);
		}
	}
	return 0;
}
