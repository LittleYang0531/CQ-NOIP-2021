#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int t;
ll xx,x;
int cnt,flag,tot2,vis[N],tot,vis2[N];
ll jl2[N],jl[N];
void dfs(int y){
	if(flag)return;
	if(y==tot2+1){
		if(!cnt)return;
		ll xxx=xx;
		while(xxx){
			int bj=xxx%10;
			if(bj==7){
				flag=1;
				break;
			}
			xxx/=10;
		}
		return;
	}
	cnt++;
	xx*=jl2[y];
	y++;
	dfs(y);
	y--;
	xx/=jl2[y];
	cnt--;
	y++;
	dfs(y);
	y--;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	ll nn=N-3;
	ll n2=sqrt(nn);
	for(int i=2;i*i<=n2;i++){
		if(vis2[i])continue;
		for(int j=i;i*j<=n2;j++){
			vis2[i*j]=1;
		}
	}
	for(ll i=2;i<=n2;i++){
		if(!vis2[i])jl[++tot]=i;
	}
	for(ll i=7;i<=nn;i++){
		if(vis[i])continue;
		tot2=0;
		ll n3=sqrt(i),n4=i;
		for(int j=1;j<=tot;j++){
			if(jl[j]>n3)break;
			while(n4%jl[j]==0){
				n4/=jl[j];
				jl2[++tot2]=jl[j];
			}
			if(n4==1)break;
		}
		if(n4!=1){
			jl2[++tot2]=n4;
		}
		flag=cnt=0;
		xx=1;
		dfs(1);
		if(flag){
			vis[i]=1;
			for(int j=2;j*i<=nn;j++){
				vis[j*i]=1;
			}	
		}
	}
	while(t--){
		scanf("%lld",&x);
		if(x<=nn){
			if(vis[x]){
				printf("-1\n");
				continue;
			}
		}
		else{
			ll n3=sqrt(x),n4=x;
			tot2=0;
			for(int j=1;j<=tot;j++){
				if(jl[j]>n3)break;
				while(n4%jl[j]==0){
					n4/=jl[j];
					jl2[++tot2]=jl[j];
				}
				if(n4==1)break;
			}
			if(n4!=1){
				jl2[++tot2]=n4;
			}
			flag=cnt=0;
			xx=1;
			dfs(1);
			if(flag){
				printf("-1\n");
				continue;
			}
		}
		ll flag2=0;
		for(int i=x+1;i<=nn;i++){
			if(!vis[i]){
				flag2=i;
				break;
			}
		}
		if(flag2){
			printf("%lld\n",flag2);
			continue;
		}
		ll flag3=max(x,nn);
		for(ll i=flag3+1;;i++){
			ll n3=sqrt(i),n4=i;
			tot2=0;
			for(int j=1;j<=tot;j++){
				if(jl[j]>n3)break;
				while(n4%jl[j]==0){
					n4/=jl[j];
					jl2[++tot2]=jl[j];
				}
				if(n4==1)break;
			}
			if(n4!=1){
				jl2[++tot2]=n4;
			}
			flag=cnt=0;
			xx=1;
			dfs(1);
			if(!flag){
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}
