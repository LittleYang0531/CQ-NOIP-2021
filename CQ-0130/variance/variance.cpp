#include<bits/stdc++.h>
using namespace std;
int n,a[10000],sum,ans;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		ans+=pow(n*a[i]*n-sum*n,2);
	}
	//����ڿ������ѳ����Ļ�����ѧ����ͽ����˰ɡ�����
	//����!���ü��̵������ڸǹ�ȥ�ͺ���nari
	cout<<ans<<endl;
	return 0;
}
/*������ȱ�ݣ������±��ѣ� 
лл��ѧ������ɵ�ˡ����� */
