#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){ll a=0;int b=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9'){a=(a<<1)+(a<<3)+(c^48);c=getchar();}return a*b;}
const int MAX_N = 2e5 + 9;
const int MAX_X_VAL = 1e7 + 9;
int T;
int x[MAX_N];
bool qwq[MAX_X_VAL];
inline bool check1(int x){
	while(x){
		if(x % 10 == 7) return 1;
		x /= 10;
	}
	return 0;
}
inline bool check2(int x){
	for(int i=2;(i*i)<=x;++i) if(x%i==0) if(qwq[i] || qwq[x/i]) return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T = read();
	for(int i=1;i<=T;++i) x[i] = read();
	for(int i=1;i<=10000000;++i) qwq[i] = check1(i);
	for(int i=1;i<=T;++i){
		if(qwq[x[i]] || check2(x[i])) puts("-1"),qwq[x[i]] = 1;
		else for(int j=x[i]+1;;++j){
			if(qwq[j]) continue;
			if(check2(j)) {qwq[j] = 1;continue;}
			cout << j << endl;
			break;
		}
	}
//	cout <<"Time:" << clock() << "ms.";
	return 0;
}
