#include<bits/stdc++.h>
#define MAXN 10000005
#define MAXT 200005
#define max(a,b) a>b?a:b
using namespace std;
inline int read(){
	int sum=0,w=1;
	char ch=getchar();
	while('0'>ch||ch>'9'){if(ch=='-'){w=-1;}ch=getchar();}
	while('0'<=ch&&ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
	return sum*w;
}
int smax;
int t,x;
int ans[MAXN];
bool blog[MAXN];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	t=read();
	blog[0]=false;
	for(int i=1;i<=MAXN;i++){
		int z=i;
		bool flag=false;
		if(blog[i])continue;
		while(z!=0){
			int num=z%10;
			if(num==7){
				flag=true;
				break;
			}
			z/=10;
		}
		if(flag==false)continue;
		blog[i]=true;
		for(int j=2;i*j<=MAXN;j++){
			blog[i*j]=true;
		}
	}
	int sum=0;
	ans[MAXN-5]=MAXN-4;
	sum=MAXN-4;
	for(int i=MAXN-5;i>=0;i--){
		ans[i]=sum;
		if(blog[i]==false){
			sum=i;
		}
	}
	for(int i=1;i<=t;i++){
		x=read();
		if(blog[x]==true){
			puts("-1");
		}else{
			printf("%d\n",ans[x]);
		}
	}
	return 0;
}
