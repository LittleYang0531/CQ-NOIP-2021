#include<bits/stdc++.h>
using namespace std;

int T,ans;
vector<int> num;
bool Vis[10001000];

bool check(int x){
	while(x>0){
		if((x%10)==7)return 1;
		x/=10;
	}
	return 0;
}

inline int read(){
	int ret=0,f=1; char ch=getchar();
	while(!isdigit(ch)){ if(ch=='-') f=-1; ch=getchar(); }
	while(isdigit(ch)) ret=(ret<<1)+(ret<<3)+ch-'0',ch=getchar();
	return ret*f;
}

void find(int x){
	int l=0,r=num.size()-1,mid,ret=0;
	bool flag=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(num[mid]>x) r=mid-1,ret=mid;
		else l=mid+1;
	}
	for(int i=ret;~i;i--){
		if(num[i]<x) break;
		if(num[i]==x){ flag=true; break;}
	}
	if(!flag) ans=-1;
	else ans=num[ret];
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	T=read();
	for(int i=1;i<=10000100;i++){
		if(Vis[i]) continue;
		if(check(i)) for(int j=1;j*i<=10000100;j++) Vis[j*i]=true;
		if(!Vis[i]) num.push_back(i);
	}
	while(T--){
		int x=read(); ans=0;
		find(x);
		printf("%d\n",ans);
	}
	return 0;
}
/*Hope I can AK NOIP2021!!
RP++!!;
I'm ¹í»°Á¬Æª£¡£¡ 
Besides,Fuck CCF!!(the most important!
*/
