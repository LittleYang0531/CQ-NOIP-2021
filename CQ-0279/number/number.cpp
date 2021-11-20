#include<bits/stdc++.h>
using namespace std;
const int MAX=10000500;
int next[MAX];
int N;
int read(){
	int a=getchar();
	while(!(a=='-'||a<='9'&&a>='0'))a=getchar();
	int b,c=0;
	if(a=='-'){
		b=-1;
		a=getchar();
	}else{
		b=1;
	}
	while(a<='9'&&a>='0'){
		c=c*10+a-'0';
		a=getchar();
	}
	return c*b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,x;
	t=read();
	N=t*100;
	if(t>=10000)N=MAX-1;
	int k=1;
	for(int k=1;k<=N;k*=10)
	for(int a=0;a<k;a++){
		for(int b=0;(10*b+7)*k+a<=N;b++){
			for(int d=1;((10*b+7)*k+a)*d<=N;d++){
				next[((10*b+7)*k+a)*d]=-1;
			}
		}
	}
	int last=0;
	for(int i=N;i>=0;i--){
		if(next[i]!=-1){
			next[i]=last;
			last=i;
		}
	}
	for(int i=0;i<t;i++){
		x=read();
		cout<<next[x]<<endl;
	}
	return 0;
}
