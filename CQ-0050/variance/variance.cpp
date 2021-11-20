#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
//#define int __int128
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=1e4+10;
int n,a[N],ans,b[N];
int st[30],tt;
void write(int x){
	if(!x)return putchar('0'),void();
	while(x)st[++tt]=x%10,x/=10;
	while(tt)putchar(st[tt--]^48);
}
int s1,s2;
#define db double
const db delta=0.997;
int SA(){
	int res=1e9;s1=s2=0;For(i,1,n)a[i]=b[i],s1+=a[i],s2+=a[i]*a[i];
	db t=2000;while(t>1e-7){
		int x=rand()%(n-2)+2;
		int val=a[x];a[x]=a[x-1]+a[x+1]-a[x];
		int S1=s1-val+a[x],S2=s2-val*val+a[x]*a[x];
		int now=n*S2-S1*S1,del=res-now;
		if(del>0)res=now,s1=S1,s2=S2;
		else if(rand()<exp(-del/t)*RAND_MAX)s1=S1,s2=S2;
		else a[x]=val;
		t*=delta;
	}
	return res;
}
signed main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	For(i,1,n=read())a[i]=read(),s1+=a[i],s2+=a[i]*a[i],b[i]=a[i];srand(time(NULL));
	ans=n*s2-s1*s1;if(n<=2)return write(ans),0;
//	For(i,1,50000000){
//		int x=rand()%(n-2)+2,val=a[x];
//		a[x]=a[x-1]+a[x+1]-a[x];
//		s1=s1-val+a[x],s2=s2-val*val+a[x]*a[x];
//		ans=min(ans,n*s2-s1*s1);
//	}
	while(1.0*clock()/CLOCKS_PER_SEC<0.9)ans=min(ans,SA());
	write(ans);
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99

59865
*/
