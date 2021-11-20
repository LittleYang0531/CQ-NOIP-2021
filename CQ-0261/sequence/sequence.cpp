#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){ll a=0;int b=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9'){a=(a<<1)+(a<<3)+(c^48);c=getchar();}return a*b;}
int n,m,k;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(1u * time(0));
	cout << 1ll * rand() * rand() % 998244353;
//	cout <<"Time:" << clock() << "ms.";
	return 0;
}
