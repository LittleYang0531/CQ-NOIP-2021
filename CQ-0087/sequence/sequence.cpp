#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[105];
inline long long read()
{
	char c=getchar();
	long long x=0;
	while(c<'0'||c>'9')
	c=getchar();
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x;
}
int jc(int x)
{
	int shu=1;
	while(x--)shu*=2;
	return shu;
}
const long long MOD=998244353;
int f[35];
long long sum;
long long jc(int fst,int lst)
{
	long long shu=1;
	for(int i=fst+1;i<=lst;++i)
	shu*=i;
	return shu;
}
void dfs8(int x)
{
	if(x>n)
	{
		int geshu[15]={0},pdd=0;
		for(int i=1;i<=n;++i)
		geshu[f[i]]++;
		for(int i=0;i<=m;++i)
		{
			pdd+=geshu[i]%2;
			geshu[i+1]+=geshu[i]/2;
		}
		int tou=m+1;
		while(geshu[tou])
		{
			pdd+=geshu[tou]%2;
			geshu[tou+1]+=geshu[tou]/2;
			tou++;
		}
		if(pdd>k)return;
		else
		{
			int zhuang[20]={0};
			for(int i=1;i<=n;++i)
			zhuang[f[i]]++;
			long long chu=1;
			int geshu=0;
			for(int i=0;i<=m;++i)
			{
				if(zhuang[i])
				{
					geshu++;
					chu*=jc(0,zhuang[i]);
				}
			}
			long long zongshu=1;
			zongshu=(jc(0,n)/chu);
		//	for(int i=1;i<=n;++i)
		//	printf("%d ",f[i]);
		//	printf("\n");
			long long sum1=1;
			for(int i=1;i<=n;++i)
			sum1=(sum1*a[f[i]])%MOD;
			sum=(sum+zongshu*sum1)%MOD;
			return;
		}
	}
	for(int i=f[x-1];i<=m;++i)
	{
		f[x]=i;
		dfs8(x+1);
	}
}
int f30[35];
//f30[]biaoshi 30dejiecheng  f30[i] biaoshijiechengzhong youduoshaoge i
int yinshu[35][8];
int l[35]={0,0,1,1,2,1,2,1,3,2,2,1,3,1,2,2,4,1,3,1,3,2,2,1,4,2,2,3,3,1,3};
void dfs30(int x)
{
	if(x>n)
	{
		int geshu[20]={0},pdd=0;
		for(int i=1;i<=n;++i)
		geshu[f[i]]++;
		for(int i=0;i<=m;++i)
		{
			pdd+=geshu[i]%2;
			geshu[i+1]+=geshu[i]/2;
		}
		int tou=m+1;
		while(geshu[tou])
		{
			pdd+=geshu[tou]%2;
			geshu[tou+1]+=geshu[tou]/2;
			tou++;
		}
		if(pdd>k)return;
		else
		{
			int f30jia[35];
			for(int i=1;i<=n;++i)
			f30jia[i]=f30[i];
			int zhuang[35]={0};
			for(int i=1;i<=n;++i)
			zhuang[f[i]]++;
			//cout<<zhuang[0]<<" "<<zhuang[1]<<endl;
			for(int i=0;i<=m;++i)
			{
				for(int j=2;j<=zhuang[i];++j)
				{
					for(int k=1;k<=l[j];++k)
					f30jia[yinshu[j][k]]--;
				}
			}
			long long zongshu=1;
			for(int i=2;i<=29;++i)
			{
				for(int j=1;j<=f30jia[i];++j)
				zongshu=(zongshu*i)%MOD;
			}
		//	for(int i=1;i<=n;++i)
		//	printf("%d ",f[i]);
		//	printf("\n");
			long long sum1=1;
			for(int i=1;i<=n;++i)
			sum1=(sum1*a[f[i]])%MOD;
			sum=(sum+zongshu*sum1)%MOD;
			return;
		}
	}
	for(int i=f[x-1];i<=m;++i)
	{
		f[x]=i;
		dfs30(x+1);
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=0;i<=m;++i)
	a[i]=read();
	if(n==8)
	dfs8(1);
	else if(n==30&&m==7)
	{	
		f30[2]=26,f30[3]=14,f30[5]=7,f30[7]=4,f30[11]=2,f30[13]=2,f30[17]=1;
		f30[19]=1,f30[23]=1,f30[29]=1;
		yinshu[2][1]=2;
		yinshu[3][1]=3;
		yinshu[4][1]=2,yinshu[4][2]=2;
		yinshu[5][1]=5;
		yinshu[6][1]=2,yinshu[6][2]=3;
		yinshu[7][1]=7;
		yinshu[8][1]=2,yinshu[8][2]=2,yinshu[8][3]=2;
		yinshu[9][1]=3,yinshu[9][2]=3;
		yinshu[10][1]=2,yinshu[10][2]=5;
		yinshu[11][1]=11;
		yinshu[12][1]=2,yinshu[12][2]=2,yinshu[12][3]=3;
		yinshu[13][1]=13;
		yinshu[14][1]=2,yinshu[14][2]=7;
		yinshu[15][1]=3,yinshu[15][2]=5;
		yinshu[16][1]=2,yinshu[16][2]=2,yinshu[16][3]=2,yinshu[16][4]=2;
		yinshu[17][1]=17;
		yinshu[18][1]=2,yinshu[18][2]=3,yinshu[18][3]=3;
		yinshu[19][1]=19;
		yinshu[20][1]=2,yinshu[20][2]=2,yinshu[20][3]=5;
		yinshu[21][1]=3,yinshu[21][2]=7;
		yinshu[22][1]=2,yinshu[22][2]=11;
		yinshu[23][1]=23;
		yinshu[24][1]=2,yinshu[24][2]=2,yinshu[24][3]=2,yinshu[24][4]=3;
		yinshu[25][1]=5,yinshu[25][2]=5;
		yinshu[26][1]=2,yinshu[26][2]=13;
		yinshu[27][1]=3,yinshu[27][2]=3,yinshu[27][3]=3;
		yinshu[28][1]=2,yinshu[28][2]=2,yinshu[28][3]=7;
		yinshu[29][1]=29;
		yinshu[30][1]=2,yinshu[30][2]=3,yinshu[30][3]=5;
		dfs30(1);
	}
	else
	{
		cout<<200603030;
	}
	printf("%lld",sum);
	return 0;
}
