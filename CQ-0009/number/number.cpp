#include<stdio.h>
#define R register int
#define N 10000002
bool tag[N];
int ans[N],pw[7];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pw[0]=1;
	for(R i=1;i!=7;i++){
		pw[i]=pw[i-1]*10;
	}
	for(R i=0;i!=7;i++){
		for(R j=pw[i]-1;j!=-1;j--){
			for(R k=pw[6-i]-1;k!=-1;k--){
				tag[7*pw[i]+j+k*pw[i+1]]=true;
			}
		}
	}
	int t,x=N-1;
	for(R i=7;i!=N;i++){
		if(tag[i]==true){
			for(R j=i<<1;j<N;j+=i){
				tag[j]=true;
			}
		}
	}
	for(R i=N-2;i!=0;i--){
		if(tag[i]==false){
			ans[i]=x;
			x=i;
		}
	}
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		scanf("%d",&x);
		if(tag[x]==true){
			puts("-1");
		}else{
			printf("%d\n",ans[x]);
		}
	}
	return 0;
}
