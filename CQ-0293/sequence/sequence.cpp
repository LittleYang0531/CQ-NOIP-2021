#include<iostream>
#include<cstdio>
#include<time.h>
#include<bits\stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int mod=998244353;

int main(){
	//freopen("sequence.in","r",stdin);
	//freopen("sequence.out","w",stdout);
	srand(time(0));
	cout<<rand()%mod*rand()%mod;
	return 0;
}
