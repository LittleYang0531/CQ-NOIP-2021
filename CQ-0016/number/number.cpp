#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MAXN 10001005
#define pb push_back
#define mkpr make_pair
#define fir first
#define sec second
const int lim=10001000;
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int T,nxt[MAXN];
bool oula[MAXN];
void init(){
	for(int i=1;i<=lim;i++){
		if(oula[i])continue;int now=i;bool flag=0;
		while(now&&!flag){flag|=(now%10==7);now/=10;}
		if(!flag)continue;
		for(int j=i;j<=lim;j+=i)oula[j]=1;	
	}
	int las=0;
	for(int i=lim;i>0;i--){nxt[i]=las;if(!oula[i])las=i;}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);init();
	while(T--){
		int x;read(x);
		if(oula[x])puts("-1");
		else printf("%d\n",nxt[x]);
	}
	return 0;
}
