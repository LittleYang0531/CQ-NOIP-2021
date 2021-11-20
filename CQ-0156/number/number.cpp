#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
const int maxa=1e7+5;
bool cant[maxa];
int apr[maxa],acnt;
int left[maxa],lcnt;
int out[maxa];
void init(){
	for(int i=1;i<=maxa-2;i++){
		if(!cant[i]){
			int ts=i;
			while(ts){
				if(ts%10==7){
					for(int j=i;j<=maxa-2;j+=i)cant[j]=true;
					break;
				}
				ts/=10;
			}
			if(!cant[i])left[++lcnt]=i;
		}
	}
	int nwz=1;
	for(int i=1;i<=maxa-2;i++){
		if(cant[i])continue;
		if(left[nwz]<i)nwz++;
		out[i]=left[nwz+1];
	}
	return;
}
int q;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int x;
		scanf("%d",&x);
		printf("%d\n",out[x]?out[x]:-1);
	}
	return 0;
}
/*
5
90
99
106
114
169
*/
