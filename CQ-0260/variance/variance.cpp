#include<iostream>  //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
using namespace std;
int n,a[10005],ans,b[10005];
bool pd[10000005],ppd[10000005],pdd[10000005];
int fc(int e[]){
	double pj=0,ans=0;
	for(int i=1;i<=n;i++){
		pj+=e[i];
	}
	pj=pj/n;
	for(int i=1;i<=n;i++){
		ans+=(e[i]-pj)*(e[i]-pj);
	}
	ans=ans*n;
	return ans;
}
int dfs(int sl[],int la,double pj){
	int cc=fc(sl);
	int p=pj*n;
	if(pd[cc]&&ppd[p]&&pdd[cc+p]) return 0;
//	printf("\n\n\n");
//	for(int i=1;i<=n;i++) printf("%d ",sl[i]);
//	printf("\n%d %.1llf %d %d\n\n",la,pj,cc,ans);
	pd[cc]=1;
	ppd[p]=1;
	pdd[cc+p]=1;
	if(cc<ans) ans=cc;
	int c=sl[la-1];
	if(la-2>=1){
		sl[la-1]=sl[la]+sl[la-2]-sl[la-1];
		pj-=1.0*(c-sl[la-1])/n;
		dfs(sl,la-1,pj);
		pj+=1.0*(c-sl[la-1])/n;
		sl[la-1]=c;
	}
	
	
	if(la+2<=n){
		c=sl[la+1];
		sl[la+1]=sl[la]+sl[la+2]-sl[la+1];
//		pj=(pj*n-c+sl[la+1])/n;
		pj-=1.0*(c-sl[la+1])/n;
		dfs(sl,la+1,pj);
		pj+=1.0*(c-sl[la+1])/n;
		sl[la+1]=c;
	}
	return 0;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	double pj=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pj+=a[i];
	}
//	ans=fc(a,pj);
	ans=fc(a);
	memcpy(b,a,sizeof(a));
	for(int i=2;i<n;i++){
		a[i]=b[i+1]+b[i-1]-b[i];
		pj=pj+a[i]-b[i];
		dfs(a,i,pj/n);
		pj=pj+b[i]-a[i];
		a[i]=b[i];
	}
	cout<<ans;
	return 0;
}
