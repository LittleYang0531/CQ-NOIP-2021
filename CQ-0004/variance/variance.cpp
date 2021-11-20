#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(ll x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
int n;
const int mod=998244353;
int v[10005];
int a[10005];
namespace S10
{
	struct node
	{
		int a[11];
		bool operator<(const node&w)const
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]<w.a[i])
				{
					return 1;
				}
				if(a[i]>w.a[i])return 0;
			}
			return 0;
		}
		ll get()const
		{
			ll sm_=0,sm=0;
			for(int i=1;i<=n;i++)
				sm_+=1ll*a[i]*a[i],sm+=a[i];
			return n*sm_-sm*sm;
		}
		unsigned ll ghs()
		{
			unsigned ll hs=0;
			for(int i=1;i<=n;i++)
			{
				hs*=20;
				hs+=a[i];
			}
			return hs;
		}
	}st;
	map<node,int>mp;
	void solve()
	{
		for(int i=1;i<=n;i++)st.a[i]=v[i];
		mp[st]=1;
		queue<node>q;
		q.push(st);
		ll res=1e18;
		while(!q.empty())
		{
			node s=q.front();
			res=min(res,s.get());
			q.pop();
			for(int i=2;i<n;i++)
			{
				s.a[i]=s.a[i-1]+s.a[i+1]-s.a[i];
				if(mp.find(s)==mp.end())
				{
					mp[s]=1;
					q.push(s);
				}
				s.a[i]=s.a[i-1]+s.a[i+1]-s.a[i];
			}
		}
//		cout<<mp.size()<<"\n";
		cout<<res<<"\n";
		return ;
	}
}
struct node
{
	int a[16];
	bool operator<(const node&w)const
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<w.a[i])
			{
				return 1;
			}
			if(a[i]>w.a[i])return 0;
		}
		return 0;
	}
	ll get()const
	{
		ll sm_=0,sm=0;
		for(int i=1;i<=n;i++)
			sm_+=1ll*a[i]*a[i],sm+=a[i];
		return n*sm_-sm*sm;
	}
	unsigned ll ghs()
	{
		unsigned ll hs=0;
		for(int i=1;i<=n;i++)
		{
			hs*=20;
			hs+=a[i];
		}
		return hs;
	}
}st;
map<node,int>mp;
unordered_map<unsigned ll,int>ss;
unsigned ll pw[10005];
ll js()
{
	ll sm_=0,sm=0;
	for(int i=1;i<=n;i++)
		sm_+=1ll*a[i]*a[i],sm+=a[i];
	return n*sm_-sm*sm;
}
const double eps=1e-8;
const double R=0.998;
ll res=1e18;
void run()
{
	double T=1e9;
	while(T>eps)
	{
		int o=26;
		while(o--)
		{
			int s=rand()%(n-2)+2;
			ll now=js();
			a[s]=a[s-1]+a[s+1]-a[s];
			ll to=js();
			ll dlt=now-to;
//			cerr<<now<<" "<<to<<"\n";
			if(dlt>0)
			{
				res=min(res,to);
			}
			else 
			{
				if(exp(dlt/T)*RAND_MAX<=rand())//接受 
				{
//					cerr<<exp(dlt/T)<<"\n";
//					assert(0);
				}
				else 
				{
					a[s]=a[s-1]+a[s+1]-a[s];
					
				}
			}
		}
		T*=R;
	}
	int o=26000;
	while(o--)
	{
		int s=rand()%(n-2)+2;
		ll now=js();
		a[s]=a[s-1]+a[s+1]-a[s];
		ll to=js();
		ll dlt=now-to;
//			cerr<<now<<" "<<to<<"\n";
		if(dlt>0)
		{
			res=min(res,to);
		}
		else 
		{
			if(exp(dlt/T)*RAND_MAX<=rand())//接受 
			{
//					cerr<<exp(dlt/T)<<"\n";
//					assert(0);
			}
			else 
			{
//					if(exp(dlt/T)!=1)cerr<<exp(dlt/T)<<"\n";
//					assert(0);
				a[s]=a[s-1]+a[s+1]-a[s];
				
			}
		}
	}
	T*=R;
}
int main(){
	srand(1637383321);
//	cout<<time(0)<<"\n";
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
//	for(int i=-10000;i<=100000;i++)
//	{
//		cout<<i/100.0<<" "<<exp(i/100.0)<<"\n";
//	}
	n=read();
	for(int i=1;i<=n;i++)v[i]=a[i]=read();
	if(n<=10)
	{
		S10::solve();
		exit(0);
	}
	run();
	run();
	run();
	run();
	run();
	run();
	run();
	run();
	run();
	run();
	run();
	cout<<res<<'\n';
	pc('1',1);
	return 0;
}
/*
1
9999998
*/
//			if(s.get()==59865)
//			{
//				for(int i=1;i<=n;i++)
//				{
//					cout<<s.a[i]<<" ";
//				}
//				puts("");
//			}
//			if(mp.size()>100000)break;
/*IronHeart@413A*/
