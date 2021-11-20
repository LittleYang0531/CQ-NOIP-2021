#include<bits/stdc++.h>
#define N 100005
using namespace std;
inline int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void write(int x){
	char f[50];int cnt=0;
	if(!x)
		putchar('0');
	while(x){
		f[cnt++]=x%10+'0';
		x/=10;
	}
	while(cnt)
		putchar(f[--cnt]);
	putchar('\n');
}
bitset<N> vis;
int T,n,m,q,head[N],nxt[N<<2],to[N<<2],lv[N],col[N],ans,t;
char c[N],w[N<<2];
inline void add(int u,int v,char W){
	nxt[++t]=head[u];head[u]=t;to[t]=v;w[t]=W;
	nxt[++t]=head[v];head[v]=t;to[t]=u;w[t]=W;
}
inline int way(int x,int y){
	if(x/m==y/m)
		if(x>y)
			return 0;
		else
			return 1;
	else
		if(x>y)
			return 2;
	return 3;
}
//void dfs(int k,int lev,int color,int d,int s,char flag){
//	for(int i=head[k];i;i=nxt[i])
//		if(w[to[i]]!='0')
//			if(flag=='1'){
//				
//			}
//}
bool flag;
int k,res;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		n=read();m=read();q=read();
		flag=0;
		for(int i=1;i<=n;++i){
			scanf("%s",&c+1);
			for(int j=1;j<m;++j){
				add((i-1)*m+j,(i-1)*m+j+1,c[j]);
				if(c[j]==2||c[j]==3)	
					flag=1;
			}
		}
		for(int i=1;i<n;++i){
			scanf("%s",&c+1);
			for(int j=1;j<=m;++j){
				add((i-1)*m+j,i*m+j,c[j]);
				if(c[j]==2||c[j]==3)
					flag=1;
			}
		}
//		if(flag){
//			while(q--){
//				col[k]=read();lv[k]=read();k=(read()-1)*m+read();
//				ans=0;
//				for(int i=head[k];i;i=nxt[i]){
//					res=0;
//					if(lv[to[i]]){
//						if(col[to[i]]!=col[k]&&lv[to[i]]<=lv[k])
//							res=max(res,1);
//					}
//					else if(w[i]=='1'){
//						dfs(k,l,co,0,0,'1');
//					}
//					else if(w[i]=='2'){
//						dfs(k,l,co,way(k,to[i]),0,'2');
//					}
//					else if(w[i]=='3'){
//						memset(vis,0,sizeof(vis));
//						vis[k]=1;
//						dfs(k,l,co,0,0,'3');
//					}
//				}
//				write(ans);
//			}
//		}
		while(q--){
			if(!flag){
			col[k]=read();lv[k]=read();k=(read()-1)*m+read();
				ans=0;
				for(int i=head[k];i;i=nxt[i])
					if(w[i]!='0'){
						if(lv[to[i]]){
							if(col[to[i]]!=col[k]&&lv[to[i]]<=lv[k])
								ans++;
						}
						else
							ans++;
					}
			write(ans);
		}
		}
	}
	return 0;
}
