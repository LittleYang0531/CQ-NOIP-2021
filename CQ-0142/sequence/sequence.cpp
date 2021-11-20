//Nerver gOnna gIve you uP
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=,mod=998244353;
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
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	
	return 0;
}
