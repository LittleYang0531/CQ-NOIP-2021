#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<ctime>
#include<map>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,K,v[105],power[105][105],dp[105][32][32][32],ans,C[505][505];
const int mod=998244353; 
int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y;
}
int dec(int x,int y){
	return x-y<0?x-y+mod:x-y;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),K=read();
	for(int i=1;i<=m+1;i++)v[i]=read();
	for(int i=1;i<=m+1;i++){
		power[i][0]=1;
		for(int j=1;j<=n;j++)power[i][j]=1ll*power[i][j-1]*v[i]%mod;
	} 
	C[0][0]=1;
	for(int i=1;i<=500;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=add(C[i-1][j],C[i-1][j-1]);
		}
	}
	dp[0][0][0][0]=1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=K;k++){
				for(int l=0;l<=n;l++){
					if(dp[i][j][k][l]){
						for(int p=0;p<=n-j;p++){
							int nowones=l+p;
							if(k+(nowones%2)<=K)
							{
								dp[i+1][j+p][k+(nowones%2)][nowones/2]=add(dp[i+1][j+p][k+(nowones%2)][nowones/2],1ll*dp[i][j][k][l]*power[i+1][p]%mod*C[n-j][p]%mod);
							}
						}
					}
				} 
			}
		}
	}
	for(int i=0;i<=K;i++){
		for(int j=0;j<=n;j++){
			if(dp[m+1][n][i][j]){
				int now=i,jw=j;
				while(jw){
					if(jw%2==1)now++;
					jw/=2;
				}
				if(now<=K){
					ans=add(ans,dp[m+1][n][i][j]);
				}
			} 
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
5 1 1 2 1
设 dp[i][j][k] 表示算了前i个，cnti之和为j，当前1的个数为k，进位个数为l的贡献之和
100*30*30*30 
*/
