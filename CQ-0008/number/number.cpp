#include<iostream>
#include<cstdio>
using namespace std;
#define N 10000012
bool vis[N],P[N];int Q,nx[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<N;i++)P[i]=(i%10==7)||P[i/10];
	for(int i=1;i<N;i++)if(P[i])for(int j=i;j<N;j+=i)vis[j]=1;
	for(int i=N-1,v=N;i>=1;i--){nx[i]=v;if(!vis[i])v=i;}
	scanf("%d",&Q);int x;while(Q--){scanf("%d",&x);printf("%d\n",vis[x]?(-1):nx[x]);}return 0;
}
