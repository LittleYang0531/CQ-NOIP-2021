#include<bits/stdc++.h>
using namespace std;
const int NN=10005;

long long a[NN],n,cnt,aa;
long long ans[NN*1000],num=1e9+7;
long long tot1,tot2,tot;
bool vis[NN][605],h[NN*1000];

bool check()
{
	tot=0;
	bool flag=0;
	for(int i=1;i<=n;i++)
		tot=tot+a[i];
	for(int i=1;i<=n;i++)
		if(vis[i][a[i]]==1&&h[tot]==1)
			continue;
		else{
			flag=1;//���һ�£���ʾ��һ������û����
			break; 
		} 
	if(flag==0)//ȫ���ҵ���  ���������Ѿ������� 
		return true;
	h[tot]=1;
	for(int i=1;i<=n;i++)//��Ǹ������� 
		vis[i][a[i]]=1;
	return false;
}

void sove()
{
	cnt++;
	tot1=tot2=0;
	for(int i=1;i<=n;i++)
	{
		tot1=tot1+a[i];
		tot2=tot2+a[i]*a[i];
	}
	ans[cnt]=n*tot2-tot1*tot1;
	
}

void find(int x)
{
	for(int i=2;i<n;i++)
	{
		if(i==x) continue;
		aa=a[i];
		a[i]=a[i-1]+a[i+1]-a[i];
		if(check()==1)//����һ�¸��������Ƿ��Ѿ����� 
		{
			a[i]=aa;
			continue;
		} 
		sove();//��������� ����*n^2 
		find(i);//���������� 
	}
	return ;
}

int main()
{
//	freopen("variance.in","r",stdin);
//	freopen("variance.out","w",stdout);
//	ios::sync_with_stdio(false);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	check();
	sove();//û�в�����ʱ�� 
	
	find(1);
	for(int i=1;i<=cnt;i++)
		num=min(num,ans[i]);
	cout<<num<<'\n';
	return 0;
}
