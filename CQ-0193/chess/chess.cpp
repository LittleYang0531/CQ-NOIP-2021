#include<bits/stdc++.h>
using namespace std;
struct node{int v,op;};struct node1{int col,lv,op,u;};
map <int,int> Num[200005],Map[200005];
vector <node> road[200005];
char a[200005];
int n,m,q,Have[200005],Cl[200005],Lv[200005],vis[200005],vis1[200005];
void add_edge(int u,int v,int op){road[u].push_back(node{v,op}),Map[u][v]=op;road[v].push_back(node{u,op}),Map[v][u]=op;}
queue <node1> p;
bool check(int i,int j){
	if(Cl[i]!=Cl[j]&&Lv[i]<=Lv[j])return true;
	return false;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    	cin>>n>>m>>q;
    	for(int i=1;i<=n*m;i++)road[i].clear();
    	int tot=0;
    	for(int i=1;i<=200000;i++)Num[i].clear(),Map[i].clear();
		for(int i=1;i<=n;i++)
    	 for(int j=1;j<=m;j++)
    	 	Num[i][j]=++tot,Have[tot]=0,Cl[tot]=0,Lv[tot]=0,vis[tot]=0,vis1[tot]=0;
    	for(int i=1;i<=n;i++){
    		scanf("%s",a);
    		for(int j=m-1;j>=1;j--)a[j]=a[j-1];
    		for(int j=1;j<m;j++)add_edge(Num[i][j],Num[i][j+1],a[j]-'0');
		}
		for(int i=1;i<n;i++){
			scanf("%s",a);
			for(int j=m;j>=1;j--)a[j]=a[j-1];
			for(int j=1;j<=m;j++)add_edge(Num[i][j],Num[i+1][j],a[j]-'0');
		}
		int cl,lv,x,y;
		for(int i=1;i<=q;i++){
			scanf("%d%d%d%d",&cl,&lv,&x,&y);
			p.push(node1{cl,lv,1,Num[x][y]});
			Cl[Num[x][y]]=cl,Lv[Num[x][y]]=lv;Have[Num[x][y]]=1;
			int ans=0;
			if(x>1){
				if(!Have[Num[x-1][y]]||check(Num[x-1][y],Num[x][y])){
					if(Map[Num[x-1][y]][Num[x][y]]==1)vis1[Num[x-1][y]]=i,++ans;
				}
			}
			if(x<n){
				if(!Have[Num[x+1][y]]||check(Num[x+1][y],Num[x][y])){
					if(Map[Num[x+1][y]][Num[x][y]]==1)vis1[Num[x+1][y]]=i,++ans;
				}
			}
			if(y>1){
				if(!Have[Num[x][y-1]]||check(Num[x][y-1],Num[x][y])){
					if(Map[Num[x][y-1]][Num[x][y]]==1)vis1[Num[x][y-1]]=i,++ans;
				}
			}
			if(y<m){
				if(!Have[Num[x][y+1]]||check(Num[x][y+1],Num[x][y])){
					if(Map[Num[x][y+1]][Num[x][y]]==1)vis1[Num[x][y+1]]=i,++ans;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
