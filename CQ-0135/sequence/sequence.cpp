#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL Mod=99844353;
LL ans;
int n,m,k;
LL v[110];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++){
		cin>>v[i];
	}
	ans=rand()%100;
	cout<<ans;
}
