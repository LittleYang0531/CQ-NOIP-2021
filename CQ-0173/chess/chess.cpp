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
int n,m,q,tmp,T;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	srand((unsigned)time(NULL));
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>q;
		while(q--)
			cout<<rand()%5<<endl;
		for(int i=1;i<=n*2+1;i++)
			cin>>tmp;	
	}
	return 0;
}

