#include<cstdio>
int al,ame,a[10000],minx=100000000,i,sum,floor,cl[1000000],flag;
float x,y,b,t,d;
void Dfs(int um){
	if(floor>3000){return ;}
	++floor;
	int cb,j=0;sum=0;d=0;
	for(j;j<al;++j){sum+=a[j];}
	x=sum;b=x/y;
	for(j=0;j<al;++j){t=a[j]-b;d+=t*t;}
	d*=al;
	for(j=0;j<flag;++j){if(d==cl[j])return ;}
	cl[flag]=d;;++flag;if(d<minx)minx=d;
	for(j=1;j<=ame;++j){
		if((a[j]!=(a[j-1]+a[j+1]-a[j]))&&(j!=um)){
			cb=a[j];
			a[j]=a[j-1]+a[j+1]-a[j];
			Dfs(j);
			a[j]=cb;
		}
	}
	--floor;
}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&al);ame=al-2;y=al;
	for(;i<al;++i)scanf("%d",&a[i]);
	Dfs(0);
	printf("%d",minx);
	return 0;
}
