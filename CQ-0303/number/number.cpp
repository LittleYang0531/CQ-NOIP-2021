#include<bits/stdc++.h>
#define isdigit(x) ('0'<=x && x<='9')
using namespace std;
int T,x,nxt[13000005],tmp;
bitset<13000005> ok,checked;
inline bool p(int x)
{
	while(x)
	{
		if( x%10 == 7 ) return 1;
		x/=10;
	}
	return 0;
}
inline int read()
{
	int w=0;
	char ch=getchar();
	while(!isdigit(ch))
		ch=getchar();
	while isdigit(ch)
	{
		w=(w<<1)+(w<<3)+ch-'0';
		ch=getchar(); 
	}
	return w;
}
void out(int x)
{
	if(x) out(x/10),putchar(x%10 + '0');
	return ;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ok.set(),checked.reset();
	for(int i=1;i<=13000000;++i)
	{
		if(checked[i]) continue;
		checked[i]=1;
		if(p(i))
		{
			for(int j=1,tmp=i;tmp<=13000000;tmp=i*(++j))
			{
				ok[i*j]=0;
				checked[i*j]=1;
			}
		}
	}
	for(int i=13000000;i>=1;--i)
	{
		if(ok[i+1]) nxt[i]=i+1;
		else nxt[i]=nxt[i+1];
	}
	T=read(),++T;
	while(--T)
	{
		x=read();
		if(!ok[x]) putchar('-'),putchar('1');
		else out(nxt[x]);
		putchar('\n');
	}
	return 0;
}

