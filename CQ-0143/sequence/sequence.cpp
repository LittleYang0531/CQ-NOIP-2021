#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int v[31],cnt[110],num[31],ccnt[110];
void dfs(int x,int h){
	if(x>n){
		memset(ccnt,0,sizeof(ccnt));
		int num1=0;
		for(int i=0;i<=h;i++){
			ccnt[i]=cnt[i];
		}
		for(int i=0;i<=h+5;i++){
			if(ccnt[i]%2==1)num1++;
			ccnt[i+1]+=ccnt[i]/2;
		}
		if(num1<=k){
			long long ji=1;
			for(int i=1;i<=n;i++){
				ji=(ji%998244353*v[num[i]])%998244353;
			}
			ans=(ans+ji)%998244353;
		}
		return;
	}
	for(int i=0;i<=m;i++){
		cnt[i]++;
		num[x]=i;
		h=max(h,i);
		dfs(x+1,h);
		cnt[i]--;
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)cin>>v[i];
	dfs(1,0);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
