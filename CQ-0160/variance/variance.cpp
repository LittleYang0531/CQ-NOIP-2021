#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll

ll Abs(ll a){
	if(a<0ll) return -a;
	return a;
}

int n;
int a[10005];
int b[10005];

map<vector<int>,bool> m;

ll Find(){
	ll sum=0,now=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	for(int i=1;i<=n;i++) now+=(sum-a[i]*n)*(sum-a[i]*n);
	return now/n;
}

bool Check(){
	
	vector<int> v;
	for(int i=1;i<=n;i++) v.push_back(a[i]);
	if(m[v]) return 1;
	m[v]=1;return 0;
}

ll ans;

void File(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
}

signed main(){
	File();
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ans=Find();
	for(int id=1;id<=n-1;id++){
		while(1){
			int sum=0,now=0,f=0;
			for(int i=1;i<=n;i++) sum+=a[i];
			for(int i=1;i<=n;i++) b[i]=a[i]*n;
			int id=lower_bound(b+1,b+n+1,sum)-b;
			if(b[id]!=sum) id--;
			for(int i=2;i<=id;i++) if(a[i]<a[i-1]+a[i+1]-a[i]) f=1,a[i]=a[i-1]+a[i+1]-a[i];
			for(int i=id+1;i<=n-1;i++) if(a[i]>a[i-1]+a[i+1]-a[i]) f=1,a[i]=a[i-1]+a[i+1]-a[i];
			if(!f||Check())	break;	
			ans=min(ans,Find());
		}
		m.clear();
	}
	printf("%lld",ans);
	return 0;
}
