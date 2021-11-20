/*
	AKIOI的，格局小了
	I Ak O.W.Ls
	I Ak N.E.W.Ts
	No matter where,no matter how,Hogwarts is always there for you in your heart.
*/
/*
	CQ-00240不让我膜他，我非要膜他
	sto tanyulin orz
	sto tanyulin orz
*/
/*
	致同校的oiers
	tkz大神，我默默地祝你成功，愿你的OI之路灿若繁星
	L_h_,C_Y_Y_H,D_K_D,LRC,YZY,NYH,你们的路还长，愿你们的OI之路生如夏花
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n;
long long arr[N],ans,sum,tmp[N],tkz;
int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	tkz = 0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=arr[n];i++)
	{
		ans = sum = 0ll;
		int t = 1;
		while(arr[t] < i)	t++;
		for(int j=1;j<t-1;j++)
			tmp[j] = arr[j+1] - arr[j];
		tmp[t-1] = i - arr[t-1];
		tmp[t] = arr[t] - i;
		for(int j=t+1;j<=n;j++)
			tmp[j] = arr[j] - arr[j-1];
		if(t > 1)	sort(tmp+1,tmp+t,greater<int>());
		if(t < n)	sort(tmp+t+1,tmp+n+1);
		tmp[t-1] = i-tmp[t-1];
		tmp[t] = i+tmp[t];
		for(int j=t-2;j>=1;j--)
			tmp[j] = tmp[j+1] - tmp[j];
		for(int j=t+1;j<=n;j++)
			tmp[j] = tmp[j-1] + tmp[j];
		for(int j=1;j<=n;j++)
		{
			ans += tmp[j] * tmp[j];
			sum += tmp[j];
		 }  
		tkz = min(tkz,ans * n - sum * sum);
	}
	cout<<tkz;
	return 0;
}
