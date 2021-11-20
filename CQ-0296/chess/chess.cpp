#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9') c=getchar();
	while(c>='0' and c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x*f;
}
struct node{int col,lv,h;}t[maxn][maxn];
int T;
int n,m,q;
int poi[maxn][maxn],num[maxn][maxn],opt[maxn][maxn],vst[maxn][maxn];
void common(int x,int y){ //普通 
	for(int i=x-1;i>=1;i--){ //上 
		bool flag=false;
		for(int j=x-1;j>=i+1;j--) if(t[j][y].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[i][y]]==1) if(t[i][y].h==0 or (t[i][y].col!=t[x][y].col and t[i][y].lv<=t[x][y].lv)) vst[i][y]=1;
	}
	for(int i=x+1;i<=n;i++){ //下 
		bool flag=false;
		for(int j=x+1;j<=i-1;j++) if(t[j][y].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[i][y]]==1) if(t[i][y].h==0 or (t[i][y].col!=t[x][y].col and t[i][y].lv<=t[x][y].lv)) vst[i][y]=1;
	}
	for(int i=x-1;i>=1;i--){ //左 
		bool flag=false;
		for(int j=x-1;j>=i+1;j--) if(t[x][j].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[x][i]]==1) if(t[x][i].h==0 or (t[x][i].col!=t[x][y].col and t[x][i].lv<=t[x][y].lv)) vst[x][i]=1;
	}
	for(int i=x+1;i<=m;i++){ //右 
		bool flag=false;
		for(int j=x+1;j<=i-1;j++) if(t[x][j].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[x][i]]==1) if(t[x][i].h==0 or (t[x][i].col!=t[x][y].col and t[x][i].lv<=t[x][y].lv)) vst[x][i]=1;
	}
}
void straight(int x,int y,int k){ //直行 
	for(int i=x-1;i>=1;i--){ //上 
		bool flag=false;
		for(int j=x-1;j>=i+1;j--) if(t[j][y].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[i][y]]==1) if(t[i][y].h==0 or (t[i][y].col!=t[x][y].col and t[i][y].lv<=t[x][y].lv)) vst[i][y]=1;
	}
	for(int i=x+1;i<=n;i++){ //下 
		bool flag=false;
		for(int j=x+1;j<=i-1;j++) if(t[j][y].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[i][y]]==1) if(t[i][y].h==0 or (t[i][y].col!=t[x][y].col and t[i][y].lv<=t[x][y].lv)) vst[i][y]=1;
	}
	for(int i=x-1;i>=1;i--){ //左 
		bool flag=false;
		for(int j=x-1;j>=i+1;j--) if(t[x][j].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[x][i]]==1) if(t[x][i].h==0 or (t[x][i].col!=t[x][y].col and t[x][i].lv<=t[x][y].lv)) vst[x][i]=1;
	}
	for(int i=x+1;i<=m;i++){ //右 
		bool flag=false;
		for(int j=x+1;j<=i-1;j++) if(t[x][j].h==1){flag=true;break;}
		if(flag==true) continue;
		if(opt[num[x][y]][num[x][i]]==1) if(t[x][i].h==0 or (t[x][i].col!=t[x][y].col and t[x][i].lv<=t[x][y].lv)) vst[x][i]=1;
	}
}
void supper(int x,int y){ //互通 
	
}
void work(int x,int y){
	common(x,y);
	for(int i=1;i<=4;i++) straight(x,y,i);
	supper(x,y);
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T--){
		n=read(); m=read(); q=read();
		int cnt=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) num[i][j]=++cnt;
		for(int i=1;i<=n;i++) for(int j=1;j<=m-1;j++) opt[num[i][j]][num[i][j+1]]=int(getchar()-'0');
		for(int i=1;i<=n-1;i++) for(int j=1;j<=m;j++) opt[num[i][j]][num[i+1][j]]=int(getchar()-'0');
		while(q--){
			int a,b,x,y;
			a=read(); b=read(); x=read(); y=read();
			t[x][y].col=a,t[x][y].lv=b,t[x][y].h=1;
			work(x,y);
			cnt=0;
			for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(vst[i][j]) cnt++;
			printf("%d\n",cnt);
		}
	}	
}
