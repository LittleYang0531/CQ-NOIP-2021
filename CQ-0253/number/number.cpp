#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7+7,maxm=1e7+7;
int T,cnt,num[maxn],id[maxn];
bool vis[maxn];
bool check(int x){
	while(x){
		if(x%10==7)return 1;
		x/=10;
	}
	return 0;
}
int read(){
	int f=1,x=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+ch-48;
		ch=getchar();
	}
	return (f==1)?x:-x;
}
void write(int x){
	if(!x)return ;
	write(x/10);
	putchar((x%10)+'0');
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(vis,0,sizeof(vis));
	for(int i=1;i<maxm;++i){
		if(check(i)){
			for(int j=1;j*i<maxm;j++){
				vis[j*i]=1;
			}
		}
	}
	cnt=0;
	for(int i=1;i<maxm;++i){
		if(!vis[i])num[++cnt]=i,id[i]=cnt;
	}
	int x,l,r,mid,ans;
	scanf("%d",&T);
	while(T--){
//		scanf("%d",&x);
		x=read();
		if(vis[x]==1){
//			printf("-1");
//			write(-1);
			putchar('-');
			putchar('1');
			putchar('\n');
			continue;
		}
//		l=1,r=cnt;
//		while(l<=r){
//			mid=(l+r)>>1;
//			if(num[mid]>x)ans=num[mid],r=mid-1;
//			else l=mid+1;
//		}
//		printf("%d",ans);
//		printf("%d",num[id[x]+1]);
		write(num[id[x]+1]);
		putchar('\n');
	}
	return 0;
}
