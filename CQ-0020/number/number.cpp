/*
���ǿ����Ȱ����д�7�����ѳ�����Ȼ��������ɸ��
ֱ��dfs��
��������Ҫ֪�����Ͻ硣
�ȴ�����������Ͻ硣 
���Ҳ���ֱ���ѳ���Ȼ�����һ�¾ͺ�����
Ŷ��Ҫ�ѵ�ʱ���С����
10000001�����ˡ� 
10000000��-1��
��������ֻҪ�ѵ�0~9999999���ڵ����ͺ��ˣ�Ȼ���ٰ�10000001�ӽ�ȥ�� 
��
����������ɸ���㣿
���ǹ��ѵ�����7���ˣ�����û��ɾ�����ǵı��� 
��������x��������û��0. 

�����ģ�������ң�Ϊʲô��ļ�����ȫ�ǵ��أ� 

��α���ˡ�
��������ɸ����Ϊ�п�����С������Ҫ�μӽ�����������Ǹ�7.�ܲ���nlnn�ɡ���
������˵ 
���������Ŷ������ 
���*
1.3s�ˡ� 
����Ͷ��ֺ�ʱ��ô�� 
���Ż���һ������ֻҪ1s�ˡ�
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
