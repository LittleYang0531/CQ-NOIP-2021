#include <cstdio>
#include <algorithm>
using namespace std;
void read(int &x)
{
	x=0;int f=1;char c=getchar();
	while(!('0'<=c&&c<='9')){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
void print(int x)
{
	if(x<0) {putchar('-'),print(-x);return;}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
bool check(int x)
{
	while(x)
	{
		if(x%10==7) return true;
		x/=10;
	}
	return false;
}
bool P[11000005];
void MakeNum(int N)
{
	for(int i=1;i<=N;i++)
	{
		if(P[i]) continue;
		if(check(i))
		{
			P[i]=true;
			for(int j=1;j*i<=N;j++) P[j*i]=true;
		}
	}
}
int nxt[10000005];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	MakeNum(1e7+1000);
	int lst=0;
	for(int i=1e7+1000;i>=1;i--)
	{
		if(!P[i]) nxt[i]=lst,lst=i;
	}
	int T,x;read(T);
	while(T--)
	{
		read(x);
		if(P[x]) print(-1); 
		else print(nxt[x]);
		puts("");
	}
	return 0;
}
/*
猜一手大样例不给 10^7
失败了…… 

4
6
33
69
300

5
90
99
106
114
169
*/
