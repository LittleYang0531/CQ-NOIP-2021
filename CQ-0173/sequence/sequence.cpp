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
const int N=30,P=998244353;
int n,m,k;
int arr[105],bi[105],op[105],bii[105],tkz; 
void check()
{
	memcpy(bii,bi,sizeof(bii));
	for(int i=0;i<105-1;i++)
	{
		if(bii[i] > 1)
			bii[i+1] += (bii[i] >>1);
		bii[i] &= 1;
	}
	int cnt = 0;
	for(int i=0;i<105;i++)
		if(bii[i])
			cnt++;
	if(cnt > k)
		return;
		
	int ad = 1;
	for(int i=1;i<=n;i++)
		ad = (ad * arr[op[i]]) % P;
	tkz = (tkz + ad) % P;
}
void DFS(int nowx)
{
	if(nowx > n)
	{
		check();
		return;
	}
	for(int i=0;i<=m;i++)
	{
		bi[i] ++;
		op[nowx] = i;
		DFS(nowx+1);
		op[nowx] = 0;
		bi[i] --; 
	 } 
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<=m;i++)
		cin>>arr[i];
	DFS(1);
	cout<<tkz<<endl;
	return 0;
}

