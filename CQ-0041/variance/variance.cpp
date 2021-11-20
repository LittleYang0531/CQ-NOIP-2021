#include<bits/stdc++.h>
namespace MY_STD{
	#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
	#ifdef GTRAKIOI
	#define defrog(...) fprintf(stderr,__VA_ARGS__)
	#else
	#define defrog(...) 1
	#endif
	
	typedef long long ll;
	typedef std::vector<int>vi;
	typedef std::vector<vi >vvi;
	typedef std::vector<vvi >vvvi;
	typedef std::vector<ll>vll;
	typedef std::vector<vll >vvll;
	typedef std::vector<vvll >vvvll;
	typedef std::pair<int,int>pii;
	#define pb push_back
	#define eb emplace_back
	
	
	const int N=10101,M=998244353;
	int n;
	ll ans=0x3f3f3f3f3f3f3f3fll;
	int a[N],d[N];
	vi fnt,rer;
//	vi memfnt,memrer;
	void dfs(const int&ly){
		if(ly>=n){
//			static int b[N];
//			int mid=fnt.size()+1;
			int s2=0,s=0,cur=0;
//			for(int i=mid-1;i;--i){
//				b[i]=b[i+1]-fnt[mid-i-1];
//			}
			for(const auto&x:fnt){
				cur-=x;
				s2+=cur*cur;
				s+=cur;
			}
			cur=0;
			for(const auto&x:rer){
				cur+=x;
				s2+=cur*cur;
				s+=cur;
			}
			ll res=n*(ll)s2-s*(ll)s;
			if(res<ans){
				ans=res;
//				memfnt=fnt;
//				memrer=rer;
			}
			return;
		}
		fnt.eb(d[ly]);
		dfs(ly+1);
		fnt.pop_back();
		rer.eb(d[ly]);
		dfs(ly+1);
		rer.pop_back();
	}
	
	signed main(){
		File("variance");
		std::cin>>n;
		for(int i=1;i<=n;++i){
			std::cin>>a[i];
			d[i-1]=a[i]-a[i-1];
		}
		std::sort(d+1,d+n);
		dfs(1);
		printf("%lld\n",ans);
//		for(auto x:memfnt)defrog("%d ",x);defrog("\n");
//		for(auto x:memrer)defrog("%d ",x);defrog("\n");
		return 0;
	}
	/*signed main(){
		File("variance");
		std::cin>>n;
		for(int i=1;i<=n;++i){
			std::cin>>a[i];
			d[i-1]=a[i]-a[i-1];
		}
		std::sort(d+1,d+n);
		for(int mid=1,imid;mid<=(imid=n-1-mid);++mid){
			vvll f(n+1,vll(a[n]+1,+oo));
			f[0][0]=0;
			for(int i=1;i<n;++i){
				for(int j=i;~j;--j){
					for(int s1=a[i+1]-a[1];~s1;--s1){
						int s2=a[i+1]-a[1]-s1;
						defrog("%d %d %d %d %d\n",mid,i,j,s1,s2);
						if(j<i&&s2>=d[i])f[j][s1]=f[j][s1]+(imid-(i-j))*ll(s2-d[i]+d[i]*d[i]+1);
						if(j>0&&s1>=d[i])f[j][s1]=std::min(f[j][s1],f[j-1][s1-d[i]]+(mid-j)*ll(s1-d[i]+d[i]*d[i]-1));
					}
				}
			}
			for(int s1=a[n]-a[1];~s1;--s1)ans=std::min(ans,f[mid][s1]);
		}
		printf("%lld\n",ans);
		return 0;
	}*/
}
signed main(){
	return MY_STD::main();
}
