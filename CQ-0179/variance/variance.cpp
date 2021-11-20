#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n,mid;
LL sum,pr=1e18;
LL suan_b(vector<int> a){
	LL ans=0;
	sum=0; for(int i=1;i<=n;i++) sum+=a[i];
	for(int i=1;i<=n;i++) ans=ans+a[i]*a[i]*n-2*a[i]*sum;
	ans=ans+sum*sum;
	return ans;
}
LL a[N];
LL suan(){
	LL ans=0;
	sum=0; for(int i=1;i<=n;i++) sum+=a[i];
	for(int i=1;i<=n;i++) ans=ans+a[i]*a[i]*n-2*a[i]*sum;
	ans=ans+sum*sum;
	return ans;
}
map<vector<int>,bool> vis;
queue<vector<int> > q;
vector<int> b;
void bfs(){
	q.push(b);
	vis[b]=1;
	while(!q.empty()){
		vector<int> u=q.front(); q.pop();
		pr=min(pr,suan_b(u));
		for(int i=2;i<n;i++){
			int t=u[i];
			u[i]=u[i-1]+u[i+1]-u[i];
			if(!vis[u]) vis[u]=1,q.push(u);
			u[i]=t;
		}
	}
}
int main(){// 12
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	b.push_back(0);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),b.push_back(a[i]);
	if(n<=4){
		bfs();
		printf("%lld",pr);
	}
	else{
	suan();
	srand(time(0));
	for(int i=1;i<=100;i++){
		int t=rand()%(n-2)+2;
		a[t]=a[t+1]+a[t-1]-a[t];
	//	cout<<t<<endl;
		pr=min(pr,suan());
	}
	mid=(a[1]+a[n])/2;
	for(int k=1;k<=N;k++){
		int flag=0;
		for(int i=2;i<n;i++){
			int t=a[i-1]+a[i+1]-a[i];
			if(abs(mid-t)<abs(mid-a[i])) a[i]=t,flag=1,pr=min(pr,suan());
		}
//		cout<<pr<<endl;
		if(!flag) break;
	}
	for(int i=1;i<=100;i++){
		int t=rand()%(n-2)+2;
		a[t]=a[t+1]+a[t-1]-a[t];
		pr=min(pr,suan());
	}
//	for(int i=1;i<=n;i++) cout<<a[i]<<endl;
	sum=0; for(int i=1;i<=n;i++) sum+=a[i]; mid=sum/n;
	for(int k=1;k<=N;k++){
		sum=0; for(int i=1;i<=n;i++) sum+=a[i]; mid=sum/n;
		int flag=0;
		for(int i=2;i<n;i++){
			int t=a[i-1]+a[i+1]-a[i];
			if(abs(mid-t)<abs(mid-a[i])) a[i]=t,flag=1,pr=min(pr,suan());
		}
		if(!flag) break;
	}
	printf("%lld",pr);
	}
	return 0;
}
/*
10
6 19 34 35 56 63 82 82 83 99
6 21 34 55 56 63 63 64 81 99

55.9
54.2

105/2= 52
*/
