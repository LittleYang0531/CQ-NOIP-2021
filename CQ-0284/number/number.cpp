#include<bits/stdc++.h>
using namespace std;
long long n,cnt;
struct thy{
	int num,id;
}x[200002];
long long ans[200002],k[200002];
int cmp(thy a,thy b){
	return a.num<b.num;
}
int js(int a){
	for(int i=10000000;i>=1;i=i/10){
		if(a>=i){
			if(a/i==7) return 1;
			else a=a-(a/i)*i;
		}
		else continue;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i].num);
		x[i].id=i;
	}
	sort(x+1,x+1+n,cmp);
	for(int i=1;i<=x[n].num+20;i++){
		if(js(i)==1) k[++cnt]=i;
	}
	for(int i=1;i<=n;i++){
		int w=0,jb=0,jj=0;
		for(int j=1;j<=cnt;j++){
			if(x[i].num%k[j]==0){
				ans[x[i].id]=-1;
				w=1;
				break;
			}
		}
		if(w==0){
			while(jb==0){
				jj=0;
				x[i].num++;
				for(int j=1;j<=cnt;j++){
					if(x[i].num%k[j]==0) break;
					else jj++;
				}
				if(jj==cnt){
					jb=1;
					ans[x[i].id]=x[i].num;
				}
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}
