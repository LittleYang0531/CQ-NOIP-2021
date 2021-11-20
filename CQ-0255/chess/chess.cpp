#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x*f;
}
#define wr(x) write(x,false)
#define gc(x) while(x=getchar(),x=='\n'||x==' ')
void write(int x,bool bk){
	if(x==0&&bk)return;
	write(x/10,true),putchar((x%10)^48);
}
const int MX=2e5+5,dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int n,m;
struct P{
	int x,y;
	P(int o=0):x(o/m),y(o%m){}
	inline int D(){return x*m+y;}
};
P mp(int x,int y){P res;res.x=x,res.y=y;return res;}
struct lt{
	int x,t;
};
int to[MX*4],wp[MX*4],nxt[MX*4],hd[MX],cnt=0;
void ae(int u,int v,int w){
	nxt[++cnt]=hd[u];
	to[cnt]=v;
	wp[cnt]=w;
	hd[u]=cnt;
}
lt a[MX];
int bk[MX];
int finturn(P st,P ed){
	for(int i=1;i<=4;++i){
		if(st.x+dx[i]==ed.x,st.y+dy[i]==ed.y)return i;
	}return 0;
}
int bfs(P s,int b){
	bk[s.D()]=b;
	int ans=0;
	queue<lt>Q;
	for(int i=hd[s.D()];i;i=nxt[i]){
		if(wp[i]==2)Q.push({to[i],finturn(s,P(to[i]))}),bk[to[i]]=b;
		if(wp[i]==3)Q.push({to[i],0}),bk[to[i]]=b;
		++ans;
	}
	while(Q.size()){
		lt top=Q.front();Q.pop();
		if(top.t==0){
			for(int i=hd[top.x];i;i=nxt[i]){
				if(bk[to[i]]==b)continue;
				if(wp[i]==3)Q.push({to[i],0}),bk[to[i]]=b,++ans;
			}
		}
		else{
			P nxt=P(top.x);
			nxt.x+=dx[top.t],nxt.y+=dy[top.t];
			if(nxt.x==0||nxt.x==n||nxt.y==0||nxt.y==m||bk[nxt.D()]==b)continue;
			if(a[nxt.D()].t==-1)Q.push({nxt.D(),top.t}),++ans,bk[nxt.D()]=b;
			else{
				if(a[nxt.D()].t!=a[s.D()].t&&a[nxt.D()].x<=a[s.D()].x)++ans;
			}
		}
	}
	return ans;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=read();
	while(T--){
		memset(to,0,sizeof to);
		memset(hd,0,sizeof hd);
		memset(wp,0,sizeof wp);
		memset(bk,0,sizeof bk);
		cnt=0;
		n=read(),m=read();
		int q=read();
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j){
				a[mp(i,j).D()].t=-1,a[mp(i,j).D()].x=0;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j){
				char ch;
				gc(ch);
				if(ch!='0')ae(mp(i,j+1).D(),mp(i,j).D(),ch^48),ae(mp(i,j).D(),mp(i,j+1).D(),ch^48);
			}
		}
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j){
				char ch;
				gc(ch);
				if(ch!='0')ae(mp(i+1,j).D(),mp(i,j).D(),ch^48),ae(mp(i,j).D(),mp(i+1,j).D(),ch^48);
			}
		}
		for(int i=1;i<=q;++i){
			int col=read(),lv=read(),x=read(),y=read();
			a[mp(x,y).D()]={lv,col};
			wr(bfs(mp(x,y),i)),putchar('\n');
		}
	}return 0;
}
