#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int T,n;
int a[N],b[N],tot;
bool check(int x)//�ж�x�Ƿ���7 
{
	while(x)
	{
		if(x%10==7)
			return true;
		x/=10;
	}
	return false;
}
bool vis[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	tot=0;
	for(int i=1;i<N;i++)
	{
		if(!vis[i])
		{
			if(check(i))
			{
				for(int j=1;j*i<N;j++)
					vis[i*j]=1;
			}
		}
	}
	for(int i=1;i<N;i++)
		if(vis[i]==0)
		{
			tot++;
			a[tot]=i;
			b[i]=tot;
		}
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(vis[n])
			puts("-1");
		else
		{
			int x=b[n];
			printf("%d\n",a[x+1]);
		}
	}
	return 0;
}
//#include<bits/stdc++.h>
//using namespace std;
//const int N=1e7+5;
//int T,n;
//int a[N],b[N],tot;
//bool check(int x)//�ж�x�Ƿ���7 
//{
//	while(x)
//	{
//		if(x%10==7)
//			return true;
//		x/=10;
//	}
//	return false;
//}
//int v[N];//ÿ��������С���� 
//int seven[N],cnt;//���� 
//int main()
//{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
//	tot=cnt=0;
//	for(int i=1;i<N;i++)//������ŷ��ɸ 
//	{
//		if(!v[i])
//		{
//			if(check(i))
//			{
//				v[i]=i;
//				seven[++cnt]=i;
//			}
//		}
//		if(!v[i])
//			continue;
//		for(int j=1;j<=cnt;j++)
//		{
//			if(seven[j]*i>=N)
//				break;
//			if(v[i]<seven[j])
//				break;
//			v[i*seven[j]]=seven[j];
//		}
//	}
//	for(int i=1;i<N;i++)
//		if(v[i]==0)
//		{
//			tot++;
//			a[tot]=i;
//			b[i]=tot;
//		}
//	scanf("%d",&T);
//	while(T--)
//	{
//		scanf("%d",&n);
//		if(v[n])
//			puts("-1");
//		else
//		{
//			int x=b[n];
//			printf("%d\n",a[x+1]);
//		}
//	}
//	return 0;
//}
