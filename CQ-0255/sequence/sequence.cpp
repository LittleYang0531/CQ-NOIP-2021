#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')x=x*10+(ch^48),ch=getchar();
	return x*f;
}
using bs=bitset<105>;
const int xzj=998244353;
int v[105];
int n,m,k,ans;
bs sit;
void dfs(int x,int cnt,int lb){
	if(x==n){
		if(lb<=k)ans=(1ll*ans+cnt)%xzj;
		return;
	}
	bs buf=sit;
	for(int i=0;i<=m;++i){
		if(sit[i]==0){
			sit[i]=1;
			dfs(x+1,cnt*1ll*v[i]%xzj,lb+1);
			sit[i]=0;
		}
		else{
			if(i==0||sit[i-1]==0){
				int j=i;
				for(;buf[j];++j)buf[j]=0,--lb;buf[j]=1,++lb;
				swap(sit,buf);
				dfs(x+1,cnt*1ll*v[i]%xzj,lb);
				swap(sit,buf);
			}
			else{
				swap(sit,buf);
				buf[i-1]=1,++lb;
				dfs(x+1,cnt*1ll*v[i]%xzj,lb);
				swap(sit,buf);
			}
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i)v[i]=read();
	dfs(0,1,0);
	cout<<ans;
	return 0;
}
