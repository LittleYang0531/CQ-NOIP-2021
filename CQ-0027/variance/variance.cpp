//ayanami保佑，狗妈保佑，MDR保佑，M99保佑，克爹保佑
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1>=1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
#define gc getchar
long long getint(){
	long long ret=0;bool flg=0;
	char c=gc();
	while(c<'0'||c>'9'){
		if(c=='-')flg=1;
		c=gc();
	}
	while(c>='0'&&c<='9'){
		ret=(ret<<3)+(ret<<1)+(c^48);
		c=gc();
	}
	return flg?-ret:ret;
}
void pc(char c){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=c;
}
void wrt(long long x){
	if(x<0)pc('-'),x=-x;
	if(x==0)return pc('0');
	int c[48]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
const int bs=(1<<10)-1;
int n,a[10005],c[10005],p[35],num[605];
int b[10005],d[10005],C[10005];
long long ans=0x3f3f3f3f3f3f3f3fll;
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=getint();
	for(int i=1;i<=n;i++)a[i]=getint();
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	sort(c+1,c+n+1);
	if(n<=20){
		for(int i=1;i<=n;i++)c[i]=c[i+1];
		for(int S=0;S<1<<n;S++){
			b[0]=d[0]=C[0]=0;
			for(int i=1;i<n;i++){
				if(S>>(i-1)&1)b[++b[0]]=c[i];
				else d[++d[0]]=c[i];
			}
			sort(b+1,b+b[0]+1),sort(d+1,d+d[0]+1),reverse(d+1,d+d[0]+1);
			for(int i=1;i<=d[0];i++)C[++C[0]]=d[i];
			for(int i=1;i<=b[0];i++)C[++C[0]]=b[i];
			long long res=0,sum=0;
			for(int i=2;i<=n;i++)a[i]=a[i-1]+(C[i-1]&bs);
			for(int i=1;i<=n;i++)sum+=a[i],res+=1ll*n*a[i]*a[i];
			res=res-sum*sum,ans=min(ans,res);
		}
		cout<<ans<<"\n";
		exit(0);
	}
	int N=0;
	for(int i=1;i<n;i++)c[i]=c[i+1];
	for(int i=1;i<n;i++)++num[c[i]];
	for(int i=0;i<=600;i++)if(num[i]&1)p[i]=N++;
	for(int S=0;S<1<<N;S++){
		b[0]=d[0]=C[0]=0;
		for(int i=0;i<=600;i++){
			for(int j=1;j<=num[i]/2;j++)b[++b[0]]=i;
			if((num[i]&1)&&!(S>>p[i]&1))b[++b[0]]=i;
		}
		for(int i=0;i<=600;i++){
			for(int j=1;j<=num[i]/2;j++)d[++d[0]]=i;
			if((num[i]&1)&&(S>>p[i]&1))d[++d[0]]=i;
		}
		reverse(d+1,d+d[0]+1);
		for(int i=1;i<=d[0];i++)C[++C[0]]=d[i];
		for(int i=1;i<=b[0];i++)C[++C[0]]=b[i];
		long long res=0,sum=0;
		for(int i=2;i<=n;i++)a[i]=a[i-1]+(C[i-1]&bs);
		for(int i=1;i<=n;i++)sum+=a[i],res+=1ll*n*a[i]*a[i];
		res=res-sum*sum,ans=min(ans,res);
	}
	cout<<ans<<"\n";
	fwrite(wb,1,p2,stdout);
	return 0;
}
/*
4
1 2 4 6
*/
