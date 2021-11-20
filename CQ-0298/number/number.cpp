#include <bits/stdc++.h>
using namespace std;
int a[10010];
bool ok(int x){
	string s="";
	while(x!=0){
		s+=x%10+'0';
		x/=10;
	}
	for(int i=0;i<(int)s.length();i++){
		if(s[i]=='7'){
			return false;
		}
	}
	return true;
}
bool check7n(int x){
	int n=sqrt(x);
	for(int i=2;i<=n;i++){
		if(x%i==0){
			if(!ok(i)||!ok(x/i)){
				return false;
			}
		}
	}
	return true;
}
int ok2(int x){
	for(int i=x+1;i<=20000000;i++){
		if(ok(i)&&check7n(i)){
			return i;
		}
	}
	return -1;
}
int T;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	if(T<=1000){
		for(int i=1;i<=10000;i++){
			if(ok(i)&&check7n(i)){
				a[i]=ok2(i);
			}
			else{
				a[i]=-1;
			}
		}
		while(T--){
			int x;
			cin>>x;
			printf("%d\n",a[x]);
		}	
	}
	else{
		while(T--){
			int x;
			cin>>x;
			if(ok(x)&&check7n(x)){
				printf("%d\n",ok2(x));
			}
			else{
				puts("-1");
			}
		}
	}
	return 0;
}//50pts
//这应该是这个人得分最高的题目了。
//尽管他还是没能AC。 
