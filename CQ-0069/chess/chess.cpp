#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int rd(){
	int x=0,f=1;char c=gc();
	for(;c>'9'||c<'0';c=gc()) if(c=='-') f=0;
	for(;c>='0'&&c<='9';c=gc()) x=x*10+c-48;
	return f?x:-x;
}vector<char>v1[N],v2[N];
vector<int>mp1[N],mp2[N],vis[N];
struct node{int x,y,tp,frm;};
int n,m,Q;queue<node>q;
int hx[4]={0,0,1,-1},hy[4]={1,-1,0,0};
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int T=rd();
	while(T--){
		n=rd(),m=rd(),Q=rd();
		for(int i=0;i<=n;i++) v1[i].clear(),v2[i].clear(),mp1[i].clear(),mp2[i].clear(),vis[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=1;j<m;j++){
				char c=gc();
				while(c>'9'||c<'0') c=gc();
				v1[i-1].push_back(c);
			}mp1[i-1].resize(m+1),mp2[i-1].resize(m+1);vis[i-1].resize(m+1);
		}for(int i=1;i<n;i++){
			for(int j=1;j<=m;j++){
				char c=gc();
				while(c>'9'||c<'0') c=gc();
				v2[i-1].push_back(c);
			}
		}for(int i=1;i<=Q;i++){
			int col=rd(),lv=rd(),x=rd(),y=rd();
			x--,y--;int cnt=0;
			q.push((node){x,y,-1,0});
			while(!q.empty()){
				int xx=q.front().x,yy=q.front().y;
				int tp=q.front().tp,frm=q.front().frm;q.pop();
				if(vis[xx][yy]==i) continue;
				vis[xx][yy]=i;cnt++;
				if(tp==0) continue;
				if(mp1[xx][yy]) continue;
				for(int j=0;j<4;j++){
					if(tp!=-1&&!(frm==(1<<(j>>1)))) continue;
					int dx=xx+hx[j],dy=yy+hy[j];
					if(dx<0||dy<0||dx>n-1||dy>m-1||vis[dx][dy]==i) continue;
					int nxt=-1;
					if(j==0) nxt=v1[xx][yy]-'0';
					if(j==1) nxt=v1[dx][dy]-'0';
					if(j==2) nxt=v2[xx][yy]-'0';
					if(j==3) nxt=v2[dx][dy]-'0';
					if(mp1[dx][dy]){
						if(mp1[dx][dy]==col) continue;
						if(mp2[dx][dy]>lv) continue;
						if(tp==-1||tp==nxt) q.push((node){dx,dy,nxt,j>>1});
					}else if(tp==-1||tp==nxt) q.push((node){dx,dy,nxt,j>>1});
				}
			}printf("%d\n",cnt-1);
			mp1[x][y]=col?col:-1;
			mp2[x][y]=lv;
		}
	}return 0;
}
