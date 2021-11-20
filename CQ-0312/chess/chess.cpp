//2021/11/20

//大模拟我吐了啊...
//再给 1 个小时ba 

#include <iostream>

#include <cstdio>

#include <climits>

#include <vector>

#include <string>

#define BLACK 0

#define WHITE 1

#define debug(x,que) cerr<<#x<<" = "<<x<<que

#define endl "\n"

namespace Newstd
{
	inline int read()
	{
		int x=0,k=1;
		char ch=getchar();
		while(ch<'0' || ch>'9')
		{
			if(ch=='-')
			{
				k=-1;
			}
			ch=getchar();
		}
		while(ch>='0' && ch<='9')
		{
			x=(x<<1)+(x<<3)+ch-'0';
			ch=getchar();
		}
		return x*k;
	}
	inline void write(int x)
	{
		if(x<0)
		{
			putchar('-');
			x=-x;
		}
		if(x>9)
		{
			write(x/10);
		}
		putchar(x%10+'0');
	}
}

using namespace Newstd;

using namespace std;

const short dx[]={0,0,-1,1};

const short dy[]={-1,1,0,0};

const int ma=100005;

struct Node
{
	int col;
	
	int lv;
	
	bool mark;
};

int T,n,m,q;

int ans;

/*
mp1[i][j]:mp[i][j] -> mp[i][j+1]
mp2[i][j]:mp[i][j] -> mp[i+1][j]
*/ 

vector<vector<int> >mp1,mp2;

vector<vector<Node> >mp;

int main(void)
{
	freopen("chess.in","r",stdin);
	
	freopen("chess.out","w",stdout); 
	
	T=read();
	
//	cerr<<"KEEP."<<endl; 
	
	while(T--)
	{
		n=read(),m=read(),q=read();
		
		/*
		memset(lv,0,sizeof(lv));
		
		memset(col,0,sizeof(col));
		*/
		
		mp1.clear(),mp2.clear();
		
		mp.clear();
		 
		for(register int i=1;i<=n;i++)
		{
			string opt;
			
			cin>>opt;
			
			opt=" "+opt; 
			
			mp1[i].push_back(0);
			
			for(register int j=1;j<m;i++)
			{
				mp1[i].push_back(opt[j]-'0');
			}
		}
		
		for(register int i=1;i<n;i++)
		{
			char opt[ma];
			
			scanf("%s",opt+1);
			
			mp2[i].push_back(0);
			
			for(register int j=1;j<=m;j++)
			{
				mp2[i].push_back(opt[j]-'0');
			}
		}
		
		while(q--)
		{
			int col=read(),lv=read(),x=read(),y=read(); 
			
			mp[x][y].col=col,mp[x][y].lv=lv; 
			
			mp[x][y].mark=true;
			
			ans=0;
			
			ans+=mp2[x-1][y]+mp1[x][y-1]+mp2[x][y]+mp1[x][y];
			
			printf("%d\n",ans); 
		}
	}
	
	return 0;
}
