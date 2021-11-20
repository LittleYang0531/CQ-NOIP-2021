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
bool bs[10000005],gs[10000005];
int prim[10000005],fa[10000005];
int get_fa(int x){return x==fa[x]?x:fa[x]=get_fa(fa[x]);}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	bs[7]=1;
	for(int i=10;i<=10000003;i++)bs[i]=bs[i/10]|bs[i%10];
	for(int i=1;i<=10000003;i++){
		if(bs[i]&&!gs[i])
			for(int j=i*2;j<=10000003;j+=i)
				gs[j]=1;
		fa[i]=bs[i]||gs[i]?i+1:i;
	}
	int Ti=getint();
	while(Ti--){
		int x=getint();
		if(bs[x]||gs[x])wrt(-1),pc('\n');
		else wrt(get_fa(x+1)),pc('\n');
	}
	fwrite(wb,1,p2,stdout);
	return 0;
}
