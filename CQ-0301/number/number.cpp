#include <bits/stdc++.h>
using namespace std;
int t,x;
bool p(int x){//1��0�� 
	//�Ƿ�Ϊ7�ı���
	if(x%7==0)return 1; 
	//��λ���Ƿ���7
	for(int i=x;i>0;i/=10)if(i%10==7)return 1;
	//�����Ƿ���7�����
	for(int i=2;i<=x;i++)
		while(x%i==0){
			x/=i;
			if(p(x))return 1;
		}
	return 0; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		if(p(x)){printf("-1\n");continue;}
		for(int now=x+1;;now++)
			if(!p(now)){
				printf("%d\n",now);
				break;
			}
		}
	return 0;
}
