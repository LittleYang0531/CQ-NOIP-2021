//_zzi_ orz jzm ppl xez xyx xjx dym zxy wxk llsw they are yyds!!!
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+5;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
bool vis[maxn];
bool check(int n){
	bool flag=0;
	while(n){
		int x=n%10;
		if(x==7){
			flag=1;
			break;
		}
		n/=10;
	}
	return flag;
}
int a[maxn/10];
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	for(int i=1;i<=1e7;i++){
		if(check(i)==1){
			vis[i]=1;
			for(int j=2;i*j<=1e7;j++){
				vis[i*j]=1;
			}
		}
		if(!vis[i]){
			a[++cnt]=i;
		}
	}
	int t=readint();
	while(t--){
		int x=readint();
		if(vis[x]==1){
			puts("-1");
			continue;
		}
		if(x>=9999998){
			puts("10000001");
			continue;
		}
		int pos=upper_bound(a+1,a+cnt+1,x)-a;
		printf("%d\n",a[pos]);
	}
	return 0;
}
