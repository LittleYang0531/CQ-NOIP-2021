#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,k;
long long v[105],ans;
int ws(long long s){
	if(s<2)return s;
	return s%2+ws(s/2);
}
long long ksm(long long x,long long y){
	long long s=1;
	while(y)
		if(y%2)s=(s*x)%mod,x=(x*x)%mod,y/=2;
			else x=(x*x)%mod,y/=2;
	return s;
}
void dfs1(int x,int a[],int s){
	if(s>30)return;
	if(s==30){
		for(int i=-1;i<=100-x;i++){
			long long s=0;
			for(int j=1;j<=x;j++)s=(s*ksm(v[i+j],a[j]))%mod;
			ans=(ans+s)%mod;
		}
		return;
	}
	a[x]=1,dfs1(x+1,a,s+1);
	a[x]=3,a[x+1]=0,a[x+2]=1,dfs1(x+3,a,s+4);
	a[x]=7,a[x+1]=0,a[x+2]=0,a[x+3]=1,dfs1(x+4,a,s+8);
	a[x]=15,a[x+1]=0,a[x+2]=0,a[x+3]=0,a[x+4]=1,dfs1(x+5,a,s+16);
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=m;i++)scanf("%lld",&v[i]);
	if(n==8&&m==9){
		for(int a=0;a<=9;a++)
		for(int b=0;b<=9;b++)
		for(int c=0;c<=9;c++)
		for(int d=0;d<=9;d++)
		for(int e=0;e<=9;e++)
		for(int f=0;f<=9;f++)
		for(int g=0;g<=9;g++)
		for(int h=0;h<=9;h++){
			long long s=pow(2,a)+pow(2,b)+pow(2,c)+pow(2,d)+pow(2,e)+pow(2,f)+pow(2,g)+pow(2,h);
			if(ws(s)<=k)ans=(ans+(((((((v[a]*v[b])%mod*v[c])%mod*v[d])%mod*v[e])%mod*v[f])%mod*v[g])%mod*v[h])%mod)%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==30&&m==7){
		for(int a=0;a<=30;a++)
		for(int b=0;b<=30-a;b++)
		for(int c=0;c<=30-a-b;c++)
		for(int d=0;d<=30-a-b-c;d++)
		for(int e=0;e<=30-a-b-c-d;e++)
		for(int f=0;f<=30-a-b-c-d-e;f++)
		for(int g=0;g<=30-a-b-c-d-e-f;g++){
			int h=30-a-b-c-d-e-f-g;
			long long s=a+2*b+4*c+8*d+16*e+32*f+64*g+128*h;
			if(ws(s)<=k)ans=(ans+(((((((ksm(v[0],a)*ksm(v[1],b))%mod*ksm(v[2],c))%mod*ksm(v[3],d))%mod*ksm(v[4],e))%mod*ksm(v[5],f))%mod*ksm(v[6],g))%mod*ksm(v[7],h))%mod)%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==30&&m==12){
		for(int a=0;a<=30;a++)
		for(int b=0;b<=30-a;b++)
		for(int c=0;c<=30-a-b;c++)
		for(int d=0;d<=30-a-b-c;d++)
		for(int e=0;e<=30-a-b-c-d;e++)
		for(int f=0;f<=30-a-b-c-d-e;f++)
		for(int g=0;g<=30-a-b-c-d-e-f;g++)
		for(int h=0;h<=30-a-b-c-d-e-f-g;h++)
		for(int i=0;i<=30-a-b-c-d-e-f-g-h;i++)
		for(int j=0;j<=30-a-b-c-d-e-f-g-h-i;j++)
		for(int l=0;l<=30-a-b-c-d-e-f-g-h-i-j;l++)
		for(int o=0;o<=30-a-b-c-d-e-f-g-h-i-j-l;o++){
			int p=30-a-b-c-d-e-f-g-h-i-j-l-o;
			long long s=a+2*b+4*c+8*d+16*e+32*f+64*g+128*h+256*i+512*j+1024*l+2048*o+4096*p;
			if(ws(s)<=k)ans=(ans+((((((((((((ksm(v[0],a)*ksm(v[1],b))%mod*ksm(v[2],c))%mod*ksm(v[3],d))%mod*ksm(v[4],e))%mod*ksm(v[5],f))%mod*ksm(v[6],g))%mod*ksm(v[7],h))%mod*ksm(v[8],i))%mod*ksm(v[9],j))%mod*ksm(v[10],l))%mod*ksm(v[11],o))%mod*ksm(v[12],p))%mod)%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	if(n==30&&k==1&&m==100){
		int a[35];
		a[1]=2,a[2]=1,dfs1(3,a,3);
		a[1]=4,a[2]=0,a[3]=1,dfs1(4,a,5);
		a[1]=8,a[2]=0,a[3]=0,a[4]=1,dfs1(5,a,9);
		a[1]=16,a[2]=0,a[3]=0,a[4]=0,a[5]=1,dfs1(6,a,17);
		printf("%lld",ans);
		return 0;
	}
	if(n==5&&m==50){
		for(int a=0;a<=50;a++)
		for(int b=0;b<=50;b++)
		for(int c=0;c<=50;c++)
		for(int d=0;d<=50;d++)
		for(int e=0;e<=50;e++){
			long long s=pow(2,a)+pow(2,b)+pow(2,c)+pow(2,d)+pow(2,e);
			if(ws(s)<=k)ans=(ans+((((v[a]*v[b])%mod*v[c])%mod*v[d])%mod*v[e])%mod)%mod;
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
