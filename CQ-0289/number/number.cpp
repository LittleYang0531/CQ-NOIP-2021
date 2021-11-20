#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
int T;
long long x;
bool sum[N];
void f(){
	for(int i=7;i<=N;i+=10){
		int t=1;
		while(i*t<=N){
			sum[i*t]=true;
			t++;
		}
	}
	for(int i=70;i<=N;i+=100){
		for(int j=1;j<=9;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	for(int i=700;i<=N;i+=1000){
		for(int j=1;j<=99;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	for(int i=7000;i<=N;i+=10000){
		for(int j=1;j<=999;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	for(int i=70000;i<=N;i+=100000){
		for(int j=1;j<=9999;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	/*
	for(int i=700000;i<=N;i+=1000000){
		for(int j=1;j<=99999;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	*/
	/*
	for(int i=7000000;i<=N;i+=10000000){
		for(int j=1;j<=999999;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	*/
	/*
	for(int i=70000000;i<=N;i+=100000000){
		for(int j=1;j<=9999999;j++){
			int t=1;
			while((i+j)*t<=N){
				sum[(i+j)*t]=true;
				t++;
			}
		}
	}
	*/
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	f();
	while(T--){
		scanf("%lld",&x);
		if(sum[x]){
			cout<<"-1"<<endl;
			continue;
		}
		else{
			for(long long i=x+1;i<=N;i++){
				if(!sum[i]){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	/*
	for(int i=1;i<=210;i++){
		if(sum[i]){
			cout<<i<<" ";
		}
	}
	*/
	return 0;
}
