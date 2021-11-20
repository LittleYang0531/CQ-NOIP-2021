#include<bits/stdc++.h>
using namespace std;

const int maxn=1e7;

int vis[10000005],T,Nxt[10000005];

template <typename T> inline void read(T &n){
	n=0;T w=1;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}

bool Check(int x){
	int y=x;
	while(y){
		if(y%10==7) return true;
		y/=10;
	}
	return false;
}

void prework(){
	for(int i=2;i<=maxn;i++){
		if(Check(i)){
			for(int j=1;1LL*i*j<=maxn;j++) vis[i*j]=1;
		}
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	prework();
	int last=1;
	for(int i=2;i<=maxn;i++){
		if(!vis[i]){
			Nxt[last]=i;
			last=i;
		}
	}
	read(T);
	while(T--){
		int x;
		read(x);
		if(vis[x]) puts("-1");
		else printf("%d\n",Nxt[x]);
	}
	return 0;
}
