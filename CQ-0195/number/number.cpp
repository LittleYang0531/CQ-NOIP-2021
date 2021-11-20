#include<bits/stdc++.h>
using namespace std;
int t,n,p,tot=1,to=0,la=1;
bool a[10000007],b[10000007];
int ans[10000007],n7[10000007];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	memset(a,true,sizeof(a));
	ans[0]=-1;
	while(t--){
		scanf("%d",&n);
		p=n;
		while(ans[p]==0){
			tot++;
			if ((tot%10)==7 || (tot/10%10)==7 || (tot/100%10==7) ||
			(tot/1000%10)==7 || (tot/10000%10)==7 || (tot/100000%10)==7 ||
			(tot/1000000%10)==7){
				b[tot]=true;
				a[tot]=false;
				n7[++to]=tot;
				for (int i=2;i<=n;i++){
					if (tot*i>10000000) break;
					a[tot*i]=false;
				}
			}
			if (a[tot]==false){
				ans[tot]=-1;
			}
			else{
				ans[la]=tot,la=tot;
				for (int i=1;i<=to;i++){
					if (tot*n7[i]>10000000) break;
					a[tot*n7[i]]=false;
				}
			}
		}
		printf("%d\n",ans[p]);
	}
	
}
