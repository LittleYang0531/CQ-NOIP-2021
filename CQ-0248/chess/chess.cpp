#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_set>
using namespace std;

void fr(int&x)
{
    x=0;
    bool neg=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar())
        if(c=='-')  neg=1;
    while(isdigit(c))
        x=(x<<3)+(x<<1)+c-48,c=getchar();
    x*=neg?-1:1;
}
void fr(short&x)
{
    x=0;
    bool neg=0;
    char c=getchar();
    for(;!isdigit(c);c=getchar())
        if(c=='-')  neg=1;
    while(isdigit(c))
        x=(x<<3)+(x<<1)+c-48,c=getchar();
    x*=neg?-1:1;
}

void fp(int x)
{
    if(x<0) putchar('-'),x*=-1;
    if(x>=10)    fp(x/10);
    putchar(x%10+'0');
}

const int N=450;

int n,m,step;

struct node{
    int col,lv;
}board[N][N];
struct item{
    int state;
    void modify(int x,int y,int from)
    {
        state=x*10000+y*10+from;
    }
    int x()
    {
        return state/10000;
    }
    int y()
    {
        return state%10000/10;
    }
    int from()
    {
        return state%10;
    }
};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
short road[N][N][4];

void init()
{
    memset(board,0,sizeof board);
    memset(road,0,sizeof road);
}

inline bool canGo(int x,int y,int k){return x>=1&&y>=1&&x<=n&&y<=m&&road[x][y][k^1];}
item q[N*N];
int hh,tt,cnt;
bool vis[N][N]; //whether visited (i,j)
void flood_fill(int col,int lv,int sx,int sy)
{
    memset(vis,0,sizeof vis);
    unordered_set<int> S;
    hh=tt=cnt=0;
    vis[sx][sy]=1;
    for(int k=0;k<4;k++)
    {
        int nx=sx+dx[k],ny=sy+dy[k];
        if(canGo(nx,ny,k))
        {
//            printf("(%d,%d) can go to (%d,%d) by %d on %d\n",sx,sy,nx,ny,road[sx][sy][k],k);
            if(board[nx][ny].col==0)
            {
                if(road[sx][sy][k]==2||road[sx][sy][k]==3)
                    q[tt++].modify(nx,ny,k);
//                printf("(%d,%d)",nx,ny);
                cnt++;
                S.insert(q[tt].state);
                vis[nx][ny]=1;
            }
            else if(col!=board[nx][ny].col&&lv>=board[nx][ny].lv)
            {
//                printf("(%d,%d)",nx,ny);
                cnt++;
                vis[nx][ny]=1;
            }
        }
    }
    while(hh<tt)
    {
        if(tt==N*N)  tt=0;
        item u=q[hh++];
        if(hh==N*N) hh=0;

        for(int k=0;k<4;k++)
        {
            if(road[u.x()][u.y()][k]!=road[u.x()][u.y()][u.from()^1]    //one king of edge from the beginning to the end
               ||road[u.x()][u.y()][k]<2    //go deeper
               ||(road[u.x()][u.y()][u.from()^1]==2&&k!=u.from())   //one direction on edge type 2
               )  continue;
            int nx=u.x()+dx[k],ny=u.y()+dy[k];
            if(k==(u.from()^1)) continue;   //no turning back
            if(canGo(nx,ny,k))
            {
                if(S.count(nx*10000+ny*10+k))   continue;   //no repeating
                S.insert(nx*10000+ny*10+k);
                if(board[nx][ny].col==0)
                {
                    q[tt++].modify(nx,ny,k);
                    if(tt==N*N) tt=0;
                    if(!vis[nx][ny])
//                printf("(%d,%d)",nx,ny),
                        cnt++;
                    vis[nx][ny]=1;
                }
                else if((col!=board[nx][ny].col)&&lv>=board[nx][ny].lv)
                {
                    if(!vis[nx][ny])
//                printf("(%d,%d)",nx,ny),
                        cnt++;
                    vis[nx][ny]=1;
                }
            }
        }
    }
    fp(cnt),putchar('\n');
}

void solve()
{
    fr(n),fr(m),fr(step);
//    char c;
    for(int i=1;i<=n;i++,getchar())
        for(int j=1;j<m;j++)
            road[i][j][2]=getchar()-'0',road[i][j+1][3]=road[i][j][2];
    for(int i=1;i<n;i++,getchar())
        for(int j=1;j<=m;j++)
            road[i][j][0]=getchar()-'0',road[i+1][j][1]=road[i][j][0];
    while(step--)
    {
        int col,lv,x,y;
        fr(col),fr(lv),fr(x),fr(y);
        board[x][y]={col+1,lv};
        flood_fill(col+1,lv,x,y);
    }
//    while(1)
//    {
//        int x,y,k;
//        cin>>x>>y>>k;
//        cout<<road[x][y][k]<<endl;
//    }
}

int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int t;
    fr(t);
    while(t--)
    {
        init();
        solve();
    }
}
