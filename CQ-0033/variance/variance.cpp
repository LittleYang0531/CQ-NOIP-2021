#include<bits/stdc++.h>
using namespace std;
# define ll long long
# define read read1<ll>()
# define Type template<typename T>
Type T read1(){
	T t=0;bool vis=0;
	char k;
	do (k=getchar())=='-'&&(vis=1);while('0'>k||k>'9');
	while('0'<=k&&k<='9')t=(t<<3)+(t<<1)+(k^'0'),k=getchar();
	return vis?-t:t;
}
# define fre(k) freopen(k".in","r",stdin);freopen(k".out","w",stdout)
int a[10005],s,b[10005];
ll f[105][105][10005];
ll P2(ll x){return x*x;}
ll sol(){
	ll t=0,ans=0;
	for(int i=1;i<=s;++i)t+=a[i];
	for(int i=1;i<=s;++i)ans+=a[i]*a[i]*s-2*a[i]*t;
	return ans+P2(t);
}
int main(){fre("variance");
	s=read;
	for(int i=1;i<=s;++i)a[i]=read-(i>1?a[1]:0);
	a[1]=0;
	for(int i=1;i<s;++i)b[i]=a[i+1]-a[i];
	sort(b+1,b+s);reverse(b+1,b+s);
	if(s<=20){ll ans=9e18;
		for(int j=0;j<(1<<s-1);++j){
			int l=1,r=s;
			for(int i=0;i+1<s;++i)
				if(j>>i&1)a[l+1]=a[l]+b[i+1],++l;
				else a[r-1]=a[r]-b[i+1],--r;
			ans=min(ans,sol());
		}cout<<ans;
		return 0;
	}
	if(*max_element(a+1,a+s+1)<=100){
		memset(f,0x7f>>1,sizeof(f));
		ll Lmax=f[0][0][0];
		f[0][0][a[s]]=P2(a[s]);
		int t=0,sum=0,w=0;ll ans=9e18;
		for(int i=1;i+1<s;++i){sum+=a[s];
			if(b[i]==0){w=s-1-i;break;}
			for(int j=sum;~j;--j)
				for(int k=0;k<=t;++k)
					if(f[k][t-k][j]!=Lmax){
						int lv=k+b[i];
						f[lv][t-k][j+lv]=min(f[lv][t-k][j+lv],f[k][t-k][j]+P2(lv));
						lv=t-k+b[i];
						f[k][lv][j+a[s]-lv]=min(f[k][lv][j+a[s]-lv],f[k][t-k][j]+P2(a[s]-lv));
					}
			t+=b[i];
		}//cerr<<t<<endl;
		sum+=a[s];
		for(int j=sum;~j;--j)
			for(int k=0;k<=t;++k)
				if(f[k][t-k][j]!=Lmax)
					ans=min(ans,(f[k][t-k][j]+P2(k)*w)*s-P2(j+1ll*k*w));
		cout<<ans;
		return 0;
	}cout<<sol();
	return 0;
}
/*
4
1 2 4 6
*/
