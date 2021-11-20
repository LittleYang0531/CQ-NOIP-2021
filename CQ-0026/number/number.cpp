#include <bits/stdc++.h>
using namespace std;
const int N=1e7+1005;
void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9')	s=getchar();
	while(s>='0'&&s<='9')	x=x*10+s-'0',s=getchar();
}
void print(int x){
	if(x>9)	print(x/10);
	putchar(x%10+'0');
}
bool vis[N];
int tag[N];
void init(){
	for(int i=1;i<N;++i){
		int x=i;
		while(x){
			if(x%10==7){
				vis[i]=tag[i]=1;
				break;
			}
			x/=10;
		}
	}
	for(int i=1;i<N;++i){
		if(!vis[i])	continue;
		for(int j=2;i*j<N;++j)
			tag[i*j]=1;
	}
	for(int i=1;i<N;++i)	tag[i]+=tag[i-1];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int T;
	read(T);
	while(T--){
		int x;
		read(x);
		if(tag[x]-tag[x-1]>0){
			puts("-1");
			continue;
		}
		int l=x+1,r=N-1,mid=(l+r)>>1,res;
		while(l<=r){
			if(tag[mid]-tag[x]<mid-x)	r=mid-1,res=mid;
			else	l=mid+1;
			mid=(l+r)>>1;
		}
		print(res),putchar('\n');
	}
	return 0;
}
