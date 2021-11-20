#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Max=998244353;
int n,m,k,qz=0;
struct node{
	int tnum,anum;
	int ass[105];
}nums[105][105];
int ms[105];
inline void add(int a,int b,int c){
	int k=0;
	sort(nums[a][b].ass+1,nums[a][b].ass+1+nums[a][b].anum);
	for(int i=1;i<=nums[a][b].anum;i++){
		if(nums[a][b].ass[i]==c+k) {
			nums[a][b].ass[i]=Max+1;
			k++;
			continue;
		}
		if(nums[a][b].ass[i]!=c+k&&k>0) break;
	}
	nums[a][b].ass[++nums[a][b].anum]=c+k;
	sort(nums[a][b].ass+1,nums[a][b].ass+1+nums[a][b].anum);
	nums[a][b].anum-=k;
}
inline void first(){
	for(int i=2;i<=m+1;i++){
		nums[1][i].tnum=1,nums[1][i].ass[1]=ms[i],nums[1][i].anum=1;
	}
	for(int i=1;i<=m+1;i++){
		for(int j=i;j<=i+n&&j<=m+1;j++){
			nums[i][j].anum=nums[i][j-1].anum,nums[i][j].tnum=nums[i][j-1].tnum;
			for(int a=1;a<=nums[i][j].anum;a++)
				nums[i][j].ass[a]=nums[i][j-1].ass[a];
			add(i,j,ms[j]);
		}
	}
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=m+1;i++) scanf("%d",&ms[i]);
	first();
	for(int i=1;i<=m+1;i++){
		for(int j=i;j<=i+n&&j<=m+1;j++){
			if(nums[i][j].anum<=k){
				int a=1;
				for(int p=1;p<=nums[i][j].anum;p++){
					a*=nums[i][j].ass[i]%Max;
				}
				qz+=a%Max;
				qz%=Max;
			}
		}
	}
	printf("%d",qz);
	
	return 0;
}
//AF NOIP
