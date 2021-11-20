#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=10000005;
bool num[MAXN];
int n[MAXN];
inline bool fen(int x){
	int f=x;
	while(f>0){
		int p=f%10;
		if(p==7){
			num[x]=1;
			return false;
		}
		f/=10;
	}
	return true;
}

inline void shai(){
	for(int i=1;i<=MAXN;i++){
		if(num[i]==0){
			if(fen(i)==0){
				for(int j=2;i*j<=MAXN;j++)
					num[i*j]=1;
			}
		}
	}
}

inline void pai(){
	int p=MAXN;
	for(int i=MAXN;i>0;i--){
		if(num[i]==0)p=i;
		n[i-1]=p;
	}
}

int main(){
	ios::sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	shai();
	pai();
	int t;
	t=read();
	int p;
	while(t--){
		p=read();
		if(num[p]==1)cout<<"-1"<<'\n';
		else cout<<n[p]<<'\n';
	}
	return 0;
}
