//�Ǿ������ݲݵĽ�����,����̫���� 
//���� ���㽴 �뽴 ,���ǲ��й�����δ��,ף���ǳɹ�XD 
#include <bits/stdc++.h>
using namespace std;

const int N=5100;

int n,m,q;
int col[N][N],lv[N][N];

int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)){ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	n=read();m=read();q=read();
	while(q--){
		cout<<"AFO"<<endl;
	}
	return 0;
}
