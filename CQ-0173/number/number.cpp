/*
	AKIOI的，格局小了
	I Ak O.W.Ls
	I Ak N.E.W.Ts
	No matter where,no matter how,Hogwarts is always there for you in your heart.
*/
/*
	CQ-00240不让我膜他，我非要膜他
	orz tanyulin sto(???)
	sto tanyulin orz 
	sto tanyulin orz
*/
/*
	致同校的oiers
	tkz大神，我默默地祝你成功，愿你的OI之路灿若繁星
	Lh,CYYH,DKD,LRC,YZY,NYH,你们的路还长，愿你们的OI之路生如夏花
*/ 
#include<bits/stdc++.h>
using namespace std;
const int N=1e7+30;
int arr[N];
bool p[N];
//数论噩梦 
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
			for(long long j=0;j<prms.size();j++)//用最小的筛 
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
	//开始卡常 
	for(int i=0;i<N/10;i++)
		p[i*10+7] = true; 
	getn();
	while(T--)
	{
		getn();
		if(p[n])//不合法
			puts("-1");
		else 
			putn(arr[n+1]);
	}
	return 0;
}
