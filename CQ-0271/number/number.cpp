#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<set>
#define X 1650000
#define ll long long
using namespace std;
int n,a[200001];
bool p[X+5];
set<int>s;
void read(int &x){
	x=0;
	char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+(c^48);
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}
bool x7(ll m){
	while(m) {
		if(m%10==7) return 1;
		m/=10;
	}
	return 0;
}
void pre() {
	for(ll i=1;i<=X;i++)
	if(!p[i])
		if(x7(i))
			for(ll j=i;j<=X;j+=i)
				p[j]=true;
		else s.insert(i);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(n);
	pre();
	for(int i=1;i<=n;i++){
		read(a[i]);
		if(p[a[i]]) puts("-1");
		else{
			set<int>::iterator it=s.upper_bound(a[i]);
			print(*it);
			puts("");
		}
	}
	return 0;
}
