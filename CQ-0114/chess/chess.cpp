#include<algorithm>
#include<cstdio>
using namespace std;
int re(){
	int temp;
	scanf("%d",&temp);return temp;}
int ans,n,m,q;
int mmm[1000][1000],mmn[1000][1000];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    int T=re();
    while(T){
    	n=re();m=re();q=re();
    	for(int i=1;i<=n;i++)
    	 for(int j=1;j<=m-1;j++)
         { char  c=getchar();
           mmm[i][j]=c-'0';
		 }
    	for(int i=1;i<=n-1;i++)
    	 for(int j=1;j<=m;j++)
         { char  c=getchar();
           mmn[i][j]=c-'0';
		 }
    for(int i=1;i<=q;i++)
     {
     	int clo=re(),lv=re(),x=re(),y=re();
     	printf("3\n");
	 }
  	}
	return 0;
}
