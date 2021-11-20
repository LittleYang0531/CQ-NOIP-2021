#include<bits/stdc++.h>
using namespace std;
int const MAX=1e7+100;

int T;
int p[MAX+5];

bool check(int x){
	while(x){
		if((x%10)==7){
			p[x]=-1;
			return 1;
		}
		x/=10;
	}
	return 0;
}

void s(int x){
	for(int i=2;i<=(MAX/x);i++){
		p[x*i]=-1;
	}
}

void work(){
	int now=0;
	for(int i=1;i<=MAX;i++){
		if(p[i]==-1) continue;
		if(check(i)){
			s(i);
		}
		else{
			p[now]=i;
			now=i;
		}
	}
	
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	work();
	while(T--){
		int x;
		scanf("%d",&x);
		if(p[x]==-1||p[x]==0){
			printf("-1\n");
		}
		else{
			printf("%d\n",p[x]);
		}
	}
	return 0;
}
// fc number.out number4.ans
