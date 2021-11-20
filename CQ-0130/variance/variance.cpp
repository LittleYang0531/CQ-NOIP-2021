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
	//如果在考场上脱出来的话，中学生活就结束了吧···
	//对了!用敲键盘的声音掩盖过去就好了nari
	cout<<ans<<endl;
	return 0;
}
/*二分有缺陷，考虑下暴搜？ 
谢谢数学，我人傻了··· */
