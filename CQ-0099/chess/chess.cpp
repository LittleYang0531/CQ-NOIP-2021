#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int t,qq,n,m;
int xx[4]={1,0,-1,0};
int yy[4]={0,-1,0,1};
string s;
string v1[200100],v2[200100];
struct ban
{
	int x,y;
};
bool operator < (const ban &a,const ban &b)
{
	return a.x<b.x;
}
struct ccf
{
	int x,y,opt,fang;//1 shang 2 xia 3 zuo 4 you
};
map<pair<int,int>,pair<int,int> > mms; 
map<pair<int,int>,int> ms; 
queue<ccf> q;
int bfs(int x,int y,int lv,int col)
{
	int ans=0;
	map<pair<int,int>,int> mm;
	pair<int,int> Impact=make_pair(x,y);
	
	mm[make_pair(x,y)]=1;
	q.push((ccf){x,y,-1,-1});
	while(!q.empty())
	{
		ccf now=q.front();
		q.pop();
		if(ms[make_pair(now.x,now.y)])
		{
			if(!mm[make_pair(now.x,now.y)]&&(now.x!=x||now.y!=y)&&mms[make_pair(now.x,now.y)].first<=lv&&mms[make_pair(now.x,now.y)].second!=col) 
			{
			//	cout<<mms[make_pair(now.x,now.y)].second<<endl;
				mm[make_pair(now.x,now.y)]=1,ans++;
			}
			continue;
		}
		if(now.opt==0)continue;
		if(!mm[make_pair(now.x,now.y)]&&(now.x!=x||now.y!=y)) 
		{
			mm[make_pair(now.x,now.y)]=1,ans++;
		//	cout<<now.x<<" "<<now.y<<" "<<x<<" "<<y<<endl;
		}
		else mm[make_pair(now.x,now.y)]++;
		if(mm[make_pair(now.x,now.y)]>4) continue;
		if(now.opt==1) continue;
		//cout<<now.x<<" "<<now.y<<endl;
		for(int i=0;i<=3;i++)
		{
			
			int mcx=now.x+xx[i],mcy=now.y+yy[i];//cout<<"("<<now.x<<","<<now.y<<") -> ("<<mcx<<","<<mcy<<")"<<endl;
			if(mcx>=1&&mcy>=1&&mcx<=n&&mcy<=n)
			{
				if(now.opt==-1)
				{
					int nxt=-1,ff=-1;
					if(xx[i]==0&&yy[i]==-1)nxt=v1[mcx-1][mcy-1],ff=1;
					if(xx[i]==0&&yy[i]==1)nxt=v1[mcx-1][mcy-2],ff=2;
					if(xx[i]==1&&yy[i]==0)nxt=v2[mcx-2][mcy-1],ff=3;
					if(xx[i]==-1&&yy[i]==0)nxt=v2[mcx-1][mcy-1],ff=4;
					nxt-='0';
				//	cout<<nxt<<endl;
					if(nxt==1&&mms[make_pair(mcx,mcy)].first<=lv&&mms[make_pair(mcx,mcy)].second!=col) mm[make_pair(mcx,mcy)]=1,ans++;
					if(nxt==2) q.push((ccf){mcx,mcy,nxt,ff});
					if(nxt==3) q.push((ccf){mcx,mcy,nxt,-1});
				}
				else if(now.opt==3)
				{
					int nxt=-1;
					if(xx[i]==0&&yy[i]==-1)nxt=v1[mcx-1][mcy-1];
					if(xx[i]==0&&yy[i]==1)nxt=v1[mcx-1][mcy-2];
					if(xx[i]==1&&yy[i]==0)nxt=v2[mcx-2][mcy-1];
					if(xx[i]==-1&&yy[i]==0)nxt=v2[mcx-1][mcy-1];
					nxt-='0';
					if(nxt==now.opt) q.push((ccf){mcx,mcy,now.opt,-1});
				}
				else if(now.opt==2)
				{
					int nxt=-1,ff=-1;
					if(xx[i]==0&&yy[i]==-1)nxt=v1[mcx-1][mcy-1],ff=1;
					if(xx[i]==0&&yy[i]==1)nxt=v1[mcx-1][mcy-2],ff=2;
					if(xx[i]==1&&yy[i]==0)nxt=v2[mcx-2][mcy-1],ff=3;
					if(xx[i]==-1&&yy[i]==0)nxt=v2[mcx-1][mcy-1],ff=4;
					nxt-='0';
					if(nxt==now.opt&&ff==now.fang) q.push((ccf){mcx,mcy,now.opt,ff});
				}
			}
			
		}
	}
	mms[make_pair(x,y)]=make_pair(lv,col);
	ms[make_pair(x,y)]=1;
	return ans;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read(),m=read(),qq=read();
		for(int i=0;i<n;i++) 
		{
			cin>>v1[i];
		}
		for(int i=0;i<n-1;i++)
		{
			cin>>v2[i];
		}
		for(int i=1;i<=qq;i++)
		{
			int col,lv,x,y;
			col=read(),lv=read(),x=read(),y=read();
			cout<<bfs(x,y,lv,col)<<endl;
		}
	}
}
