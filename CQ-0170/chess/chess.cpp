// ��ȥ���⣬��԰���ߺ����飡���޶� 
// С�۴Ӵ��ţ�������������
// �������С�
// ��ȥĪ���ʣ������޾�ʱ��
// ��ĺ��غδ��ǣ��̲�����ʹ�˳
// �������ྯ������ټ��塣
// ��ҹ�������������ϸ�¥����������·��
// �ɾ���������ǣ��ղ����а�˪֦�� 
// ���Ϻ��˳����£����º�������ˡ� 
// ��ɽ���������⣬��ˮ�зְ����ޡ�
// �����沨ǧ����δ�������������
// ��̨���·�ҹ��һ����ʯ���綷���������ʯ���ߡ�
// ������ʱ���磬�滨���������
// ��ɪ�޶���ʮ�ң�һ��һ��˼���ꡣ 
// ���紺�μ���ʱ��ȥ�Ƴ������ٴ���
// ��ʦδ������������ʹӢ�������� 
// ���һ�������ϣ�����ʫ�鵽������ 
// ������Ұ��������ɽ�����ز���ƽ�� 

#include<cstdio>
#include<cstring>
const int maxn=5005;
const int fangx[]={-1,1,0,0};
const int fangy[]={0,0,-1,1};
int T,n,m,q,c,l,t,x,y,ans,now;
int a[maxn][maxn],b[maxn][maxn];
int vis[maxn][maxn],vis2[maxn][maxn];
struct _{ int c,l; bool f; } p[maxn][maxn];
inline int GetType(int x,int y,int u){
	if(u==1) return b[x-1][y];
	if(u==2) return b[x][y];
	if(u==3) return a[x][y-1];
	return a[x][y];
} 
void Search(int x,int y,int u,int r){
	if(++vis[x][y]>1) return;
	if(vis2[x][y]!=now) vis2[x][y]=now, ++ans;
	if(u==1) return;
//	printf("%d, %d, %d, %d\n",x,y,u,r);
	for(int i=0;i<4;++i){
		int nx=x+fangx[i], ny=y+fangy[i];
		if(nx<1||ny<1||nx>n||ny>m) continue;
		if((t=GetType(x,y,i+1))!=u&&(~u)) continue;
		if(!t) continue;
		if(t==2&&(i<2&&r==2||i>1&&r==1)&&(~r)) continue;
//		printf("(%d, %d) => (%d, %d): %d (I = %d)\n",
//		x,y,nx,ny,t,i+1);
		if(p[nx][ny].f){
			if(p[nx][ny].c!=c&&p[nx][ny].l<=l)
				if(vis2[nx][ny]!=now) vis2[nx][ny]=now, ++ans;
			continue;
		}
		Search(nx,ny,t,t==2?(i<2?1:2):-1); --vis[nx][ny];
	}
	return;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i){
			for(int j=1;j<m;++j){
				scanf("%1d",&a[i][j]);
				p[i][j].f=0;
			}
		}
		for(int i=1;i<n;++i){
			for(int j=1;j<=m;++j){
				scanf("%1d",&b[i][j]);
				p[i][j].f=0;
			}
		}
		while(q--){
			scanf("%d%d%d%d",&c,&l,&x,&y);
			p[x][y].c=c; p[x][y].l=l;
			p[x][y].f=1; ans=0;
			if(n*m<=5000){
				vis2[x][y]=++now;
				Search(x,y,-1,-1);
				--vis[x][y];
				printf("%d\n",ans);
			} else{
				for(int i=0;i<4;++i){
					int nx=x+fangx[i], ny=y+fangy[i];
					if(nx<1||ny<1||nx>n||ny>n) continue;
					if(GetType(x,y,i+1)==1&&(!p[nx][ny].f||
					p[nx][ny].c!=c&&p[nx][ny].l<=l)) ++ans;
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}

// You watch me bleed until I can't breathe shaking
// Falling onto my knees
// And now that I'm without your kisses
// I'll be needing stiches
// Tripping over myself aching
// Begging you to come help
// And now that I'm without your kisses
// I'll be needing stiches

// С z ��С c
// ��Ҫ�ز����СС zc�� 
// �� ��ǲ���Ҫ���˰����Һ���û�� 
