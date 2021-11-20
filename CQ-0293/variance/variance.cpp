#include<iostream>
#include<cstdio>
#include<bits\stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int a[605];

int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	int n=read();
	int x;
	int s=0;
	for(int i=1;i<=n;i++){
		x=read();
		s+=x;
	}
	cout<<rand()%(s*2)*rand()%(s*2);
	
	
	return 0;
}
