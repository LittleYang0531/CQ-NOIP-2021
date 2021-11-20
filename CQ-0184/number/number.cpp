#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e7 + 5;
const int MAX_T = 2e5 + 5;
const int MAX_M = 3e5 + 5;
int T,n,vis[MAX_N],a[MAX_M],b[MAX_M],tot,ans[MAX_T];
struct node{
	int x,id;
}p[MAX_T];
bool cmpx(node a,node b){return a.x<b.x;}
inline int check7(int x){
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=1e7;
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		if(check7(i)){
			for(int j=1;i*j<=n;++j){
				vis[i*j]=1;
			}
		}
	}
	int las=0;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(i-las>=10){
				a[++tot]=las;
				b[tot]=i;
			}
			las=i;
		}
	}
//	printf("%d\n",tot);
	scanf("%d",&T);
	for(int i=1;i<=T;++i) scanf("%d",&p[i].x),p[i].id=i;
	sort(p+1,p+1+T,cmpx);
	int j=1;
	for(int i=1;i<=T;i++){
		if(p[i].x==9999998){
			ans[p[i].id]=10000001;
			continue;
		}
		if(p[i].x==9999999 || p[i].x==10000000){
			ans[p[i].id]=-1;
			continue;
		}
		while(a[j]<p[i].x) j++;
		if(a[j]==p[i].x){
			ans[p[i].id]=b[j];
			j++;
			continue;
		}
		if(vis[p[i].x]){
			ans[p[i].id]=-1;
			continue;
		}
		int x=p[i].x;
		x++;
		while(vis[x]) x++;
		ans[p[i].id]=x;
	}
	for(int i=1;i<=T;i++) printf("%d\n",ans[i]);
	return 0;
}
