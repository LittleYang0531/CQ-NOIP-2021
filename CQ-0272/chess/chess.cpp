#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pc putchar 
const int N=1e5+5,INF=0x3f3f3f3f,mod=1e9+7;
int read()
{
	int r=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){r=r*10+(ch^48);ch=getchar();}
	return r*f;
}
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	return 0;
}
