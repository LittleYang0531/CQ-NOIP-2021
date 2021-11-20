#include<bits/stdc++.h>
using namespace std;
int T,x,nxt[10011000],lst[10011000],ask[200001],mx,p10[8]={1,10,100,1000,10000,100000,1000000,10000000};
bool can[10011000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for (int i=1;i<=T;i++)
	{
		cin>>ask[i];
		if (ask[i]>mx)mx=ask[i];
	}
	mx+=10000;
	memset(can,1,mx+1);
	for (int i=1;i<=mx;i++)
	{
		nxt[i]=i+1;
		lst[i]=i-1;
	}
	for (int i=1;i<=mx;i=nxt[i])
		if (can[i])
		{
			bool have7=0;
			for (int j=i;j;j/=10)
				if (j%10==7)
				{
					have7=1;
					break;
				}
			if (have7)
			{
				nxt[lst[i]]=nxt[i];
				lst[nxt[i]]=lst[i];
				for (int j=i;j<=mx;j+=i)
				{
					can[j]=0;
					nxt[lst[j]]=nxt[j];
					lst[nxt[j]]=lst[j];
				}
			}
		}
		else
		{
			nxt[lst[i]]=nxt[i];
			lst[nxt[i]]=lst[i];
		}
	for (int i=1;i<=T;i++)
		if (!can[ask[i]])cout<<"-1\n";
		else cout<<nxt[ask[i]]<<'\n';
}
