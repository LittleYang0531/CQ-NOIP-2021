//Nerver gOnna gIve you uP
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=3e5;
int t,x,pre,to[N+10];
bool p[N+10];
inline bool checker(int x){
	while(x){
		if(x%10==7)return true;
		x/=10;
	}
	return false;
}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(t);
//	if(t<=N){
		for(int i=1;i<=N;++i){
			if(checker(i)){
				p[i]=true;
				for(int k=2;i*k<=N;++k)
				p[i*k]=true;
			}
		}
		for(int i=N-1;i>=1;--i){
			if(!p[i+1]){
				if(p[i])pre=i+1;
				else to[i]=i+1;
			}
			else to[i]=pre;
		}
		while(t--){
			read(x);
			if(p[x])printf("-1\n");
			else printf("%d\n",to[x]);
		}		
//	}
	return 0;
}
