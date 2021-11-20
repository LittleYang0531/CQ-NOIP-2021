#include<bits/stdc++.h>
using namespace std;
char ch=' ';
inline int read(){
	int x=0,f=1;
	while(!(ch>='0'&&ch<='9'||ch=='-')){
		ch=getchar();
	}
	if(ch=='-'){
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9){
		write(x/10);
	}
	putchar((x%10)^48);
}
const int maxx=10000105;
bool cc[maxx],cc2[maxx];
int num[maxx];//先前不能报的数
int ans[maxx];
int np;//最后能报出的数 
bool check(int x){
	if(x%7==0){
		return 1;
	}
	while(x){
		if(x%10==7) return 1;
		x/=10;
	}
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i=1;i<=maxx-5;i++){
		if(check(i)){
			num[++num[0]]=i;
			cc[i]=cc2[i]=1;
		}
	}
	np=num[0];
	for(int i=2;i<=maxx-5;i++){
		int p=i;
		while(num[np]*p>maxx-5){
			np--;
		}
		for(int j=1;j<=np;j++){
			cc[num[j]*p]=1;
		}
	}
	int bj=2e9;
	for(int i=maxx-5;i;i--){
		ans[i]=bj;
		if(cc[i]==0) bj=i;
	}
	int n;
	n=read();
	while(n--){
		int x;
		x=read();
		if(cc[x]){
			printf("-1\n");
		}
		else{
			write(ans[x]);
			printf("\n");
		}
	}
	return 0;
}
//AFO
