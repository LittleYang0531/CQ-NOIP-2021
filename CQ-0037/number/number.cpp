#include<bits/stdc++.h>
using namespace std;
namespace IO
{
	const int buf_size=1<<20;
	char buf[buf_size],*S,*T;
	inline char read_char()
	{
		if(S==T)
			T=(S=buf)+fread(buf,1,buf_size,stdin);
		return S!=T?*(S++):EOF;
	}
	inline int read_int()
	{
		char c=read_char();
		bool neg=false;
		while(c<'0'||c>'9')
		{
			neg=(c=='-');
			c=read_char();
		}
		int x=0;
		while(c>='0'&&c<='9')
		{
			x=x*10+(c^'0');
			c=read_char();
		}
		return neg?-x:x;
	}
	char fw[buf_size];
	int pw;
	inline void flush()
	{
		fwrite(fw,1,pw,stdout);
		pw=0;
	}
	inline void write_char(char x)
	{
		fw[pw++]=x;
		if(pw==buf_size)
			flush();
	}
	inline void write_int(int x)
	{
		if(!x)
		{
			write_char('0');
			return;
		}
		if(x<0)
		{
			write_char('-');
			x=-x;
		}
		static char st[26];
		int tp=0;
		while(x)
		{
			st[++tp]=x%10^'0';
			x/=10;
		}
		while(tp>0)
			write_char(st[tp--]);
	}
}
const int max_R=1e7+5;
bool p[max_R],ok[max_R];
int ans[max_R];
inline void init()
{
	const int R=(int)1e7+1;
	for(int i=1;i<=R;++i)
		ok[i]=true;
	for(int i=1;i<=R;++i)
	{
		if(i%10==7)
			p[i]=true;
		else
			p[i]=p[i/10];
		if(p[i])
		{
			for(int j=i;j<=R;j+=i)
				ok[j]=false;
		}
	}
	assert(ok[R]);
	int Last=R;
	for(int i=R-1;i>=1;--i)
	{
		ans[i]=ok[i]?Last:-1;
		if(ok[i])
			Last=i;
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	int T=IO::read_int();
	while(T--)
	{
		int x=IO::read_int();
		IO::write_int(ans[x]);
		IO::write_char('\n');
	}
	IO::flush();
	return 0;
}

