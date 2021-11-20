#include<bits/stdc++.h>
using namespace std;
int n,a[10005],f[105][105][4005],sum[10005],ans=1e9;
void upd(int &x,int y){
	x=min(x,y);
}
namespace Solve400600{

map<int,int> F[405][405];
void main(){
	for(int i=n;i>1;i--)a[i]=a[i]-a[i-1];
	for(int i=1;i<n;i++)a[i]=a[i+1];
	n--,sort(a+1,a+n+1);
	for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)F[i][i][i*a[1]]=a[1]*a[1]*(n-i+1)*i;
	for(int len=1;len<n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			for(auto p:F[i][j]){
				int k=p.first,v=p.second;
				if(i>1){
					int to=k+a[len+1]*(i-1);
					if(F[i-1][j].count(to))upd(F[i-1][j][to],v+2*a[len+1]*(i-1)*((n+1)*sum[len]-k)+a[len+1]*a[len+1]*(n-i+2)*(i-1));
					else F[i-1][j][to]=v+2*a[len+1]*(i-1)*((n+1)*sum[len]-k)+a[len+1]*a[len+1]*(n-i+2)*(i-1);
				}
				if(j<n){
					int to=k+a[len+1]*(j+1);
					if(F[i][j+1].count(to))upd(F[i][j+1][to],v+2*a[len+1]*(n-j)*k+a[len+1]*a[len+1]*(j+1)*(n-j));
					else F[i][j+1][to]=v+2*a[len+1]*(n-j)*k+a[len+1]*a[len+1]*(j+1)*(n-j);
				}
			}
		}
	}
	for(auto p:F[1][n])ans=min(ans,p.second);
	cout<<ans;
}

}
namespace Solve1000050{
map<int,int> F[55][55];
void main(){
	for(int i=n;i>1;i--)a[i]=a[i]-a[i-1];
	for(int i=1;i<n;i++)a[i]=a[i+1];
	n--,sort(a+1,a+n+1);
	for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i];
	F[51][51][0]=0;
	for(int len=n-100;len<n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(i>51||n-j+1>51)continue;
			for(auto p:F[i][n-j+1]){
				int k=p.first,v=p.second;
				if(i>1){
					int to=k+a[len+1]*(i-1);
					if(F[i-1][n-j+1].count(to))upd(F[i-1][n-j+1][to],v+2*a[len+1]*(i-1)*((n+1)*sum[len]-k)+a[len+1]*a[len+1]*(n-i+2)*(i-1));
					else F[i-1][n-j+1][to]=v+2*a[len+1]*(i-1)*((n+1)*sum[len]-k)+a[len+1]*a[len+1]*(n-i+2)*(i-1);
				}
				if(j<n){
					int to=k+a[len+1]*(j+1);
					if(F[i][n-j].count(to))upd(F[i][n-j][to],v+2*a[len+1]*(n-j)*k+a[len+1]*a[len+1]*(j+1)*(n-j));
					else F[i][n-j][to]=v+2*a[len+1]*(n-j)*k+a[len+1]*a[len+1]*(j+1)*(n-j);
				}
			}
		}
	}
	for(auto p:F[1][1])ans=min(ans,p.second);
	cout<<ans;
}

}
int main(){
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(n>100&&n<=400)return Solve400600::main(),0;
	if(n>400)return Solve1000050::main(),0;
	for(int i=n;i>1;i--)a[i]=a[i]-a[i-1];
	for(int i=1;i<n;i++)a[i]=a[i+1];
	n--,sort(a+1,a+n+1);
	for(int i=1;i<n;i++)sum[i]=sum[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++)f[i][i][i*a[1]]=a[1]*a[1]*(n-i+1)*i;
	for(int len=1;len<n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			//printf("[%d,%d]: ",i,j);
			for(int k=0;k<=4000;k++){
				//if(f[i][j][k]<1e9)printf("(%d,%d) ",k,f[i][j][k]);
				if(i>1&&k+a[len+1]*(i-1)<=4000)
					upd(f[i-1][j][k+a[len+1]*(i-1)],f[i][j][k]+2*a[len+1]*(i-1)*((n+1)*sum[len]-k)+a[len+1]*a[len+1]*(n-i+2)*(i-1));
				if(j<n&&k+a[len+1]*(j+1)<=4000)
					upd(f[i][j+1][k+a[len+1]*(j+1)],f[i][j][k]+2*a[len+1]*(n-j)*k+a[len+1]*a[len+1]*(j+1)*(n-j));
			}
			//puts("");
		}
	}
	for(int i=0;i<=4000;i++){
		ans=min(ans,f[1][n][i]);
	}
	cout<<ans;
	return 0;
}
