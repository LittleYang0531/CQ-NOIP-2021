/*
CCF-NOIp 2021 
Pass: IronHeart@413A
Éê¡°Êö¡± ¡¢·ÉÐÐ¡°Æ÷¡± 
Worship BinDir0 to get higher grade!
stO BinDir0 AK IOI Orz!!!
*/
#include<bits/stdc++.h>
namespace MY_STD{
	#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
	#ifdef GTRAKIOI
	#define defrog(...) fprintf(stderr,__VA_ARGS__)
	#else
	#define defrog(...) 1
	#endif
	
	typedef long long ll;
	typedef std::vector<int>vi;
	typedef std::pair<int,int>pii;
	
	inline int getchar(){static char ibuf[1<<15],*p1,*p2;return p1==p2&&(p2=(p1=ibuf)+fread(ibuf,1,1<<15,stdin),p1==p2)?EOF:*p1++;}
	struct IOer{
		inline int rint(){char c,f=0;while((c=getchar())<48||c>57)if(c=='-')f=1;unsigned int a=c&15;while((c=getchar())>=48&&c<=57)a=a*10+(c&15);return f?~a+1:a;}
		inline operator int(){return rint();}
	}g90;
	
	const int N=10001000;
	
	signed main(){
		File("number");
		int T=g90;
		int mx=0;
		vi qry(T);
		for(int&x:qry){
			x=g90;
			mx=std::max(mx,x);
		}
		
		int lim=std::min(std::max(mx*2,100),10000010);
		static char p[N];
		static char has7[N];
		for(int i=7;i<=lim;i+=10){
			has7[i]=1;
		}
		for(int i=10,k=1;i<=lim;i+=10,++k)if(has7[k]){
			for(int j=0;j<10;++j)has7[i+j]=1;
		}
		for(int i=1;i<=lim;++i){
			/*auto check=[&](int x){
				int y=1;
				while(y<=x/10)y*=10;
//				defrog("\n%d %d\n",x,y);
				do{
					int cur=x/y;
//					defrog("%d ",cur);
					if(cur==7)return true;
					x%=y;
					y/=10;
				}while(y);
				return false;
			};
			assert(check(i)==has7[i]);*/
			if(p[i])continue;
			if(has7[i]){
				p[i]=1;
				for(int j=i;j<=lim;j+=i){
					p[j]=1;
				}
			}
		}
		
		static int nxt[N];
		int next_num=lim+1;
		for(int i=lim;i;--i){
			if(p[i])nxt[i]=-1;
			else nxt[i]=next_num,next_num=i;
//			defrog("%d %d\n",i,next_num);
		}
		for(int x:qry)printf("%d\n",nxt[x]);
		return 0;
	}
}
signed main(){
	return MY_STD::main();
}
