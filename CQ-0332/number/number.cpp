#include <bits/stdc++.h>
using namespace std;
const int MAX=10001005;
inline int read(int &x){
	int s=0, f=1; char c=getchar();
	while(c < '0' || c > '9'){ if(c == '-') f=-1; c=getchar(); }
	while(c >= '0' && c <= '9') s=(s << 3)+(s << 1)+c-'0', c=getchar(); x=s*f;
}
int t, x, ton[MAX+5];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(t);
	for(int i = 1; i <= MAX; ++i){
		if(ton[i]) continue;
		int x = i;
		while(x > 0){
			if(x%10 == 7){
				ton[i]=1;
				break;
			} x/=10;
		}
		if(ton[i])
			for(int j = i+i; j < MAX; j+=i) ton[j]=1;
	}
	for(int i = 1; i <= t; ++i){
		read(x);
		if(ton[x]){
			cout<<"-1\n";
			continue;
		}
		for(int ans = x+1; ; ++ans)
			if(!ton[ans]){
				cout<<ans<<"\n";
				break;
			}
	}
	return 0;
}
/*
!?Ԥ�����Ȼ������!?
1e7������Ӧ�ò���ը��?
����Ϊʲô��cout������printf��???
ͬ����t ��200000 �� x ��10000000�ķ�Χ,cout���0.7s����,��printf��1.5s����!?
......���ִ󷨺�!!! stO ���㽴 Orz 
*/
