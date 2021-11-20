//ayanami保佑，狗妈保佑，MDR保佑，M99保佑，克爹保佑
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
#define gc getchar
long long getint(){
	long long ret=0;bool flg=0;
	char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-')flg=1;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		ret=(ret<<3)+(ret<<1)+(c^48);
		c=gc();
	}
	return flg?-ret:ret;
}
void pc(char c){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=c;
}
void wrt(long long x){
	if(x<0)pc('-'),x=-x;
	if(x==0)return pc('0');
	int c[48]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
int n,m,Q,ans;
int _C1[600005],_C2[600005];
int *c1[600005],*c2[600005];
int ID(int x,int y){return (x-1)*m+y;}
int fa[600005];
int get_fa(int x){return x==fa[x]?x:fa[x]=get_fa(fa[x]);}
int get_fa(int i,int j){return get_fa(ID(i,j));}
int vst[600005];
bool check(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}
int col[600005],le[600005],sz[600005];
void dfs0(int x,int y,int C,int L,bool fg){
	if(!check(x,y))return;
	if(col[ID(x,y)]==C)return;
	if(le[ID(x,y)>L])return;
	if(vst[0]!=vst[ID(x,y)])++ans,vst[ID(x,y)]=vst[0];
	if(fg||le[ID(x,y)])return;
	if(check(x+1,y)&&c2[x][y]==1&&x<=n)dfs0(x+1,y,C,L,1);
	if(check(x-1,y)&&c2[x-1][y]==1&&x>=1)dfs0(x-1,y,C,L,1);
	if(check(x,y+1)&&c1[x][y]==1&&y<=m)dfs0(x,y+1,C,L,1);
	if(check(x,y-1)&&c1[x][y-1]==1&&y>=1)dfs0(x,y-1,C,L,1);
}
void dfs1(int x,int y,int C,int L){
	if(!check(x,y))return;
	if(col[ID(x,y)]==C||vst[ID(x,y)]==vst[0])return;
	if(le[ID(x,y)>L])return;
	if(vst[0]!=vst[ID(x,y)])++ans,vst[ID(x,y)]=vst[0];
	if(le[ID(x,y)])return;
	if(check(x+1,y)&&c2[x][y]==3&&x<=n)dfs1(x+1,y,C,L);
	if(check(x-1,y)&&c2[x-1][y]==3&&x>=1)dfs1(x-1,y,C,L);
	if(check(x,y+1)&&c1[x][y]==3&&y<=m)dfs1(x,y+1,C,L);
	if(check(x,y-1)&&c1[x][y-1]==3&&y>=1)dfs1(x,y-1,C,L);
}
int calc1(int x,int y,int C,int L){
	int res=0;
	while(y<m&&c1[x][y]==2){
		if(le[ID(x,y)])return res;
		++y;
		if(!check(x,y)||col[ID(x,y)]==C||le[ID(x,y)]>L)return res;
		if(vst[ID(x,y)]!=vst[0])++res,vst[ID(x,y)]=vst[0];
	}
	return res;
}
int calc2(int x,int y,int C,int L){
	int res=0;
	while(y>1&&c1[x][y-1]==2){
		if(le[ID(x,y)])return res;
		--y;
		if(!check(x,y)||col[ID(x,y)]==C||le[ID(x,y)]>L)return res;
		if(vst[ID(x,y)]!=vst[0])++res,vst[ID(x,y)]=vst[0];
	}
	return res;
}
int calc3(int x,int y,int C,int L){
	int res=0;
	while(x<n&&c2[x][y]==2){
		if(le[ID(x,y)])return res;
		++x;
		if(!check(x,y)||col[ID(x,y)]==C||le[ID(x,y)]>L)return res;
		if(vst[ID(x,y)]!=vst[0])++res,vst[ID(x,y)]=vst[0];
	}
	return res;
}
int calc4(int x,int y,int C,int L){
	int res=0;
	while(x>1&&c2[x-1][y]==2){
		if(le[ID(x,y)])return res;
		--x;
		if(!check(x,y)||col[ID(x,y)]==C||le[ID(x,y)]>L)return res;
		if(vst[ID(x,y)]!=vst[0])++res,vst[ID(x,y)]=vst[0];
	}
	return res;
}
int _gc(){
	int c=gc();
	while(c<'0'||c>'3')c=gc();
	return c^48;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int Ti=getint();
	while(Ti--){
		memset(sz,0,sizeof(sz));
		for(int i=1;i<=600000;i++)col[i]=le[i]=sz[i]=0;
		int st=1;
		n=getint(),m=getint(),Q=getint();
		for(int i=1;i<=n;i++){
			c1[i]=_C1+st-1,st+=(m+2);
			for(int j=1;j<m;j++)c1[i][j]=_gc();
			for(int j=1;j<m;j++)
				if(c1[i][j]=='3')fa[get_fa(i,j+1)]=get_fa(i,j);
		}
		for(int i=1;i<n;i++){
			c2[i]=_C2+st-1,st+=(m+2);
			for(int j=1;j<=m;j++)c2[i][j]=_gc();
			for(int j=1;j<=m;j++)fa[get_fa(i+1,j)]=get_fa(i,j);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)sz[get_fa(i,j)]++;
		}
		if(n*m<=5000){
			for(int i=1;i<=Q;i++){
				++vst[0],ans=0;
				int c=getint()+100,lv=getint()+3,x=getint(),y=getint();
				dfs1(x,y,c,lv),dfs0(x,y,c,lv,0);
				wrt(ans-1+calc1(x,y,c,lv)+calc2(x,y,c,lv)+calc3(x,y,c,lv)+calc4(x,y,c,lv)),pc('\n');
				col[ID(x,y)]=c,le[ID(x,y)]=lv;
			}
		}else{
			for(int i=1;i<=Q;i++){
				++vst[0],ans=0;
				int c=getint()+100,lv=getint()+3,x=getint(),y=getint();
				dfs1(x,y,c,lv),dfs0(x,y,c,lv,0);
				wrt(ans-1+calc1(x,y,c,lv)+calc2(x,y,c,lv)+calc3(x,y,c,lv)+calc4(x,y,c,lv)),pc('\n');
				col[ID(x,y)]=c,le[ID(x,y)]=lv;
			}
		}
	}
	fwrite(wb,1,p2,stdout);
	return 0;
}
/*
1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2
*/
