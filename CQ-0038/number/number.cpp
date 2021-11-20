#include<bits/stdc++.h>
#define inl inline 
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define pii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;

template<typename T>inl void exg(T &x,T &y){ x^=y^=x^=y; }
template<typename T>inl void chkmn(T &x,const T &y){ (x>y) && (x=y); }
template<typename T>inl void chkmx(T &x,const T &y){ (x<y) && (x=y); }

const int maxn=1e7+10,N=1e7;
int T,x;
int nxt[maxn];
bool ban[maxn];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	rep(a,0,9) rep(b,0,9) rep(c,0,9) rep(d,0,9) rep(e,0,9) rep(f,0,9) rep(g,0,9)
	    if(!((a ^ 7) && (b ^ 7) && (c ^ 7) && (d ^ 7) && (e ^ 7) && (f ^ 7) && (g ^ 7))){
	    	const int x=a*1000000+b*100000+c*10000+d*1000+e*100+f*10+g;
	    	if(!ban[x] && x) rep(i,1,N/x) ban[x*i]=1;
		}
	per(i,N+5,1) if(!ban[i]) nxt[i-1]=i;
	per(i,N+5,1) if(!nxt[i]) nxt[i]=nxt[i+1];
	while(T--){
		scanf("%d",&x);
		if(ban[x]) puts("-1");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
