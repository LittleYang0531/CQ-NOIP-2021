#include<cstdio>
#include<algorithm>
#include<cstring>  //感谢 
using namespace std;
const int maxn=102;
const int yuu=998244353;
int n,m,k,a[maxn],kk=0,v[maxn]; //a[]坐标  v[]数值 
long long num=1,ans;
int  ll[500];
bool guo[maxn];
bool erj(long long x){ //二进制 个数 
	int sum=0;
	
	while(x>0){
		if(sum>k) return false;
		sum+=x%2;
		ll[kk]=x%2;kk++;
		x/=2;		
	}
	if(sum>k) return false;
	else return true;}
void dfs(int x,int bu){
	if(x>m) return;
	if(bu==n){
		int temp=0,b[maxn],bian=0;
		memset(b,0,sizeof(b));
		for(int i=0;i<=kk+1;i++){	
		    if(a[i]!=0) bian++;
		    b[i]=(a[i]+temp)%2;
			temp=(a[i]+temp)/2;
		}
		for(int i=0;i<=m;i++)
		 {
	//	 	printf("%d:%d   ",i,a[i]);
		 }
		for(int i=0;i<=kk+1;i++)
		 if(ll[i]!=b[i]) return;
		long long   summ=1,kinna=1;
		for(int i=0;i<=m;i++)
		  for(int j=1;j<=a[i];j++)
		 summ=summ*v[i];
		for(int i=n;i>n-bian;i--)
		  kinna*=i;
		for(int i=bian;i>=1;i--)
		  kinna/=i;
	 //	printf("%d %d\n",summ,kinna);
		ans=(ans+kinna*summ%yuu)%yuu;
		return ;
	}
	a[x]++;
	dfs(x,bu+1);// xuan
	a[x]--;
	dfs(x+1,bu);//bu
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)
	 { if(num<=1073741824)
	  num*=2;scanf("%d",&v[i]);}
	num/=2;
	for(long long i=n;i<=n*num;i++)
	{
		kk=0;
		memset(ll,0,sizeof(ll));
		if(!erj(i)) continue;
		dfs(0,0);
	}
	printf("%d",ans);
	return 0;
}

