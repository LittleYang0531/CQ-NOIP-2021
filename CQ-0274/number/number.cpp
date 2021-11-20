#include<bits/stdc++.h>
#define N ((int)1e7+2)
using namespace std;
inline int read(){
	int s=0,t=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1),s+=(ch-'0'),ch=getchar();
	return s*t;
}
inline void freo(){freopen("number.in","r",stdin),freopen("number.out","w",stdout);}
bool vis[N],del[N];
int ans[N];
int now,tmp[N],tmpc,len;
inline void dfs(int p,bool fin){
	if(p==len){
		if(fin){
			//cout<<now<<'\n';
			vis[now]=true;
			tmp[++tmpc]=now;
			//printf("%d\n",now);
		}
		return;
	}
	for(int i=(p==1?1:0);i<=9;++i){
		now*=10,now+=i;
		dfs(p+1,fin|(i==7));
		now/=10;
	}
}
//int mx;
inline void pre(){
	for(int i=1;i<=8;++i) len=i,dfs(1,false);
	for(int i=1;i<=tmpc;++i){
		if(del[tmp[i]]) continue;
		for(int j=2;j*tmp[i]<N;++j)
			vis[tmp[i]*j]=del[tmp[i]*j]=true;
	}
	int p=1;
	while(p<N){
		if(vis[p]) ++p;
		else{
			int tp=p+1;
			while(vis[tp]&&tp<N) ++tp;
			ans[p]=tp;
			//if(p<=10000000) mx=max(ans[p],mx);
			p=tp;
		}
	}
}
int T;
signed main(){
	freo();
	pre();
	//cout<<mx<<'\n';
	T=read();
	int x;
	while(T--){
		x=read();
		if(vis[x]) printf("-1\n");
		else printf("%d\n",ans[x]);
	}
return 0;
}
/*
5
90
99
106
114
169
*/
