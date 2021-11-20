#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll Mod=998244353;

ll Pow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1) ans*=a,ans%=Mod;
		a*=a,a%=Mod,b>>=1;
	}
	return ans;
}

ll fac[105];
ll inv[105];

void Init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*(i)%Mod;
	inv[n]=Pow(fac[n],Mod-2);
	for(int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%Mod;
}

ll C(ll n,ll m){
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}

void File(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
}

int n,m,k;
int v[105];
ll ans=0;

int a[105];
int tot=0;
bool Check(ll x){
	ll now=0;tot=0;
//	printf("qwq:%d ",x);
	while(x){
		now+=(x&1);
		a[++tot]=(x&1);
		x>>=1;
	}	
//	for(int i=tot;i>=1;i--) printf("%d",a[i]);
//	printf(" %d\n",now<=k);
	return now<=k;
}

void DFS(int x,int tot,ll val,ll qwq,ll fuck){
//	printf("Fuck:%d %d %d %d %d\n",x,tot,val,qwq,fuck);
	if(x==m+1&&tot<n+1) return ;
	if(tot==n+1){
		if(Check(val)) ans+=qwq*fuck%Mod,ans%=Mod;
//		printf("%d %d %d\n",ans,qwq,fuck);
		return ;
	}
	for(int i=tot-1;i<=n;i++){
		ll now=qwq;ll len=i-tot+1;
		ll QwQ=qwq,FUCK=fuck;
		QwQ*=C(n-tot+1,len),QwQ%=Mod;
		FUCK*=Pow(v[x],len);FUCK%=Mod;
		DFS(x+1,i+1,val+len*Pow(2,x),QwQ,FUCK);
	}
}

int main(){
	File();
	Init(100);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++) scanf("%d",&v[i]);
	DFS(0,1,0,1,1);
	cout<<ans<<endl;
	return 0;
}
/*
15 9 50
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 

15 9 100
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 

*/
