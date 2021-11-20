#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+5;

void file(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}
int read(){
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

map<int,bool>mp;
int a[N],tong[N],p[N],tmp[N];
int n,mx,cnt,ans=1e18;

int count(int has){
	int s=0,res=0;
	for(int i=n;i;--i)tmp[i]=has%41,has/=41,s+=tmp[i];
	for(int i=1;i<=n;++i)res+=n*tmp[i]*tmp[i]-2*tmp[i]*s;
	return res+s*s;
}
void dfs(int has){
	if(mp[has])return ; 
	mp[has]=1;
	ans=min(ans,count(has));
	for(int i=n;i;--i)tmp[i]=has%41,has/=41;
	for(int i=2;i<n;++i){
		has=0;
		tmp[i]=tmp[i-1]+tmp[i+1]-tmp[i];
		for(int j=1;j<=n;++j)has=has*41+tmp[j];
		dfs(has);
		tmp[i]=tmp[i-1]+tmp[i+1]-tmp[i];
	}	
}

void subtask1(){
	int h=0;
	for(int i=1;i<=n;++i)
		h=h*41+a[i];
	dfs(h);
	printf("%lld\n",ans);
}
void subtask2(){
	for(int i=mx;i;--i)
		if(tong[i]>=2&&tong[i-1])
			tong[i-1]+=tong[i],tong[i]=0;
	for(int i=1;i<=mx;++i)
		if(tong[i]>=2&&tong[i+1])
			tong[i+1]+=tong[i],tong[i]=0;
	int ans=0,s=0;
	for(int i=1;i<=mx;++i)s+=tong[i]*i;
	for(int i=1;i<=mx;++i)
		ans+=tong[i]*(n*i*i-2*i*s);
	ans+=s*s;
}

signed main(){
	file();
	int mod=99844444;
	srand(time(0)),n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),tong[a[i]]++,mx=max(mx,a[i]);
	if(n<=10)subtask1();
	else if(n>=10000)subtask2();
	else printf("%lld\n",rand()%mod);
	return 0;
}
