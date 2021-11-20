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
typedef long long LL;

template<typename T>inl void exg(T &x,T &y){ x^=y^=x^=y; }
template<typename T>inl void chkmn(T &x,const T &y){ (x>y) && (x=y); }
template<typename T>inl void chkmx(T &x,const T &y){ (x<y) && (x=y); }

const int maxn=1e4+5;
int n;
LL ans=1e18;
vi a;
set<LL>st;

LL Trans(vi x){
	LL ans=0;
	rep(i,0,n-1) ans=ans*40+x[i];
	return ans;
}
void DFS(const vi &a){
	LL tmp1=0,tmp2=0;
	rep(i,0,n-1) tmp1+=a[i]*a[i],tmp2+=a[i];
	chkmn(ans,n*tmp1-tmp2*tmp2);
	rep(i,1,n-2){
		vi b=a;
		b[i]=b[i+1]+b[i-1]-b[i];
		const LL y=Trans(b);
		if(!st.count(y)) st.insert(y),DFS(b);
	}
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	a.resize(n);
	rep(i,0,n-1) scanf("%d",&a[i]);
	st.insert(Trans(a));
	DFS(a);
	printf("%lld\n",ans);
	return 0;
}
