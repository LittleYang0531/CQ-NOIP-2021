#include<bits/stdc++.h>

using namespace std;
int T,maxn;
int num[10000010],cnt;
int vis[10000010];
int a[10000010];
int check(int x){
	int l=1,r=cnt;
	while(l<=r){
		int mid=(l+r)/2;
		if(num[mid]>=x){
			r=mid-1;
		}
		else l=mid+1;
	}
	return r+1;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	for(int i=1;i<=T;i++){
		int x;
		cin>>x;
		a[i]=x;
		maxn=max(x,maxn);
	}
	
	maxn=max(maxn,10000);
	
	if(maxn>200000) maxn=maxn+1000;
	else if(maxn>10000) maxn=200000;

	for(int i=7;i<=maxn;i++){
		int now=i,sum=0;
		if(vis[now]) continue;
		int w=log10(i),flag=0,k=now;
		w++;
		
		if(w>=8){
			if(k/(10000000)==7)
				flag=1;
			k=k%(10000000);	
		}
		
		if(w>=7){
			if(k/(1000000)==7)
				flag=1;
			k=k%(1000000);	
		}
		
		if(w>=6){
			if(k/(100000)==7)
				flag=1;
			k=k%(100000);	
		}
		if(w>=5){
			if(k/(10000)==7)
				flag=1;
			k=k%(10000);	
		}
		
		if(w>=4){
			if(k/(1000)==7)
				flag=1;
			k=k%(1000);	
		}
		
		if(w>=3){
			if(k/(100)==7)
				flag=1;
			k=k%(100);	
		}
		
		if(w>=2){
			if(k/(10*1)==7)
				flag=1;
			k=k%(10*1);	
		}
		
		if(w>=1){
			if(k==7)
				flag=1;
		}
		if(flag==0) continue;
		while(1){
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//1
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//2
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//3
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//4
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//5
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//6
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//7
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//8
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//9
			
			++sum;
			if(now*sum>maxn) break;
			if(vis[now*sum]==0){
				num[++cnt]=now*sum;
				vis[num[cnt]]=1;
			}//10
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=1;i<=T;i++){
		int x;
		x=a[i];
		if(vis[x]){
			cout<<-1<<'\n';
			continue;
		}
		
		int k=1;
		int n=check(x);
		while(x+k==num[n+k-1]) k++;
		
		cout<<x+k<<'\n';
	}
}
