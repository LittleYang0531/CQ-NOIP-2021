#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<ctime>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
#define LL long long
int n,BB,a[10005],pos[10005],len,b[10005];
LL ans=1e18,s1,s2;
map<int,int>H[10005];
map<string,bool>OK;
void dfs(int x,int lst){
	LL S1=0,S2=0;
	string HH;
	for(int i=1;i<=n;i++){
		S1+=a[i]*a[i];
		S2+=a[i];
		HH+=to_string(a[i]);
		HH+='_';
//		cout<<a[i]<<" ";
	}
//	cout<<endl;
	LL now=n*S1-S2*S2;
	if(H[x][now]||OK[HH])return ;
	H[x][now]++;
	OK[HH]=1;
	ans=min(ans,now);
	if(x==BB)return ;
	for(int i=2;i<=n-1;i++){
		if(lst==i)continue;
		int tmp=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		pos[++len]=now;
		dfs(x+1,i);
		--len;
		a[i]=tmp;
	}
}
LL calc(){
	return n*s1-s2*s2;
}
void turn(int Id,int val){
	s1-=a[Id]*a[Id];
	s2-=a[Id];
	a[Id]=val;
	s1+=a[Id]*a[Id];
	s2+=a[Id];
}
void luangao1(){
	LL nowres=calc();
	int cs=50000;
	while(cs--){
		int x=rand()%n+1;
		if(x==1)x++;
		if(x==n)x--; 
		int tmp=a[x];
		turn(x,a[x-1]+a[x+1]-tmp);
		LL Now=calc();
		if(Now<nowres){
			nowres=Now;
			for(int k=1;k<=n;k++)b[k]=a[k];
		}
		int Cs=20;
		while(Cs--){
			for(int i=2;i<n;i++){
				int tmp=a[i];
				turn(i,a[i-1]+a[i+1]-tmp);
				LL Now=calc();
				if(Now<nowres){
					nowres=Now;
					for(int k=1;k<=n;k++)b[k]=a[k];
				}
				else turn(i,tmp);
			}	
		}
	}
	ans=min(ans,nowres);
	for(int i=1;i<=n;i++)a[i]=b[i];
	BB=3;
	dfs(1,0);
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	srand(time(0));
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),s1+=a[i]*a[i],s2+=a[i];
	if(n<=15){
		BB=min(30,2*n+1);
		dfs(1,0);
	}
	luangao1();
	printf("%lld\n",ans);
	return 0;
}
/*
*/
