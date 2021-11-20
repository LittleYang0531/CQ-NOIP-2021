#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
bool ppp;
const int N=3e5+9;
const int lim=3e5+9;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int sa[30],tp;
void write(int x){
	if(x<0){putchar('-'),x=-x;}
	if(!x){putchar('0');return;}
	while(x)sa[++tp]=x%10,x/=10;
	while(tp){putchar(sa[tp]+'0');tp--;}
	return;
}
int T,n,m,q,col,lv,cnt,tag;
char s[lim];
vector<int>R[lim],D[lim];
int vis[lim*21];
int used[lim*10];
int had[lim*10];
bool check(int x,int y){
	if(x>n||x<1||y>m||y<1)return false;
	return true;
}
int POS(int x,int y){return (x-1)*m+y;}
int id(int x,int y,int op,int way){
	return ((x-1)*m+y)+((op-1)*4+(way+1))*n*m;
}
void dfs(int x,int y,int op,int way){//1普通 2直行 3任意 
	if(had[POS(x,y)]){
		if(col*had[POS(x,y)]>0)return;//同色 
		if(lv<abs(had[POS(x,y)]))return;//等级小 
	}
	if(used[POS(x,y)]!=tag)cnt++,used[POS(x,y)]=tag;
	if(vis[id(x,y,op,way)]!=tag)vis[id(x,y,op,way)]=tag;
	else return;
	if(had[POS(x,y)])return;
	if(op==1)return;//只能走一步 
	int tx=0,ty=0,w=0;
	if(op==2){
		switch(way){
			case 0:goto xia;
			case 1:goto zuo;
			case 2:goto shang;
			case 3:goto you;
		}
	}
	xia:
		tx=x+1,ty=y;
		if(check(tx,ty)){
			w=D[x][y];  if((op==-1||w==op)&&w){
				dfs(tx,ty,w,0);
			}
		}if(op==2)return;
	zuo:
		tx=x,ty=y-1;
		if(check(tx,ty)){
			w=R[tx][ty];if((op==-1||w==op)&&w){
				dfs(tx,ty,w,1);
			}
		}if(op==2)return;
	shang:
		tx=x-1,ty=y;
		if(check(tx,ty)){
			w=D[tx][ty];if((op==-1||w==op)&&w){
				dfs(tx,ty,w,2);
			}
		}if(op==2)return;		
	you:
		tx=x,ty=y+1;
		if(check(tx,ty)){
			w=R[x][y];  if((op==-1||w==op)&&w){
				dfs(tx,ty,w,3);
			}
		}if(op==2)return;
}
bool pppp;
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc chess3.ans chess.out");
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	T=read();
	while(T-->0){
		n=read(),m=read(),q=read();
		memset(had,0,sizeof had);
		rep(i,n)R[i].resize(m);
		rep(i,n)D[i].resize(m);
		rep(i,n){scanf("%s",s+1);rep(j,m-1)R[i][j]=s[j]-'0';}
		rep(i,n-1){scanf("%s",s+1);rep(j,m)D[i][j]=s[j]-'0';}
		while(q--){
			col=read(),lv=read();if(col==0)col=-1;
			int x=read(),y=read();
			++tag;cnt=0;dfs(x,y,-1,0);
			had[POS(x,y)]=col*lv;
			write(cnt-1);puts("");
		}
	}
	return 0;
}

