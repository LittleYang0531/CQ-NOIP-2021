#include <bits/stdc++.h>
using namespace std;
int t,n,m,q,ans;
int col,lv,x,y,cnt=0;
int mapp[101][101];
char rightt[101][101],down[101][101];
struct what{int c,l;}qi[5001];
bool can(int num){//1can,0cant
	if(qi[cnt].c==qi[num].c)return 0;
	if(qi[cnt].l<qi[num].c)return 0;
	return 1;
}
void dfs(int x,int y,char st){
	if(st=='1'){
		if(y!=m&&rightt[x][y]==st&&(!mapp[x][y+1]||can(mapp[x][y+1])))ans++;//right
		if(x!=n&&down[x][y]==st&&(!mapp[x+1][y]||can(mapp[x+1][y])))ans++;//down
		if(y!=1&&rightt[x][y-1]==st&&(!mapp[x][y-1]||can(mapp[x][y-1])))ans++;//left
		if(x!=1&&down[x-1][y]==st&&(!mapp[x-2][y]||can(mapp[x-1][y])))ans++;//up
	}
	if(st=='2'){
		for(int now=y;now<=m-1;now++){//right
			if(rightt[x][now]==st){if(!mapp[x][now+1])ans++;if(can(mapp[x][now+1])){ans++;break;}}
			else break;
		}
		for(int now=x;now<=n-1;now++){//right
			if(down[now][y]==st){if(!mapp[now+1][y])ans++;if(can(mapp[now+1][y])){ans++;break;}}
			else break;
		}
		for(int now=y;now>=2;now--){//left
			if(rightt[x][now-1]==st){if(!mapp[x][now-1])ans++;if(can(mapp[x][now-1])){ans++;break;}}
			else break;
		}
		for(int now=x;now>=2;now--){//up
			if(down[now-1][y]==st){if(!mapp[now-1][y])ans++;if(can(mapp[now-1][y])){ans++;break;}}
			else break;
		}
	}
	if(st=='3'){
		if(y!=m&&rightt[x][y]==st&&(!mapp[x][y+1]||can(mapp[x][y+1]))){ans++;dfs(x,y+1,st);}//right
		if(x!=n&&down[x][y]==st&&(!mapp[x+1][y]||can(mapp[x+1][y]))){ans++;dfs(x+1,y,st);}//down
		if(y!=1&&rightt[x][y-1]==st&&(!mapp[x][y-1]||can(mapp[x][y-1]))){ans++;dfs(x,y-1,st);}//left
		if(x!=1&&down[x-1][y]==st&&(!mapp[x-2][y]||can(mapp[x-1][y]))){ans++;dfs(x-1,y,st);}//up
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(mapp,0,sizeof(mapp));
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++)for(int j=1;j<=m-1;j++)scanf("%s",&rightt[i][j]);
		for(int i=1;i<=n-1;i++)for(int j=1;j<=m;j++)scanf("%s",&down[i][j]);
		while(q--){
			scanf("%d%d%d%d",&col,&lv,&x,&y);
			mapp[x][y]=++cnt;
			qi[cnt].c=col;qi[cnt].l=lv;
			ans=0;
			for(char i='1';i<='3';i++)dfs(x,y,i);
			printf("%d\n",&ans);
		}
	}
	return 0;
}
