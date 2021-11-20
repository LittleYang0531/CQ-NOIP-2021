#include <cstdio>
inline char gc(){
	static char buf[1<<16],*S,*T;
	if(S == T){
		T = (S=buf)+fread(buf,1,1<<16,stdin);
		if(S == T)return EOF;
	}return *S++;
}
#define getchar gc
inline int re(){
	char c;
	while((c=getchar())<'0'||c>'9');
	int res = c-'0';
	while((c=getchar())>='0'&&c<='9')res = res*10+c-'0';
	return res;
}
const int maxn = 1e7+5;
int T,n;
bool an7[maxn],flg[maxn];int nxt[maxn];
void Sieve(int N){
	for(int i=7;i<=N;i+=10)an7[i] = 1;
	for(int i=70;i<=N;i+=100)
		for(int j=0;j<10;++j)an7[i+j] = 1; 
	for(int i=700;i<=N;i+=1000)
		for(int j=0;j<100;++j)an7[i+j] = 1; 
	for(int i=7000;i<=N;i+=10000)
		for(int j=0;j<1000;++j)an7[i+j] = 1; 
	for(int i=70000;i<=N;i+=100000)
		for(int j=0;j<10000;++j)an7[i+j] = 1; 
	for(int i=700000;i<=N;i+=1000000)
		for(int j=0;j<100000;++j)an7[i+j] = 1; 
	for(int i=7000000;i<=N;i+=10000000)
		for(int j=0;j<1000000;++j)an7[i+j] = 1;
	for(int i=1;i<=N;++i)
		if(an7[i])for(int j=i;j<=N;j+=i)flg[j] = 1;
	for(int i=N;i>=1;--i)
		if(!flg[i+1])nxt[i] = i+1;
		else nxt[i] = nxt[i+1];
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	Sieve(1e7+1),T = re();
	while(T--){int x = re();printf("%d\n",flg[x]?-1:nxt[x]);}
	return 0;
}
