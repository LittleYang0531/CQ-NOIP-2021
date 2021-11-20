#include<bits/stdc++.h>
#define N 5005
#define P 779
#define mod 998244353
typedef long long ll;
using namespace std;
int n,a[N],b[N],c[N],p[N],pw[N],used[N],ans=0x3f3f3f3f,dlt;
vector<int>v,g[N];
unordered_map<int,int>mp;
//bitset<500005>f;
inline void Calc(void){
	int i,x=0,s=0,ss=0,s1=0,s2=0;vector<int>v1,v2,v;
	for(i=2;i<=n;++i)if(!p[i])v1.push_back(c[i]),s1+=c[i];else v2.push_back(c[i]),s2+=c[i];
	sort(v1.begin(),v1.end()),reverse(v1.begin(),v1.end()),sort(v2.begin(),v2.end());
	v.push_back(c[1]);for(i=0;i<v1.size();++i)v.push_back(v1[i]);for(i=0;i<v2.size();++i)v.push_back(v2[i]);
	for(i=1;i<=n;++i)x+=v[i-1],s+=x,ss+=x*x;
	ans=min(ans,n*ss-s*s);
}
inline void dfs(int x){
	int i;
	if(x>n)return Calc();
	p[x]=1,dfs(x+1);
	p[x]=0,dfs(x+1);
}
//inline void Try(int x,int s,int prt){
//	if(!s)return Calc();
//	for(int y:g[s])if(!p[y])p[y]=1,Try(x+1,s-c[y],s),p[y]=0;
//}
int main(void){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int i,j,s=0,ss=0,now=0;scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),c[i]=a[i]-a[i-1],s+=c[i];s-=c[1];dlt=s;
	if(n<=20){
		dfs(2);
		printf("%d\n",ans);
		return 0;
	}
//	for(f[0]=1,i=2;i<=n;++i)f=f|f<<c[i];
//	for(i=0;i<=s;++i)if(f[i])dlt=min(dlt,abs((s-i)-i));
//	now=(s-dlt)/2;
//	f.reset();f[0]=1;
//	for(i=2;i<=n;++i){
//		ss+=c[i];
//		for(j=ss;j>=c[i];--j){if(f[j-c[i]])g[j].push_back(i),f[j]=1;}
//	}
//	Try(1,now,now);
//	printf("%d\n",ans);
//	dfs(2);
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99
*/

