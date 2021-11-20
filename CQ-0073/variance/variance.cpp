#include<bits/stdc++.h>
using namespace std;
typedef long long van;
template<typename T> inline
void read(T& x) {
	T f=1,b=0;char ch=getchar();
	while (!isdigit(ch)) {
		if (ch=='-') f=-1;
		ch=getchar();
	} while (isdigit(ch))
		b*=10,b+=ch^'0',ch=getchar();
	x=f*b;return;
}
template<typename T> inline
void print(T x) {
	if (x<0) putchar('-'),x=-x;
	if (x>9) print(x/10);putchar(x%10^'0');
}
const van MaxN=1e4+10;
van n,a[MaxN];
//struct state {
//	van a[MaxN];
//	bool operator < (const state& to) const {
//		for (int i=1;i<=n;i++) if (a[i]!=to.a[i]) {
//			return a[i]<to.a[i];
//		} return a[n]<to.a[n];
//	}
//};
//map<state,bool> used;
bool update(van id) {
	if (a[id]==a[id+1]+a[id-1]-a[id]) return false;
	a[id]=a[id+1]+a[id-1]-a[id]; return true;
} van ans=1e18;
//void DFS(van now=1,van f=0) {
//	van selfsum=0,mulsum=0;state s;memcpy(s.a,a,sizeof s.a);
//	for (int i=1;i<=n;i++) selfsum+=a[i]*a[i];
//	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) mulsum+=a[i]*a[j];
//	used[s]=1;van tmp=(n-1)*selfsum-2*mulsum;
//	if (tmp<ans) {
//		ans=tmp; cout<<ans<<endl;
//		for (int i=1;i<=n;i++) print(a[i]),putchar(' ');
//		print(tmp),putchar('\n');
//	}
//	for (int i=2;i<n;i++) {
//		if (i==f) continue;
//		van tmp=a[i];if (!update(i)) continue;memcpy(s.a,a,sizeof s.a);
////		for (int j=1;j<=n;j++) cout<<a[j]<<" ";cout<<endl;
//		if (used.find(s)==used.end()) DFS(now+1,i);
//		a[i]=tmp;
//	}
//}
van sum=0;
van calc() {
	van tmp=0;for (int i=1;i<=n;i++) { 
		tmp+=(n-1)*a[i]*a[i];for (int j=i+1;j<=n;j++) 
			tmp-=2*a[i]*a[j];
	} return tmp;
}
void DFS2(van l,van r,bool left=1,bool swaped=false) {
	ans=min(ans,calc());
	if (left) {
		van to=a[l-1]+a[l+1]-a[l];
		sum+=to,sum-=a[l];a[l]=to;
		if (l-1>1&&a[l-2]+a[l]-a[l-1]>a[l-1]) DFS2(l-1,r,!left);
		else {
			for (int i=l+1;n*a[i]<=sum;i++) {
				van nxto=a[i-1]+a[i+1]-a[i];
				if (nxto<=a[i]) continue;
				if (abs(sum-nxto)<abs(sum-a[i])) {
					DFS2(i,r,!left);break;
				}
			}
		}
	} else {
		van to=a[r-1]+a[r+1]-a[r];
		sum+=to,sum-=a[r];a[r]=to;
		if (r+1<n&&a[r+2]+a[r]-a[r+1]>a[r+1]) DFS2(l,r+1,!left);
		else {
			for (int i=r-1;n*a[i]<=sum;i++) {
				van nxto=a[i-1]+a[i+1]-a[i];
				if (nxto<=a[i]) continue;
				if (abs(sum-nxto)<abs(sum-a[i])) {
					DFS2(l,i,!left);break;
				}
			}
		}
	} if (!swaped) DFS2(l,r,!left,true);
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	read(n);for (int i=1;i<=n;i++) read(a[i]);
	ans=calc();for (int i=1;i<=n;i++) sum+=a[i];
	van l=1,r=n;bool lcan=false,rcan=false;
	for (int i=l+1;n*a[i]<=sum;i++) {
		van nxto=a[i-1]+a[i+1]-a[i];
		if (nxto<=a[i]) continue;
		if (a[i-1]+a[i+1]-a[i]>a[i]) {
			l=i;lcan=true;break;
		}
	}
	for (int i=r-1;n*a[i]<=sum;i++) {
		van nxto=a[i-1]+a[i+1]-a[i];
		if (nxto<=a[i]) continue;
		if (a[i-1]+a[i+1]-a[i]<a[i]) {
			r=i;rcan=true;break;
		}
	}
	if (lcan) DFS2(l,r,1);
	if (rcan) DFS2(l,r,0);
	print(min(ans,calc()));
	return 0; 
}

