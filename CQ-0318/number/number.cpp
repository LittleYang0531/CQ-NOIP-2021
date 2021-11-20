#include<iostream>
using namespace std;
int t,x;
int a[1005],k=0,x1,b=0,b1=0,b0=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=1000;i++){
		if(i%10==7||i/10%10==7||i/100%10==7){
			k++;
			a[k]=i;
		}
	}
	for(int m=1;m<=t;m++){
		cin>>x;
		for(int j=1;j<=k;j++){
			if(x%a[j]==0){
				cout<<-1;
				b=1;
				break;
			}
		}
		if(b==0){
			x1=x;
			while(1){
				x1++;
				for(int j=1;j<=k;j++){
					if(x1%a[j]==0){
						b1=1;
					}
				}
				if(b1==0){
					cout<<x1;
					break;
				}
				b1=0;
			}
		}
		b=0;
		b1=0;
	}
	return 0;
}
