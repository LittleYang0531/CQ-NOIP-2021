#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
const int N=12000001;
bool ppp;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int sa[30],tp;
void write(int x){
	if(x<0){putchar('-'),x=-x;}
	if(!x){putchar('0');return;}
	while(x)sa[++tp]=x%10,x/=10;
	while(tp){putchar(sa[tp]+'0');tp--;}
	return;
}
int T,n;
bool check(int x){
	while(x){if(x%10==7)return true;x/=10;}
	return false;
}
bool vis[N];
int nt[N];
void init(){
	rep(i,11000000)if(!vis[i]){
		if(check(i)){
			for(int j=1;j*i<N;j++)
				vis[j*i]=1;
		}
	}
	int pre=0;
	Rof(i,11000000,1)if(!vis[i]){nt[i]=pre,pre=i;}
}
bool pppp;
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc number.out number4.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();init();
	while(T--){
		n=read();
		if(vis[n])puts("-1");
		else {write(nt[n]);puts("");}
	}
	return 0;
}

