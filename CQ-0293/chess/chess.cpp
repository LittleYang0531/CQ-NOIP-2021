#include<iostream>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct jjy{
	int form,to,op;
};

vector<jjy> edge;
vector<int> G[200005];

int n,m,q;
int a[5005][5005];


int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int t=read();
	while(t--){
		
		n=read(),m=read(),q=read();
		for(int i=1;i<=n*m;i++)
			
		
	} 
	
	
	return 0;
}
