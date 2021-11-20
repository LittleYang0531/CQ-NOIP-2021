#include<iostream>  //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
using namespace std;
int read(){
	int w=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';
		c=getchar();
	}
	return w;
}
int t;
int pd[300010];
bool s[300010];
int dfs(int x,bool p,int w){
	if(w==6){
		if(x<=300000&&p){
			s[x]=1;
			pd[x]=1;
		}
		return 0;
	}
	for(int i=0;i<=9;i++){
		if(i==7) dfs(x*10+7,1,w+1);
		else dfs(x*10+i,p,w+1);
	}
	return 0;
}
int setup(){
	for(int i=7;i<=300000;i+=7){
		s[i]=1;
		pd[i]=1;
	}
	dfs(0,0,0);
	return 0;
}
int cx(int x){
	bool p=0;
	for(int i=1;i<=x;i++){
		if(x%i==0){
			if(s[i]){
				p=1;
				break;
			}
		}
	}
	return p;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	setup();
	t=read();
	while(t--){
		int x;
		x=read();
		if(cx(x)){
			pd[x]=1;
			printf("-1\n");
			continue;
		}
		for(int i=x+1;i<=300000;i++){
			if(pd[i]==1) continue;
			else if(pd[i]==-1){
				printf("%d\n",i);
				break;
			}
			if(cx(i)==0){
				pd[i]=-1;
				printf("%d\n",i);
				break;
			}
			else pd[i]=1;
		}
	}
	return 0;
}
