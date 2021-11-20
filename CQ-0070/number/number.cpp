#include<bits/stdc++.h>
using namespace std;
bool vis[10000107];
int nxt[10000107];
int v[6000005],top;
int T,N;
int ask[200005];

void getvis(){
	for(int i=1;i<=N;i++){
		int m=i;
		while(m) {
			if(m%10==7) {vis[i]=1,v[++top]=i;break;}
			m/=10;
		}
	}
}

inline int read(){
	int s=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') s=(s<<1)+(s<<3)+c-'0',c=getchar();
	return s;
}

void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	T=read();int Max=0;
	for(int i=1;i<=T;i++) ask[i]=read(),Max=max(Max,ask[i]);
	if(Max<=200000) N=200100;
	else N=10000100;
	
	getvis();
	for(int i=1;i<=top;i++){
		int x=v[i];
		for(int j=x+x;j<=N;j+=x) vis[j]=1;
	}
	
	int lst=N+1;
	for(int i=N;i>=1;i--) {
		if(vis[i]) continue;
		nxt[i]=lst,lst=i;
	}
	
	for(int i=1;i<=T;i++){
		if(vis[ask[i]]) puts("-1");
		else write(nxt[ask[i]]),puts("");
	}
	
	return 0;
}

