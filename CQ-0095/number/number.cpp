#include<bits/stdc++.h>
using namespace std;
#define ll int
const int inf=200010;
//const int inf=100; 
bool vis[inf+5]={0};
bool vt[inf+5]={0};
int zhi[inf+5],tt=0;
int nu[inf],tot=0;
int ans[inf];
bool check(int x) {
	while(x) {
		if(x%10==7)
			return 0;
		x/=10;
	}
	return 1;
}
void inti() {
	int i,j,t;
	bool p;
	for(i=2;i<=inf;++i) {
		if(!vt[i]) {//是质数的话 
			zhi[++tt]=i;
		}
		for(j=1;j<=tt;++j) {
			t=i*zhi[j];
			if(t>inf)
				break;
			vt[t]=1;
			if(i%zhi[j]==0)
				break;
		}
	}
	for(i=1;i<=inf;++i) {
		p=check(i);
		if(p==0) {
			vis[i]=1;
			for(j=2;j<=tt;++j) {
				if(j*i>inf)
					break;
				vis[j*i]=1;
			}
		}
		if(vis[i]==1)
			nu[++tot]=i;
	}
	ans[tot]=nu[tot]+1;
	for(i=tot-1;i>=1;--i) {
		if(nu[i]+1==nu[i+1])
			ans[i]=ans[i+1];
		else
			ans[i]=nu[i]+1;
	}
	return;
}
inline void ask(int &x) {
	int nl,nr,mid;
	nl=1,nr=tot;
	while(nl<=nr) {
		mid=(nl+nr)>>1;
		if(nu[mid]>x) {
			nr=mid-1;
		}
		else
			nl=mid+1;
//		printf("[%d %d] %d\n",nl,nr,nu[mid]);
	}
//	printf("%d %d\n",nu[nl],x);
	if(nu[nl]==x+1)
		x=ans[nl];
	else
		x=x+1;
	return;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("number4.in","r",stdin);
//	freopen("number4.out","w",stdout);
	int T,x;
	inti();
	scanf("%d",&T);
//	printf("?\n");
//	int i;
//	for(i=1;i<=70;++i)
//		printf("[]%d %d\n",nu[i],ans[i]);
	while(T--) {
		scanf("%d",&x);
		if(vis[x]==1) {//判断是否为包含7或是其倍数的 
			printf("-1\n");
			continue;
		}
		ask(x);
		printf("%d\n",x);
	}
	return 0;
}
