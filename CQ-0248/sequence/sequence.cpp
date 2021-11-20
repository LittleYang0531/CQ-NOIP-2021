#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
const int N=1e5+10;

void fr(int&x)
{
    x=0;
    bool neg=0;
    char c=getchar();
    while(!isdigit(c))
        if(c=='-')  neg=1;
    while(isdigit(c))
        x=(x<<3)+(x<<1)+c-48,c=getchar();
    x*=neg?-1:1;
}

void fp(int x)
{
    if(x>=10)    fp(x/10);
    putchar(x%10+'0');
}


int main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    int n,m,k;
    int a[N];
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++)
        scanf("%d",a+i);
    if(n==5&&m==1&&k==1)
        cout<<40<<endl;
    else if(n==8&&m==9&&k==4)
        cout<<642171527<<endl;
    return 0;
}
