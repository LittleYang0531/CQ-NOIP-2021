#include<bits/stdc++.h>
using namespace std;
int t,maxx=0,quest[200005];
bool seven(int x){
	while(x!=0){
		if(x%10==7)return true;
		else x=x/10;
	}
	return false;
}
void ran20(){
	bool che[500005];
	for(int i=1;i<=maxx*2;i++){
		if(seven(i)){
			int c=1;
			while(c*i<=maxx*2){
				che[c*i]=1;
				c++;
			}
		}
	}
	for(int i=1;i<=t;i++){
		int n=quest[i];
		if(che[n]==1){
			printf("-1\n");
			continue;
		}
		n++;
		while(che[n])
			n++;
		printf("%d\n",n);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&quest[i]);
		maxx=max(maxx,quest[i]);
	}
	ran20();
	return 0;
}
