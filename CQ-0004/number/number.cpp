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
bitset<20000005>vs;
int sum[20000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	cout<<sizeof(sum)/1024/1024<<"\n";
	//为了保险，筛到2*1e7 
	for(int i=1;i<=20000000;i++)
		if(i%10==7||vs[i/10])vs[i]=1;
	for(int i=1;i<=20000000;i++)
	{
		if(vs[i])
			for(int j=i;j<=20000000;j+=i)vs[j]=1;
	}
	for(int i=1;i<=20000000;i++)sum[i]=sum[i-1]+vs[i];
	int T=read();
	while(T--)
	{
		int x=read();
		if(vs[x])
		{
			puts("-1");
			continue;
		}
		else 
		{
			int r=20000000,l=x+1,ans=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(sum[mid]-sum[x]==(mid-x))l=mid+1;
				else ans=mid,r=mid-1;
			}
			cout<<ans<<"\n";
		}
	}
	pc('1',1);
	return 0;
}
/*
1
9999998
*/
/*IronHeart@413A*/
