#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
//#include<ctime>
using namespace std;
const unsigned int N=1e8;
int T,x,f[N],ans[N],rev[N]/*,bz[N]*/,tot,cnt;
inline void read(int &x){
	x=0;
	int y=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')
		y=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=y;
}
inline void write(int x,bool wrap){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)
	write(x/10,false);
	putchar('0'+x%10);
	if(wrap)
	puts("");
}
bool check(int x){
	if(x%10==7)
	return false;
	if(x>9)
	return check(x/10);
	return true;
}
bool check2(int x){
	//int tmp=x;
	for(register int i=1;i<=cnt;i++){
		/*tmp=x;
		for(register int j=20;j>=0;j--){
			if(tmp>=(bz[j]*rev[i]))
			tmp-=bz[j]*rev[i];
			if(tmp==0)
			return false;
		}*/
		if(x%rev[i]==0)
		return false;
	}
	return true;
}
/*void init(){
	bz[0]=1;
	for(register int i=1;i<=20;i++){
		bz[i]=bz[i-1]*2;
		//printf("bz[%d]=%d\n",i,bz[i]);
	}	
}*/
void work(){
	for(register int i=1;i<=70000;i++){
		f[i]=-1;
		if(!check2(i))
		continue;
		if(!check(i)){
			rev[++cnt]=i;
			continue;
		}
		f[ans[tot]]=i;
		ans[++tot]=i;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//double start=clock();
	//init();
	work();
	//double end=clock();
	read(T);
	while(T--){
		read(x);
		write(f[x],true);
	}
	//double end2=clock();
	//printf("work time: %.2lf ms\n",end-start);
	//printf("all time: %.2lf ms\n",end2-start);
	return 0;
}
//%ly %yjt %zp %twk
//%%%%%%%%%%%%%%%%%%%%%%%%%
//ly orz
//yjt orz
//zp orz
//twk orz
//原本打表过了2e5 70pts，但是不敢交那份，还是保险拿50分算了 
//AFOed
