#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAXN 10005
#define pb push_back
#define mkpr make_pair
#define fir first
#define sec second
const LL INF=0x3f3f3f3f3f3f3f3f;
const int mo=998244353;
const int jzm=2333;
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int n,a[MAXN];LL ans;
map<int,bool>mp;
void sakura(){
	int sum=0;
	for(int i=2;i<n;i++)sum=(1ll*jzm*sum+1ll*a[i])%mo;
	if(mp[sum])return ;mp[sum]=1;LL sum1=0,sum2=0;
	for(int i=1;i<=n;i++)sum2+=1ll*a[i]*a[i],sum1+=a[i];
	//for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	ans=min(ans,1ll*n*sum2-sum1*sum1);
	//printf("%lld\n",1ll*n*sum2-sum1*sum1);
	for(int i=2;i<n;i++){
		a[i]=a[i-1]+a[i+1]-a[i];sakura();
		a[i]=a[i-1]+a[i+1]-a[i];
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	ans=INF;sakura();
	printf("%lld\n",ans);
	return 0;
}
