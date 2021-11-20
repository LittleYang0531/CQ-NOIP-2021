#include<bits/stdc++.h>
#define limit 200000
#define inf 0x3f3f3f3f
using namespace std;
int t,x,save[10];
unsigned check[limit+5];
vector<int>prime;//prime的定义变更
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){
		if(ch=='-')w=-1;ch=getchar();
	}
	while(isdigit(ch)&&ch!=EOF){
		n=(n<<1)+(n<<3)+(ch&15);ch=getchar();
	}
	n*=w;
}
void dfs(int id,bool has7){
	if(id>6){
		int x=0;for(int i=1;i<=6;i++)x=x*10+save[i];prime.push_back(x);return;
	}
	if(id==6&&!has7)save[id]=7,dfs(id+1,1);
	else for(int i=0;i<=9;i++)save[id]=i,dfs(id+1,(i==7)||has7);
}
inline void init(){
	dfs(1,0);
	for(int i=1;i<=limit;i++)
	for(unsigned int j=0;j<prime.size()&&i*prime[j]<=limit;j++)check[i*prime[j]]=inf;
	prime.clear();
	for(int i=1;i<=limit;i++)if(check[i]!=inf)prime.push_back(i),check[i]=prime.size();prime.push_back(limit+1);
}
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	read(t);init();
	while(t--){
		read(x);printf("%d\n",(check[x]==inf)?-1:prime[check[x]]);
	}
	return 0;
}
