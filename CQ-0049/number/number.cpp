#include<bits/stdc++.h>
#define N 11000005
typedef long long ll;
using namespace std;
inline int read(void){
	char opt;int res=0,flag=1;
	while((opt=getchar())<'0'||opt>'9')if(opt=='-')flag=-1;
	while(opt>='0'&&opt<='9')res=res*10+opt-'0',opt=getchar();
	return res*flag;
}
char st;
int n,lim=11000000,nxt[N],p[N],a[200005];
bool sev[N],vis[N];
char ed;
inline void Sieve(void){
	int i,j,t,last;
	for(i=1;i<=lim;++i){sev[i]=(sev[i/10]||(i%10==7));if(sev[i])vis[p[++*p]=i]=1;}
	for(i=2;i<=lim;++i){
		for(j=1;j<=*p&&(t=p[j]*i)<=lim;++j){vis[t]=1;if(!(i%p[j]))break;}
	}
	for(last=0,i=lim;i;--i){nxt[i]=(vis[i])?-1:last;if(!vis[i])last=i;}
}
int main(void){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	cout<<(&st-&ed)/1024/1024;
	int i;scanf("%d",&n);
	Sieve();
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)printf("%d\n",nxt[a[i]]);
	return 0;
}

