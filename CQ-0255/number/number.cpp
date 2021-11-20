#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x*f;
}
#define wr(x) write(x,false)
void write(int x,bool bk){
	if(x==0&&bk)return;
	write(x/10,true),putchar((x%10)^48);
}
const int MAXX=1e7+1;
bool P[MAXX+5];
int nxt[MAXX+5];
bool f(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
void init(){
	for(int i=1;i<=MAXX;++i){
		if((!P[i])&&f(i)){
			for(int j=i;j<=MAXX;j+=i){
				P[j]=1;
			}
		}
	}
	int now=MAXX;
	for(int i=MAXX;i>=1;--i){
		nxt[i]=now;
		if(P[i]==0)now=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int T=read();
	while(T--){
		int x=read();
		if(P[x])puts("-1");
		else wr(nxt[x]),puts("");
	}
	return 0;
}
