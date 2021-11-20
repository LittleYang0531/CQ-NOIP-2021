#include<bits/stdc++.h>
using namespace std;
double average,toave,p;
long long n,ns[10005],total,toto;
bool f = 1;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 0;i < n;i++){
		scanf("%lld",&ns[i]);
		total += ns[i];
	}
	average = total*1.0/n;
	while(f){
		f = 0;
		for(int i = 1;i < n-1;i++){
			toto = total-ns[i]+ns[i-1]+ns[i+1]-ns[i];
			toave = toto*1.0/n;
			if(fabs(toave-(ns[i-1]+ns[i+1]-ns[i])) < fabs(average-ns[i])){
				total = toto;
				average = toave;
				ns[i] = ns[i-1]+ns[i+1]-ns[i];
				f = 1;
			}
		}
	}
	for(int i = 0;i < n;i++)
		p += (average-ns[i])*(average-ns[i]);
	cout << int(p*n);
	return 0;
}
