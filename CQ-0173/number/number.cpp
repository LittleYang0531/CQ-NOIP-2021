/*
	AKIOI�ģ����С��
	I Ak O.W.Ls
	I Ak N.E.W.Ts
	No matter where,no matter how,Hogwarts is always there for you in your heart.
*/
/*
	CQ-00240������Ĥ�����ҷ�ҪĤ��
	orz tanyulin sto(???)
	sto tanyulin orz 
	sto tanyulin orz
*/
/*
	��ͬУ��oiers
	tkz������ĬĬ��ף��ɹ���Ը���OI֮·��������
	Lh,CYYH,DKD,LRC,YZY,NYH,���ǵ�·������Ը���ǵ�OI֮·�����Ļ�
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+30;
int arr[N];
bool p[N];
//����ج�� 
long long n,T; 
vector<long long> prms;
bool check(long long i)
{
	long long y = i;
	int a = 1;
	while(y/a)
	{
		if((y / a) % 10 == 7)
		{
			a *= 10;
			while(y + a < N && !p[y+a])
			{
				y += a;
				p[y] = true;
			}
			return true;
		}
		a *= 10;
	}
	return false;
}
void getn()
{
	n = 0;
	char c = '0';
	while(1)
	{
		c = getchar();
		if(c == '\n')
			return;
		n = n * 10 + (c - '0'); 
	}
}
void putn(int x)
{
	char c[10];
	int cnt = 0;
	while(x)
	{
		c[++cnt] = '0' + (x % 10);
		x /= 10;
	}
	while(cnt--)
		putchar(c[cnt+1]);
	puts("");
}
void prwork()
{
	for(long long i=1;i<N;i++)
	{
		if(p[i] >= 7000000 && p[i] <= 7999999)
			p[i] = true;
		if((!p[i]) && check(i))
			p[i] = true;
		if(p[i] && i <= N / 2)
		{
			for(long long j=0;j<prms.size();j++)//����С��ɸ 
			{
				if(i * prms[j] >= N)
					break;
				p[i * prms[j]] = true; 
			 } 
			for(long long j=i;j*i<N;j++)
				p[i * j] = true;
		}
		else
			prms.push_back(i);
	}
	arr[N-1] = N-1;
	for(long long i=N-1;i>=1;i--)
		arr[i] = p[i]? arr[i+1]:i;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	prwork();
	//��ʼ���� 
	for(int i=0;i<N/10;i++)
		p[i*10+7] = true; 
	getn();
	while(T--)
	{
		getn();
		if(p[n])//���Ϸ�
			puts("-1");
		else 
			putn(arr[n+1]);
	}
	return 0;
}
