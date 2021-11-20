#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=3e7+7,M=2e5+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;(ch>'9'||ch<'0');ch=getchar()) if(ch=='-') f=-1;
	for(;(ch>='0'&&ch<='9');ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
bool fl[N];
int ans[M];
struct edg{
	int qr,idx;
}e[M];
int m,ma,l;
int qu[M],r;
inline int cmp(edg l,edg r){
	return l.qr<r.qr;
}
inline int check(int now){
	if(fl[now]) return 1;
	if(now%7==0) return 1;
	while(now!=0){
		if(now%10==7) return 1;
		now/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	m=read();
	for(int i=1;i<=m;++i) {
		e[i].idx=i,e[i].qr=read();
		if(e[i].qr>ma) ma=e[i].qr;
	}
	l=1;
	for(int i=1;;++i){
		fl[i*7]=1;
		if(i*7>ma) break;
	}
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=ma;++i){
		if(check(i)){
			if(i%7!=0&&fl[i]==0) {
				for(int t=1;;++t){
					fl[t*i]=1;
					if(t*i>ma) break;
				}
			}
			while(e[l].qr==i) ans[e[l].idx]=-1,++l;
		}
		else{
			while(r!=0){
				ans[qu[r]]=i;
				--r;
			}
			while(e[l].qr==i){
				qu[++r]=e[l].idx,++l;
			}
		}
	}
	for(int i=ma+1;;++i){
		if(check(i)==0){
			while(r!=0){
				ans[qu[r]]=i;
				--r;
			}
			break;
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
