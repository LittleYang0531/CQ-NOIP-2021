#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=10001;
vector<int> q[900000];
int n,a[maxn],ans=0x3f3f3f3f;
long long npp=0;
int cafen(){
	int he=0,sum=0;
	for(int i=1;i<=n;i++)
	{
	 	sum+=a[i]*a[i];
	 	he+=a[i];
	}
	return sum*n-he*he;
}
void dfs(){
	for(int i=npp;i>=1;i--)
	{  bool wu=true;
	   for(int j=1;j<=n;j++)
	     if(a[j]!=q[i][j-1]){ wu=false; break;
		 }
		if(wu) return;
    }
    npp++;
    for(int i=1;i<=n;i++){
    	q[npp].push_back(a[i]);
	}
	int temp=cafen();
	if(temp<ans) ans=temp;
	for(int i=2;i<n;i++)
	{
		int tt=a[i];
		int xx=a[i-1]+a[i+1]-a[i];
		if(xx>=a[i-1]&&xx<=a[i+1]&&a[i]!=xx) a[i]=xx;
		dfs();
		a[i]=tt;
	}
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	dfs();
	printf("%d",ans);
	return 0;
}

