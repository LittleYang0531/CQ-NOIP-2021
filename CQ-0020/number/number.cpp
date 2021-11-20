/*
我们考虑先把所有带7的数搜出来，然后搞个线性筛？
直接dfs？
我们首先要知道答案上界。
先打个暴力看下上界。 
那我不是直接搜出来然后二分一下就好了吗？
哦需要搜的时候从小到大。
10000001就行了。 
10000000是-1。
所以我们只要搜到0~9999999以内的数就好了，然后再把10000001加进去。 
？
不还是线性筛来搞？
我们光搜到不含7的了，但是没有删掉它们的倍数 
“正整数x”，所以没有0. 

聪明的，你告诉我，为什么你的减号是全角的呢？ 

啊伪掉了。
不能线性筛，因为有可能最小因子需要参加进来才能组成那个7.总不能nlnn吧……
试试再说 
好像还蛮快的哦，流汗 
快个*
1.3s了。 
读入和二分耗时这么大？ 
诶优化了一下现在只要1s了。
/cy
 
*/
#include<cstdio>
bool tag[10000010];
int prime[10000010],cnt,seven[10000010],lis[10000010],tot;
void dfs(int x,int sum,bool sev)
{
	if(x==-1)	seven[sum]=sev?1:0;
	else
	{
		for(int i=0;i<10;++i)	dfs(x-1,sum*10+i,sev||i==7);
	}
}
void search(int x)
{
	for(int i=1;i<=x;++i)
	{
		if(seven[i]==1)
		{
			for(int j=i*2;j<=x;j+=i)	seven[j]=2;
		}
	} 
	for(int i=1;i<=x;++i)
	{
		if(!seven[i])	lis[++tot]=i;
	}
}
void read(int &hhh)
{
	int x=0;
	char c=getchar();
	while(c!='-'&&(c>'9'||c<'0'))	c=getchar();
	if(c!='-')	x=c^'0';
	char d=getchar();
	while(d>='0'&&d<='9')
	{
		x=(x<<1)+(x<<3)+(d^'0');
		d=getchar();
	}
	if(c!='-')	hhh=x;
	else	hhh=-x;
}
void writing(int x)
{
	if(!x)	return;
	writing(x/10);
	putchar('0'^(x%10));
}
void write(int x)
{
	if(!x)
	{
		putchar('0');
		return;
	}
	else if(x<0)
	{
		putchar('-');
		x=-x;
	}
	writing(x);
}
int q,opx;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	dfs(6,0,0);
	search(10000000);
	lis[++tot]=10000001;
	read(q);
	while(q--)
	{
		read(opx);
		int l=1,r=tot;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(lis[mid]<=opx)	l=mid;
			else	r=mid;
		}
		if(lis[l]!=opx)	puts("-1");
		else
		{
			write(lis[l+1]);
			putchar('\n');
		}
	}
	return 0;
}
