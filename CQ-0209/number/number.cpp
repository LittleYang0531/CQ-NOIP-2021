#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
#define N 10000005
using namespace std;
int vst[N+2];
int can[N+2],tot;
int n,T;
bool check(int s)
{
	while(s)
	{
		int fg=s%10;
		if(fg==7) return false;
		s/=10;
	}
	return true;
}
void get_g()
{
	for(int i=1;i<=N;i++)
	{
		if(i>=7000000 && i<=7999999) continue;//����Ҫ��������
		if(vst[i])//����Լ���������ɱ����Ƶ���������ô����������һ�δ�ɲ���
			continue;
		//����˵������δ��֮ǰ�����Ƶ�������������Ƿ��� 7�������������£���֮���� can 
		if(!check(i))//�����к��� 7
		{
			for(int j=i;j<=N;j+=i) vst[j]=true;
			continue;
		}
		else can[++tot]=i;
	}
}
int getans(int s)
{
	int l=1,r=tot,mid;
	int flag=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(can[mid]>s) r=mid-1;
		else if(can[mid]<s) l=mid+1;
		else 
		{
			flag=mid;
			break;
		}
	}
	if(flag==0) return -1;
	return can[flag+1];
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	get_g();
	scanf("%d",&T);
	while(T--)
	{
		int q;
		scanf("%d",&q);
		printf("%d\n",getans(q));
	}
	return 0;
}
