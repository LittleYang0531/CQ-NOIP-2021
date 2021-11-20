#include<bits/stdc++.h>
#define RI register int
using namespace std;
const int N=11000000;
template<typename T>
void Read(T &t){
	t=0;
	int f=1;
	char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	while(c>='0'&&c<='9')(t*=10)+=c-'0',c=getchar();
	t*=f;
}
int tot,a[N],vis[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(RI i=1;i<=N;i++){
		int zc=i;
		if(vis[zc]==1)continue;
		if(zc%7==0){
			for(RI j=1;j*i<=N;j++){
				vis[j*i]=1;
			}
		}
		else{
			int flag=0;
			while(zc){
				if(zc%10==7){
					flag=1;
					break;
				}
				zc/=10;
			}
			if(flag==1){
				for(RI j=1;j*i<=N;j++){
					vis[j*i]=1;
				}
			}
		}
	}
	for(RI i=1;i<=N;i++){
		if(vis[i]==0)a[++tot]=i;
	}
	int T,x;
	Read(T);
	while(T--){
		Read(x);
		int zcc=upper_bound(a+1,a+1+tot,x)-a;
		if(vis[x]==1)puts("-1");
		else printf("%d\n",a[zcc]);
	}
	return 0;
}
