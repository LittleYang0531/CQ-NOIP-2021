#include<cstdio>
int n,m,f,ff,i,j,q,x,y;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&n);
	do{scanf("%d",&m);f=1;
		for(i=7;i<=m;++i){
			x=i;y=1;
			while(x>0){if((x%10)==7){y=0;break;}x/=10;}
			if(y)continue;
			if((m%i)==0){q=m/i;
				for(j=1;f&&((i*j)<=m);++j){
					if((i*j)==m){printf("-1\n");f=0;}
				}
			}
		}
		ff=f;
		while(f){++m;f=0;
			for(i=7;i<=m;++i){
				x=i;y=1;
				while(x>0){
					if((x%10)==7){y=0;break;}
					x/=10;
				}
				if(y)continue;
				if((m%i)==0){q=m/i;
					for(j=1;(i*j)<=m;++j){
						if((i*j)==m){f=1;}
					}
				}
			}
		}
		if(ff)printf("%d\n",m);
	}while(--n);
	return 0;
}
