#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long

const int N=1e4+10;
const ll inf=1e18;

int n;
int a[N];
unordered_map<ull,bool>ma;
ull tmp;
queue<vector<int> >dl;
vector<int>now,nxt;
ull base=114514123;
ull pw[N];
ll ans=inf;

int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

ull h(vector<int>&g){
	ull hs=0;
	for(int i=0;i<g.size();++i){
		hs+=pw[i]*g[i];
	}
	return hs;
}

ll get(vector<int>&g){
	ll sum=0;
	ll a=0;
	for(int i=0;i<g.size();++i)sum+=g[i];
	for(int i=0;i<g.size();++i)a=a+(n*g[i]-sum)*(n*g[i]-sum);
	a/=n;
	return a;
}

void Print(vector<int>&g){
	for(int i=0;i<g.size();++i){
		printf("%d ",g[i]);
	}
	printf("\n");
}

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	
	n=read();
	pw[0]=1;
	for(int i=1;i<=n;++i)pw[i]=pw[i-1]*base;
	for(int i=1;i<=n;++i){
		int x=read();
		now.push_back(x);
	}
	ma[h(now)]=1;
	dl.push(now);
	while(!dl.empty()){
		now=dl.front();
		dl.pop();
//		Print(now);
		ans=min(ans,get(now));
		nxt=now;
		for(int i=1;i<now.size()-1;++i){
			nxt=now;
			int t=nxt[i];
			nxt[i]=nxt[i-1]+nxt[i+1]-nxt[i];
			tmp=h(nxt);
			if(!ma[tmp]){
				ma[tmp]=1;
				dl.push(nxt);
			}
			nxt[i]=t;
		}
	}
	printf("%lld",ans);
	return 0;
}
