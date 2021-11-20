#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define ll long long
using namespace std;
int t,x[10005005],into[10005005],path[10005005],tot,Max;
bool flag[10005005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> t;
	rep(lzw,1,t){
		cin >> x[lzw];
		Max=max(Max,x[lzw]);
	}
	Max+=1000;
	memset(flag,0,sizeof(flag));
	rep(a,0,1) rep(b,0,9) rep(c,0,9) rep(d,0,9) rep(e,0,9) rep(f,0,9) rep(g,0,9) rep(h,0,9){
		int n=10000000*a+1000000*b+100000*c+10000*d+1000*e+100*f+10*g+h;
		if(n>Max) goto beginning;
		if(b==7 || c==7 || d==7 || e==7 || f==7 || g==7 || h==7) flag[n]=true,path[++tot]=n;
	}
	beginning:;
	/*rep(i,1,tot){
		cout << path[i] << endl;
	}*/
	rep(i,1,tot){
		rep(j,2,Max){
			//cout << tmp << endl;
			ll tmp=path[i]*j;
			if(tmp>Max) break;
			else flag[tmp]=true;
		}
	}
	/*rep(i,1,100){
		if(flag[i]) cout << i << endl;
	}*/
	int _next=Max;
	into[Max]=_next+1;
	for(int i=Max-1;i;i--){
		if(flag[i]) into[i]=_next;
		else {
			into[i]=_next;
			_next=i;
		}
	}
	rep(i,1,t){
		if(flag[x[i]]) cout << -1 << endl;
		else cout << into[x[i]] << endl;
	}
	return 0;
} 
