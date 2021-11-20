#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int T,N,M,Q;
int opt[5005][5005][5];//1ÉÏ£¬2ÓÒ£¬3ÏÂ£¬4×ó 
int col[5005][5005],lv[5005][5005];
ll ans;
int clo[5005][5005];
int cc[5005][5005];
int xf[5]={0,-1,0,1,0},yf[5]={0,0,1,0,-1};
void zhou(int fx,int x,int y,int shang,int lv1,int col1){
	int nopt=opt[x][y][fx];
	if(clo[x+xf[fx]][y+yf[fx]]) return ;
	if(nopt==0||nopt==-1||nopt!=shang){
		return ;
	}
	else if(nopt==1){
		if((col[x+xf[fx]][y+yf[fx]]!=col1&&lv1>=lv[x+xf[fx]][y+yf[fx]])||col[x+xf[fx]][y+yf[fx]]==-1){
			clo[x+xf[fx]][y+yf[fx]]=1;
			if(!cc[x+xf[fx]][y+yf[fx]])
			ans++;
			cc[x+xf[fx]][y+yf[fx]]=1;
			return ;
		}
	}
	else if(nopt==2){
		if(col[x+xf[fx]][y+yf[fx]]!=-1&&col[x+xf[fx]][y+yf[fx]]!=col1&&lv1>=lv[x+xf[fx]][y+yf[fx]]){
			clo[x+xf[fx]][y+yf[fx]]=1;
			if(!cc[x+xf[fx]][y+yf[fx]])
			ans++;
			cc[x+xf[fx]][y+yf[fx]]=1;
			return ;
		}
		else{
			if(col[x+xf[fx]][y+yf[fx]]==-1){
				clo[x+xf[fx]][y+yf[fx]]=1;
				if(!cc[x+xf[fx]][y+yf[fx]])
				ans++;
				cc[x+xf[fx]][y+yf[fx]]=1;
				
				zhou(fx,x+xf[fx],y+yf[fx],nopt,lv1,col1);
			}
		}
	}
	else if(nopt==3){
		if(col[x+xf[fx]][y+yf[fx]]!=-1&&col[x+xf[fx]][y+yf[fx]]!=col1&&lv1>=lv[x+xf[fx]][y+yf[fx]]){
			clo[x+xf[fx]][y+yf[fx]]=1;
			if(!cc[x+xf[fx]][y+yf[fx]])
			ans++;
			cc[x+xf[fx]][y+yf[fx]]=1;
			return ;
		}
		else{
			if(col[x+xf[fx]][y+yf[fx]]==-1){
				clo[x+xf[fx]][y+yf[fx]]=1;
				if(!cc[x+xf[fx]][y+yf[fx]])
				ans++;
				cc[x+xf[fx]][y+yf[fx]]=1;
				zhou(1,x+xf[fx],y+yf[fx],nopt,lv1,col1);
				zhou(2,x+xf[fx],y+yf[fx],nopt,lv1,col1);
				zhou(3,x+xf[fx],y+yf[fx],nopt,lv1,col1);
				zhou(4,x+xf[fx],y+yf[fx],nopt,lv1,col1);
			}
		}
	}
}

void fin(int x,int y,int lv1,int col1){
	for(int i=1;i<=4;i++){
		if(opt[x][y][i]!=-1&&opt[x][y][i]!=0){
			if(col1!=col[x+xf[i]][y+yf[i]]&&lv1>=lv[x+xf[i]][y+yf[i]]&&col[x+xf[i]][y+yf[i]]!=-1){
				clo[x+xf[i]][y+yf[i]]=1;
				if(!cc[x+xf[i]][y+yf[i]])
				ans++;
				cc[x+xf[i]][y+yf[i]]=1;
				continue;
			}
			else if(col[x+xf[i]][y+yf[i]]==-1){
				memset(clo,0,sizeof(clo));
				clo[x][y]=1;
				zhou(i,x,y,opt[x][y][i],lv1,col1);
			}
		}
	}
}



int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(opt,-1,sizeof(opt));
		memset(col,-1,sizeof(col));
		
		scanf("%d%d%d",&N,&M,&Q);
		for(int i=1;i<=N;i++){
			char ch[5005];
			scanf("%s",ch+1);
			for(int j=1;j<M;j++){
				opt[i][j][2]=opt[i][j+1][4]=int(ch[j]-'0');
			}
		}
		for(int i=1;i<N;i++){
			char ch[5005];
			scanf("%s",ch+1);
			for(int j=1;j<=M;j++){
				opt[i][j][3]=opt[i+1][j][1]=int(ch[j]-'0');
			}
		}
		while(Q--){
			ans=0;
			memset(cc,0,sizeof(cc));
			int clo1,lv1,x,y;
			scanf("%d%d%d%d",&clo1,&lv1,&x,&y);
			col[x][y]=clo1,lv[x][y]=lv1;
			clo[x][y]=1;
			fin(x,y,lv1,clo1);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
// fc chess.out chess3.ans
