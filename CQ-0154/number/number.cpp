#include<bits/stdc++.h>
#define inl inline
using namespace std;
const int maxx=1e7+5;
int n,cnt,ne[maxx];
bool vst[maxx];
inl int Read()
{
	int s=0,f=1; char c;
	while(!isdigit(c=getchar()))
		if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) s=s*10+c-'0';
	return s*f;
}
inl void Write(int x)
{
	short cnt=0,s[40];
	if(x<0) putchar('-'), x=-x;
	do s[++cnt]=x%10; while((x/=10));
	while(cnt--) putchar(s[cnt+1]+'0');
}
inl void Add(int x)
{
	if(!vst[x])
		for(int i=x;i<maxx;i+=x) vst[i]=true;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	for(int i1=0;i1<=9;++i1)
		for(int i2=0;i2<=9;++i2)
			for(int i3=0;i3<=9;++i3)
				for(int i4=0;i4<=9;++i4)
					for(int i5=0;i5<=9;++i5)
						for(int i6=0;i6<=9;++i6)
						{
							Add(7*1000000+i1*100000+i2*10000+i3*1000+i4*100+i5*10+i6);
							Add(i1*1000000+7*100000+i2*10000+i3*1000+i4*100+i5*10+i6);
							Add(i1*1000000+i2*100000+7*10000+i3*1000+i4*100+i5*10+i6);
							Add(i1*1000000+i2*100000+i3*10000+7*1000+i4*100+i5*10+i6);
							Add(i1*1000000+i2*100000+i3*10000+i4*1000+7*100+i5*10+i6);
							Add(i1*1000000+i2*100000+i3*10000+i4*1000+i5*100+7*10+i6);
							Add(i1*1000000+i2*100000+i3*10000+i4*1000+i5*100+i6*10+7);
						}
	for(int i=maxx-1,la=maxx;i>=1;--i)
		if(vst[i]) ne[i]=-1;
		else ne[i]=la, la=i;
	for(n=Read();n;--n) Write(ne[Read()]), putchar('\n');
	return 0;
}
