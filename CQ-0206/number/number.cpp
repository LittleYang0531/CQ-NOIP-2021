#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+5;

void file(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
}
int read(){
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void write(int x){
	if(!x)return ;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

int prime[300],can[N];
int T,x,cnt,tot;
bool vis[N];

bool check(int x){
	while(x){
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
void mark(){
	for(int i=1;i<N;++i)
		for(int j=1;j<=cnt&&prime[j]*i<N;++j){
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)break;
		}
}

signed main(){
	file();
	for(int i=1;i<N;++i)
		if(check(i))prime[++cnt]=i;
	T=read(),mark();
	for(int i=1;i<N;++i)
		if(!vis[i])can[++tot]=i;
	while(T--){
		x=read();
		if(vis[x])puts("-1");
		else{
			int t=upper_bound(can+1,can+tot+1,x)-can;
			write(can[t]),putchar('\n');
		}
	}
	return 0;
}
