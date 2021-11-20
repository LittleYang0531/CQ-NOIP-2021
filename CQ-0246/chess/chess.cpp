#include<bits/stdc++.h>
#define r register
using namespace std;

const int maxn = 1e5+5;
int ans=0;
bool pd[5005][5005];

struct str
{
	int you,xia;	//you:到左边的道路类型 ，xia:到下边到道路类型.(左边是maps[i][j-1].you,右边同理)。 
	int color,lv;	
	bool had;	//此时有没有子. 
}maps[5005][5005];

struct for_que
{
	int x,y;
	int type;	
	unsigned short from;		//from从哪个方向来（只在直线道路时使用）（0上,1下,2左,3右); 
};

inline void init()
{
	memset(maps,0,sizeof(maps));
	ans=0;
}

queue<for_que> que; 
int main(int argc,char **argv)
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	r int T,n,m,q,col,lvi,dx,dy;
	r for_que top;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d%d",&n,&m,&q);
		for(r int i=1;i<=n;++i)
		{
			getchar();
			for(r int j=1;j<=m-1;++j)
			{
				maps[i][j].you=getchar()-'0';
			}			
		}
		for(r int i=1;i<=n-1;++i)
		{
			getchar();
			for(r int j=1;j<=m;++j)
			{
				maps[i][j].xia=getchar()-'0';
			}	
		}
		for(r int i=1;i<=q;++i)
		{
			scanf("%d%d%d%d",&col,&lvi,&dx,&dy);
			memset(pd,0,sizeof(pd));
			maps[dx][dy].color=col;
			maps[dx][dy].lv=lvi;
			maps[dx][dy].had=1;
			pd[dx][dy]=1;
			que.push({dx,dy,4,5});
			while(!que.empty())
			{
				top=que.front();
				if(top.y>1&&(top.type==4||top.type==maps[top.x][top.y-1].you)&&maps[top.x][top.y-1].you!=0&&(!maps[top.x][top.y-1].had||(maps[top.x][top.y].color!=maps[top.x][top.y-1].color&&maps[top.x][top.y].lv>=maps[top.x][top.y-1].lv))) 
				{
					if(((top.type==4)||(top.type==2&&(top.from==3||top.from==5)||(top.type==3)))&&pd[top.x][top.y-1]==0)
					{
						pd[top.x][top.y-1]=1;
						if(!maps[top.x][top.y-1].had)que.push({top.x,top.y-1,maps[top.x][top.y-1].you,3});
						++ans;
					}
				}
				
				
				if((top.y<m&&(top.type==4||top.type==maps[top.x][top.y].you)&&maps[top.x][top.y].you!=0)||top.y==m-1&&(!maps[top.x][top.y+1].had||(maps[top.x][top.y].color!=maps[top.x][top.y+1].color&&maps[top.x][top.y].lv>=maps[top.x][top.y+1].lv))) 
				{
					if(top.y==m-1&&(top.type==2&&(top.from==2||top.from==5)||(top.type==3))&&pd[top.x][top.y+1]==0)
					{
						pd[top.x][top.y+1]=1;
						if(!maps[top.x][top.y+1].had)que.push({top.x,top.y+1,maps[top.x][top.y].you,2});
						++ans;
					}
					else if(((top.type==4)||(top.type==2&&(top.from==2||top.from==5)||(top.type==3)))&&pd[top.x][top.y+1]==0&&(top.type==4||top.type==maps[top.x][top.y].you)&&maps[top.x][top.y].you!=0)
					{
						pd[top.x][top.y+1]=1;
						if(!maps[top.x][top.y+1].had)que.push({top.x,top.y+1,maps[top.x][top.y].you,2});
						++ans;
					}
				}
				
				
				if(top.x>1&&(top.type==4||top.type==maps[top.x-1][top.y].xia)&&maps[top.x-1][top.y].xia!=0&&(!maps[top.x-1][top.y].had||(maps[top.x][top.y].color!=maps[top.x-1][top.y].color&&maps[top.x][top.y].lv>=maps[top.x-1][top.y].lv))) 
				{
					if(((top.type==4)||(top.type==2&&(top.from==0||top.from==5)||(top.type==3)))&&pd[top.x-1][top.y]==0)
					{
						pd[top.x-1][top.y]=1;
						if(!maps[top.x-1][top.y].had)que.push({top.x-1,top.y,maps[top.x-1][top.y].xia,0});
						++ans;
					}
				}
				
				if((top.x<n&&(top.type==4||top.type==maps[top.x][top.y].xia)&&maps[top.x][top.y].xia!=0)||top.x==n-1&&(!maps[top.x+1][top.y].had||(maps[top.x][top.y].color!=maps[top.x+1][top.y].color&&maps[top.x][top.y].lv>=maps[top.x+1][top.y].lv))) 
				{
					if(top.x==n-1&&((top.type==4)||(top.type==2&&(top.from==1||top.from==5)||(top.type==3)))&&pd[top.x+1][top.y]==0)
					{
						pd[top.x+1][top.y]=1;
						if(!maps[top.x+1][top.y].had)que.push({top.x+1,top.y,maps[top.x][top.y].xia,1});
						++ans;
					}
					else if(((top.type==4)||(top.type==2&&(top.from==1||top.from==5)||(top.type==3)))&&pd[top.x+1][top.y]==0&&(top.type==4||top.type==maps[top.x][top.y].xia)&&maps[top.x][top.y].xia!=0)
					{
						pd[top.x+1][top.y]=1;
						if(!maps[top.x+1][top.y].had)que.push({top.x+1,top.y,maps[top.x][top.y].xia,1});
						++ans;
					}
				}
				
				que.pop();
			}
			printf("%d\n",ans);
			ans=0;
		}
	}
	exit(0);
}
