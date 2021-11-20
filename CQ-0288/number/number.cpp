#include<bits/stdc++.h>
using namespace std;
int n,t,jc[10000010],ans[10000001],a,b,c,d,e,f;
inline void find(int i){
	for(int j=1;j<=1428580;j++){
		if(i*j>1e7)return ;
		if(jc[i*j]==1)continue;
		else jc[i*j]=1;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	for(int i=7;i<=1e7;i++){
		a=i%10;if(a==7){find(i);continue;}
		b=i%100;if(b>70&&b<80){find(i);continue;}
		c=i%1000;if(c>700&&c<800){find(i);continue;}
		d=i%10000;if(d>7000&&d<8000){find(i);continue;}
		e=i%100000;if(e>70000&&e<80000){find(i);continue;}
		f=i%1000000;if(f>700000&&f<800000){find(i);continue;}
		if(i>7000000&&i<8000000){find(i);continue;}
	}
	for(int i=1;i<=1e7+10;i++) if(jc[i]==0)
		for(int j=i+1;j<=1e7+10;j++) if(jc[j]==0){ans[i]=j;break;}
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		if(jc[n]==1)printf("-1\n");
		else printf("%d\n",ans[n]);
	}
	return 0;
}
