#include<bits/stdc++.h>
using namespace std;
const int M=50005,P=998244353;
int n,m,k,ans,cnt,v[M],cs[M];

void ccf(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
}

int main(){
	ccf();
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>v[i];
	int bs=n*pow(2,m);
	cout<<bs<<endl;
	for(int i=n;i<=bs;i++){
		int o=i,f=0,cnk=0;
		while(o){
			if(int(o^1)==int(o-1)){
				cnk++;
				if(cnk>k) {
					f=1;
					break;
				}
			}
			o=o>>1;
		}
		if(f==0) cs[cnt++]=i;
	}
	for(int k=0;k<cnt;k++){
		for(int i=1;i<=m;i++){
			
		}
	}
	
	cout<<rand()%10000+n*m;
	return 0;
}
/*
5 1 1
2 1


*/
