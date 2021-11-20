#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int Mxdt=100000,mod=998244353;
char gc(){
	return getchar();static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,a[10005],h[1005],Max;long long ans=1e18,s1[605][50][605],s2[605][50][605];
long long mul(long long x){return x*x;}
long long cal1(long long pre,long long suf,long long v,long long x,long long y){
	long long sum=0;
	for(int i=1;i<=x;++i)sum+=mul(pre+i*v);
	for(int i=1;i<=y;++i)sum+=mul(suf-i*v);
	return sum;
}
long long cal2(long long pre,long long suf,long long v,long long x,long long y){
	return (pre+v+pre+x*v)*x/2+(suf-v+suf-y*v)*y/2;
}
long long Cal1(long long pre,long long x){return mul(pre)*x;}
long long Cal2(long long pre,long long x){return pre*x;}
int cnt=0;
void solve(int now,int pre,int suf,long long sum1,long long sum2){
	if(now==0){
		sum1+=Cal1(pre,h[0]);
		sum2+=Cal2(pre,h[0]);
		sum1-=mul(pre);sum2-=pre;
		ans=min(ans,sum1*n-mul(sum2));
		return;
	}
	for(int i=0;i<=h[now];++i){
		if(now<=50)solve(now-1,pre+1ll*now*i,suf-1ll*now*(h[now]-i),sum1+s1[pre][now][i]+s2[suf][now][h[now]-i],sum2+cal2(pre,suf,now,i,h[now]-i));
		else solve(now-1,pre+1ll*now*i,suf-1ll*now*(h[now]-i),sum1+cal1(pre,suf,now,i,h[now]-i),sum2+cal2(pre,suf,now,i,h[now]-i));
	}
}
int main(){
//	system("fc variance.out variance4.ans");
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=2;i<=n;++i){
		Max=max(Max,a[i]-a[i-1]);++h[a[i]-a[i-1]];
	}
	for(int pre=a[1];pre<=a[n];++pre){
		for(int v=1;v<=50;++v){
			for(int k=1;k<=h[v];++k){
				s1[pre][v][k]=s1[pre][v][k-1]+mul(pre+1ll*k*v);
				s2[pre][v][k]=s2[pre][v][k-1]+mul(pre-1ll*k*v);
			}
		}
	}
	solve(Max,a[1],a[n],mul(a[1])+mul(a[n]),a[1]+a[n]);cout<<ans<<"\n";
	return 0;
}
