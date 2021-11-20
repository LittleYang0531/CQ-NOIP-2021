#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
#define rloop(i,from,to) for(int i=(from);i>=(to);--i)
using namespace std;
const int maxd=10,maxn=1e7+2;
int T,x,last_legal,digit[maxd+1],suc[maxn+1];
bool erased[maxn+1];
void read(int &x){
	x=0;
	char t=getchar();
	while(!isdigit(t))t=getchar();
	while(isdigit(t))x=x*10+t-'0',t=getchar();
	return;
}
void write(int x){
	digit[0]=0;
	if(x<0)putchar('-'),x=-x;
	do digit[++digit[0]]=x%10,x/=10;while(x);
	rloop(i,digit[0],1)putchar(digit[i]+'0');
	return;
}
bool check(int x){
	digit[0]=0;
	do digit[++digit[0]]=x%10,x/=10;while(x);
	loop(i,1,digit[0])if(digit[i]==7)return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin),freopen("number.out","w",stdout);
	last_legal=1;
	loop(i,2,maxn){
		if(check(i))loop(j,1,maxn/i)erased[i*j]=true;
		if(!erased[i])suc[last_legal]=i,last_legal=i;
	}
	read(T);
	while(T--)read(x),write(erased[x]?-1:suc[x]),putchar('\n');
	return 0;
}
