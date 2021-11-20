#include<bits/stdc++.h>
using namespace std;
#define ll long long

int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}

char a[5005][5005];
char b[5005][5005];

int main(){
	int T=read();cout<<T;
	while(T--){
		int n=read(),m=read(),q=read();
		for(int i=1;i<=n;i++) scanf("%s",a+1);
		for(int i=1;i<=n-1;i++) scanf("%s",b+1);
		
	}
	return 0;
}



/*
Happy birthday,CJG!
It seems that I need to AFO,but it is difficult for me to give up. 
But life is not like a novel, you had to say bye when you failed .

Don't worry!Just think I will never give money to f__king CCF!
*/
