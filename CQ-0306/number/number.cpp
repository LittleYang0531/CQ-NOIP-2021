#include<iostream>
#include<cstdio>
#include<cctype>
typedef unsigned ui;
const ui M=1e7+10;
ui n,top,pri[M],pos[M];bool vis[M];ui Ans[M],ans[M];
char buf[1<<21|5],*p=buf;
inline bool check(ui x){
	for(;x;x/=10)if(x%10==7)return true;
	return false;
}
inline void sieve(const ui&M){
	ui i,j,x;
	for(i=2;i<=M;++i){
		vis[i]=check(i);if(!pos[i])pri[pos[i]=++top]=i;
		for(j=1;j<=pos[i]&&(x=i*pri[j])<=M;++j)pos[x]=j;
	}
	for(i=1;i<=top;++i)for(j=1;(x=pri[i]*j)<=M;++j)vis[x]|=vis[pri[i]]|vis[j];
	for(top=0,i=1;i<=M;++i)if(!vis[i])ans[++top]=i;
	for(i=1;i<=top;++i)for(j=ans[i-1];j<ans[i];++j)Ans[j]=ans[i];
}
inline char Getchar(){
	return*p=='\0'&&(std::cin.read(buf,1<<21),0),*p++;
}
inline ui read(){
	ui n(0);char s;while(!isdigit(s=Getchar()));
	while(n=n*10+(s&15),isdigit(s=Getchar()));return n;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
	ui T,n;T=read();sieve(10000005);
	while(T--){
		n=read();
		if(vis[n])std::cout<<"-1\n";
		else std::cout<<Ans[n]<<'\n';
	}
}
