#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;

int to[N];
bool p[N];
bool flag[N];
int pw[10];
int T,x;

int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

bool check(int x){
	for(int i=0;i<=7;++i){
		if(x/pw[i]%10==7)return 1;
	}
	return 0;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	pw[0]=1;
	for(int i=1;i<=7;++i)pw[i]=pw[i-1]*10;
	for(int i=1;i<=210000;++i){
		p[i]=check(i);
		int len=sqrt(i);
		for(int j=2;j<=len;++j){
			if(i%j!=0)continue;
			p[i]|=p[j]|p[i/j];
		}
	}
	for(int i=201000;i>=1;--i){
		if(p[i+1]==0)to[i]=i+1;
		else to[i]=to[i+1];
		
	}
	T=read();
	while(T--){
		x=read();
		if(p[x]){
			printf("-1\n");
			continue;
		}
		printf("%d\n",to[x]);
	}
	return 0;
}
