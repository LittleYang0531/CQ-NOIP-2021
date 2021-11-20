#include<bits/stdc++.h>
using namespace std;
const int M=1.0e7,N=1.0e7;
int t,v[M],w[M];

void ccf(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
}

void lst(){
	int cnt;
	v[0]=1;
	for(int i=1;i<=N;i++){
		if(v[i]==1)continue;//大样例1.2s过，于是加了这个优化一下，时间缩短为0.5秒
		int o=i;
		while(o){
			int u=o%10;
			if(u==7){
				for(int j=1;i*j<=N;j++)
					v[i*j]=1;
				break;
			}
			o/=10;
		}
	}
}

int main(){
	ccf();
	lst();
	cin>>t;
	for(int i=1;i<=t;i++){
		int x,o=0;
		cin>>x;
		if(v[x]==1){
			cout<<-1<<endl;
			continue;
		}
		for(int j=x+1;j<=x+500000;j++){
			if(v[j]==0){
				cout<<j<<endl;
				break;
			}
		}
	}
	return 0;
}
/*
4
6
33
69
300

5
90
99
106
114
169
*/
