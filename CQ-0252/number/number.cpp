#include <bits/stdc++.h>
using namespace std ;
const int MAXN = 1e7+5+1e4 ;
const int N = 1e6+5 ;
int T,mx,len,top,ti,now,q ;
int sev[MAXN],vis[MAXN],ans[MAXN] ;
inline void read(int &x) {
	x = 0 ;
	char c = getchar() ;
	while(!isdigit(c)) c = getchar() ;
	while(isdigit(c)) x = (x<<1)+(x<<3)+(c^48),c = getchar() ;
}
inline void print(int x) {
	if(x > 9) print(x/10) ;
	putchar(x%10+'0') ; 
}
void find(int x,int f,int s,int k) {
	if(!x) return ;
	for(int i = 0 ; i <= 9 ; ++i ) {
		if((i == 7 || (f+i*s)%7==0 || k) && !vis[f+i*s] && (f+i*s)!=0) sev[++len] = f+i*s,vis[f+i*s]= 1 ;
		if(i == 7) find(x-1,f+i*s,s/10,1) ;
		else find(x-1,f+i*s,s/10,k) ;
	}
}
int main() {
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout) ;
	read(T) ;
	find(7,0,1000000,0) ;
	memset(vis,0,sizeof(vis)) ;
	for(int i = 1 ; i <= len ; ++i )
	{
		if(vis[sev[i]]) continue ;
		for(int j = sev[i] ; j <= MAXN ; j += sev[i] )
			vis[j] = 1 ;	
	}
	for(int i = MAXN ; i >= 0 ; --i )
	{
		ans[i] = now ;
		if(!vis[i]) now = i ;
	}
	while(T--)
	{
		read(q) ;
		if(vis[q]) putchar('-'),putchar('1'),putchar('\n') ;
		else print(ans[q]),putchar('\n') ;
	}
	return 0 ;
}
