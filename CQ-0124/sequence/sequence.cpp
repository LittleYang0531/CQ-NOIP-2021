#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline __int128 read(){
	__int128 x=0,f=1;
	char ch=getchar();
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
inline __int128 ksm(__int128 a,__int128 n){
	__int128 ans=1;
	while(n){
		if(n&1) ans*=a;
		n>>=1;
		a*=a;
	}
	return ans;
}
inline void print(__int128 x){
	if(x<0) x=-x,putchar('-');
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
inline __int128 jc(int n){
	__int128 a=1;
	for(int i=2;i<=n;++i){
		a*=i;
	}
	return a;
}
inline __int128 zuhes(__int128 m,__int128 n){
	return (jc(m)/(jc(n)*jc(m-n)));
}
__int128 n,m,k,maxn,cnt,ans;
__int128 scnt;
__int128 v[105],ss[105],er[10005][110],pol[105];
inline __int128 maxp(__int128 a,__int128 b){
	if(a>b) return a;
	else return b;
}
void dfs(__int128 now,__int128 p,__int128 akp){
	if(akp>p||now>n) return;
	if(now==n&&akp==p){
		cnt++;
		for(int i=0;i<=105;++i)
		if(pol[i]) er[cnt][i]=pol[i];
		return;
	}
	for(int i=0;i<=m;++i){
		pol[i]++;
		dfs(now+1,p,akp+ksm(2,i));
		pol[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i) v[i]=read(),maxn=maxp(v[i],maxn);
	for(__int128 i=n;i<=n*ksm(2,m);++i){
		__int128 lo=i,ktot=0;
		while(lo){
			if(lo&1) ktot++;
			lo>>=1;
		}
		if(ktot>k) continue;
		memset(pol,0,sizeof(pol));
		dfs(0,i,0);
	}
	for(int j=1;j<=cnt;++j){
		int poea=1;
		bool flag=0;
	 for(int i=0;i<=105;++i){
	 	//if(er[j][i]) print(i),putchar(' '),print(er[j][i]),putchar('\n');
		if(er[j][i]) flag=1,poea=(poea*ksm(v[i],er[j][i]))%mod;
	 }
	 if(flag)
	    ans=(ans+poea)%mod;
	}
	print(ans);
	return 0;
}
