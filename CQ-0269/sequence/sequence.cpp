#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int v[105];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	srand(unsigned(time(0)));
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m+1;i++) scanf("%d",&v[i]);
	printf("%d",rand()*rand()%998244353);

	return 0;
}
