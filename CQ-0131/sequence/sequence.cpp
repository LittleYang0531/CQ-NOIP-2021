#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int sss=0;
	char chh=getchar();
	while(chh<'0'||chh>'9') chh=getchar();
	while(chh>='0'&&chh<='9'){
		sss=sss*10+chh-'0';
		chh=getchar();
	}
	return sss;
}
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
const int mod=998244353;
int n,m,k;
int v[105];
int a[105];
int ans=0;
bool check(int pos){
	return m-pos>=n-2;
}
void calc(int pos){
	int add=v[pos];
	for(register int i=pos;i<=pos+m-2;i++){
		add=(add*v[pos])%mod;
	}
	ans=(ans+add)%mod;
}
void change_ans(){
	int add=1;
	for(register int i=0;i<=m;i++){
		if(a[i]) add=(add*v[i])%mod; 
	}
	ans=(ans+add)%mod;
}
void dfs(int now,int cnt){
	if(m-now+1<n-cnt) return;
	if(now==m+1){
		change_ans();
		return;
	}
	a[now]=1;
	dfs(now+1,cnt+1);
	a[now]=0;
	dfs(now+1,cnt);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(register int i=0;i<=m;i++){
		v[i]=read();
	}
	if(k==1){
		for(register int i=0;i<=m;i++){
			if(check(i)) calc(i);
		}
		cout<<ans;
		return 0;
	}
	else if(k==n){
		a[0]=1;
		dfs(1,1);
		a[0]=0;
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	return 0;
}
/*
I love zlj forever!!! 
*/
