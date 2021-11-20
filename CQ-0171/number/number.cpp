#include<bits/stdc++.h>
using namespace std;
const int M=10000000;
int t,s,a,cnt=0;
char f[30];
bitset<10000005> vis;
bool flag;
inline int read(){
	int x=0,f=1;char ch=getchar();
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
void write(int x){
	cnt=0;
	if(x<0) putchar('-'),x=-x;
	if(x==0){
		putchar('0');
		putchar('\n');
		return;
	}
	while(x){
		f[++cnt]=x%10+'0';
		x/=10;
	}
	while(cnt) putchar(f[cnt--]);
	putchar('\n');
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	for(int i=1;i<=M;i++){
		if(vis[i]) continue;
		if(i%7==0) for(int j=i;j<=M;j+=i) vis[j]=1;
		else{
			a=i;
			flag=0;
			while(a){
				if(a%10==7){
					flag=1;
					break;
				} 
				else a/=10;
			}
			if(flag) for(int j=i;j<=M;j+=i) vis[j]=1;
		}
	}
	for(int i=1;i<=t;i++){
		s=read();
		if(vis[s]) write(-1);
		else{
			s++;
			while(vis[s]) s++;
			write(s);
		} 
	}
	return 0;
}
