#include<bits/stdc++.h>
#define C(i,j) ((i-1)*m+j)
using namespace std;
const int N=2e5+5,M=4e5+5;
int T,n,m,idx,q,c,l,ans;
char s[N],as[N],bs[N];
int co[N],lv[N],vis[N];
int cnt,Last[N],Next[M],End[M];
void add(int x,int y){
	End[++cnt]=y;
	Next[cnt]=Last[x];
	Last[x]=cnt;
}
void dfs(int x){
	vis[x]=1;
	for(int i=Last[x],y;i;i=Next[i])
	if(vis[y=End[i]]!=1){
		if(co[y]){
			if(co[y]!=c&&lv[y]<=l)ans++;
			continue;
		}
		ans++;dfs(y);
	}
}
void xxx(){
	memset(co,0,sizeof co);
	memset(lv,0,sizeof lv);
	memset(Last,0,sizeof Last);cnt=0;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=2;j<=m;j++){
			if(s[j-1]=='3'){
				add(C(i,j),C(i,j-1));
				add(C(i,j-1),C(i,j));
			}
			as[C(i,j-1)]=s[j-1];
		}
	}
	for(int i=2;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++){
			if(s[j]=='3'){
				add(C(i,j),C(i-1,j));
				add(C(i-1,j),C(i,j));
			}
			bs[C(i-1,j)]=s[j];
		}
	}
	for(idx=1;idx<=q;idx++){
		int x,y;ans=0;
		memset(vis,0,sizeof vis);
		scanf("%d%d%d%d",&c,&l,&x,&y);
		co[C(x,y)]=c+1;lv[C(x,y)]=l;
		if(y<m&&as[C(x,y)]=='1'){
			if(co[C(x,y+1)]!=c&&lv[C(x,y+1)]<=l)ans++;
		}
		if(y<m&&as[C(x,y)]=='2'){
			for(int i=y+1;i<=m;i++){
				if(as[C(x,i-1)]!='2')break;
				if(co[C(x,i)]){
					if(co[C(x,i)]!=c&&lv[C(x,i)]<=l)ans++;
					break;
				}
				ans++;
			}
		}
		if(y>1&&as[C(x,y-1)]=='1'){
			if(co[C(x,y-1)]!=c&&lv[C(x,y-1)]<=l)ans++;
		}
		if(y>1&&as[C(x,y-1)]=='2'){
			for(int i=y-1;i>=1;i--){
				if(as[C(x,i)]!='2')break;
				if(co[C(x,i)]){
					if(co[C(x,i)]!=c&&lv[C(x,i)]<=l)ans++;
					break;
				}
				ans++;
			}
		}
		if(x<n&&bs[C(x,y)]=='1'){
			if(co[C(x+1,y)]!=c&&lv[C(x+1,y)]<=l)ans++;
		}
		
		if(x<n&&bs[C(x,y)]=='2'){
			for(int i=x+1;i<=n;i++){
				if(bs[C(i-1,y)]!='2')break;
				if(co[C(i,y)]){
					if(co[C(i,y)]!=c&&lv[C(i,y)]<=l)ans++;
					break;
				}
				ans++;
			}
		}
		if(x>1&&bs[C(x-1,y)]=='1'){
			if(co[C(x-1,y)]!=c&&lv[C(x-1,y)]<=l)ans++;
		}
		if(x>1&&bs[C(x-1,y)]=='2'){
			for(int i=x-1;i<=n;i++){
				if(bs[C(i,y)]!='2')break;
				if(co[C(i,y)]){
					if(co[C(i,y)]!=c&&lv[C(i,y)]<=l)ans++;
					break;
				}
				ans++;
			}
		}
		dfs(C(x,y));printf("%d\n",ans);
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for(scanf("%d",&T);T--;)xxx();
	return 0;
}
