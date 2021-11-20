// *学爆搜*

// *认识爆搜*

#include<cstdio>
const int maxn=15;
const int maxk=1e5+5;
const int inf=0x3f3f3f3f;
int a[maxn];
bool vis[maxk];
int n,ans=inf,s1,s2;
void dfs(void);
inline int min(int x,int y){ return x<y?x:y; }
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);	// *输入*
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s1=s1*10+a[i]; 
	}
	vis[s1]=1; dfs();	// *搜索*
	printf("%d",ans); // *输出* 
	return 0;
}
inline void ptt(void){	// potato (?)
	s1=s2=0;
	for(int i=1;i<=n;++i)
		s1+=a[i], s2+=a[i]*a[i];
	ans=min(ans,n*s2-s1*s1);
	return;
}
void dfs(void){	// *加亿、细节* 
	ptt();
	for(int i=2;i<n;++i){
		int t=a[i], u=0;
		a[i]=a[i-1]+a[i+1]-a[i];
		for(int j=1;j<=n;++j)
			u=u*10+a[j];
		if(!vis[u]) vis[u]=1, dfs();
		a[i]=t;
	}
	return;
}

// *你学会了吗？* 
