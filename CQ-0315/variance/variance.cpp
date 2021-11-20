#include<bits/stdc++.h>
using namespace std;
int a[30],b[30],base=233;
int hash[1000001],mod=1000001;
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
    int n;
    scanf("%d",&n);
    long double jj=1000000000.0;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	long double sum=0;
	for(int i=1;i<=n;i++)
    sum+=double(a[i]);
	sum/=double(n);
    long double ans=0;
	for(int j=1;j<=n;j++) ans+=(double(a[j])-sum)*(double(a[j])-sum);
    ans/=double(n);
    jj=min(jj,ans);
    while(1){
    	int js=0;
		bool p=0; 
    	for(int i=2;i<=n-1;i++){
    	    if(a[i-1]+a[i+1]!=a[i]+a[i]){
    		    a[i]=a[i-1]+a[i+1]-a[i];
    		    long double sum=0;
    		    for(int j=1;j<=n;j++) sum+=double(a[j]);
    		    sum/=double(n);
    		    long double ans=0;
    		    long long aans=0;
			    for(int j=1;j<=n;j++) ans+=(double(a[j])-sum)*(double(a[j])-sum);
                for(int j=1;j<=n;j++) aans=(aans*base)%mod,	aans+=a[j];
				if(hash[aans]==1){
					p=1;
					break;
				}
				else hash[aans]=1;
				ans/=double(n);
                jj=min(jj,ans);
                
    	    }
    	    if(p==1){
    	    	break;
			}
	    }   
	    if(p==1) break;
	}
	cout<<jj*double(n*n);
}
