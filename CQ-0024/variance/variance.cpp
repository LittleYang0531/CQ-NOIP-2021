#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch){
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
int n,a[Maxx],b[Maxx],c[Maxx];
struct node {
	LL F,Sl,Sr;int l,r;
	inline node(){F=Sl=Sr=0,l=1,r=n-1;}
	inline void Add(LL p,bool op){
		if(op)//(l*Sr+(n-l)*(Sl+p*l)<(n-r)*Sl+r*(Sr+p*(n-r)))
			F+=p*(l*Sr+(n-l)*(Sl+p*l)),Sl+=(c[l]=p)*l*2,++l;
		else F+=p*((n-r)*Sl+r*(Sr+p*(n-r))),Sr+=(c[r]=p)*(n-r)*2,--r;
	}
	inline bool operator < (const node &tp) const {return F<tp.F;}
	inline bool operator == (const node &tp) const {return F<=tp.F&&Sl<=tp.Sl&&Sr<=tp.Sr;}
}P[2333],Q[2333];
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i)b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	int fm=1;P[1]=node();
	for(int i=n-1;i;--i){
		int pd=0;
		for(int j=1;j<=fm;++j){
			Q[++pd]=P[j],Q[pd].Add(b[i],0);
			Q[++pd]=P[j],Q[pd].Add(b[i],1);
		}
		sort(Q+1,Q+pd+1),fm=unique(Q+1,Q+pd+1)-Q-1;
		for(int j=1;j<=fm;++j)P[j]=Q[j];
		fm=min(fm,2330);
	}
	cout<<P[1].F<<"\n";
//	for(int i=1;i<n;++i)cout<<c[i]<<" ";puts("");
//	for(int i=1;i<n;++i)a[i+1]=a[i]+c[i];
//	long long Ans=0,sum=0;
//	for(int i=1;i<=n;++i)Ans+=a[i]*a[i],sum+=a[i];
//	cout<<Ans*n-sum*sum<<"\n";
	//(c[i]*c[j])*min(i,j)*min(n-i,n-j)
	return 0;
}
//21 16 7 1 1 0 13 15 19
//59865
//252100
//305460375

