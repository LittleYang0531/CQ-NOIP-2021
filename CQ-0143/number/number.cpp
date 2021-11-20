#include<bits/stdc++.h>
using namespace std;
bool flag[10000001];
int nex[10000001];
bool check(int k){
	while(k>0){
		int x=k%10;
		if(x==7)return true;
		k/=10;
	}
	return false;
}
int read(){
	int k=0;
	char x=getchar();
	while(x!='\n'){
		k=k*10+x-'0';
		x=getchar();
	}
	return k;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int pre=0;
	for(int i=1;i<=10000000;i++){
		if(flag[i])continue;
		if(!check(i)){
			nex[pre]=i;
			pre=i;
			continue;
		}
		flag[i]=1;
		for(int j=1;j<=10000000/i;j++){
			flag[i*j]=1;
		}
	}
	int T=read();
	while(T--){
		int n=read();
		if(flag[n])printf("-1\n");
		else printf("%d\n",nex[n]);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
