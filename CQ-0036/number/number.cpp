#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
const int mx=1e7+100;
bool book[mx+5];
int id[mx+5],zc[mx+5],t,n,cnt;
bool pd(int x) {
	while(x) {
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1; i<=mx; i++) {
		if(book[i]||!pd(i))continue;
		for(int j=i; j<=mx; j+=i)book[j]=1;
	}
	for(int i=1; i<=mx; i++)
		if(!book[i])zc[++cnt]=i,id[i]=cnt;
	t=read();
	while(t--) {
		n=read();
		if(book[n])puts("-1");
		else cout<<zc[id[n]+1]<<'\n';
	}
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊！1145141919810
