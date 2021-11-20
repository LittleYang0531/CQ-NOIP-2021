#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sss=0;
	char chh=getchar();
	while(chh<'0'||chh>'9') chh=getchar();
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int T;
int a[10000011];
bool vis[10000011];
int has[10000011],tot=0;
bool check_base(int i){
	while(i){
		if(i%10==7) return true;
		i/=10;
	}
	return false;
}
void init(int x){
	for(register int i=7;i<=x;i++){
		if(check_base(i)) vis[i]=true;
	}
}
void init_div(){
	for(register int i=1;i<=tot;i++){
		for(register int j=2;j*has[i]<=10000000;j++)
			vis[has[i]*j]=true;
	}
}
int find(int x){
	while(vis[x])x++;
	return x;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init(10000010);
	for(register int i=6;i<=10000010;i++){
		while(!vis[i])i++;
		has[++tot]=i;
	}
	init_div();
	T=read();
	int x;
	while(T--){
		x=read();
		if(vis[x]) puts("-1");
		else {
			write(find(x+1)),puts(""); 
		}
	}
	return 0;
}
/*
这垃圾电脑跑了1.1秒，希望CCF快一点
I love zlj forever!!! 
*/
