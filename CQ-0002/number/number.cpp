#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,nxt[20000002];
char v[20000002],d[20000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=1e7+1e6,m=1e6+1e5;
	for(re int i=0;i<=n;++i){
		if(v[i]&&!d[i])for(re int j=i;j<=n;j+=i)d[j]=1;
		if(v[i]&&i<=m)for(re int j=i*10;j<i*10+10;++j)v[j]=1;
		else if(i<=m)v[i*10+7]=1;
		v[i]|=d[i];
	}
	for(re int i=n;i;--i){
		if(!v[i])nxt[i]=i;
		else nxt[i]=nxt[i+1];
	}
	t=read();
	while(t--){
		re int x=read();
		if(v[x])puts("-1");
		else printf("%d\n",nxt[x+1]);
	}
}
