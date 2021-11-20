#include<bits/stdc++.h>
using namespace std;
int a[200001],cnt;
//fuckccf引流大法 
//没有人会看到我
//看到我的都不是人
//说你呢
//还看
//好吧
//......
//......
//......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //......
//......
 //恭喜你被我耽误了一分钟！ 
bool check2(int x)
{
	while(x>1)
	{
		if(x%10==7)
		{
			return 1;
		}
		x/=10;
	}
	return 0;
}
bool check(int x)
{
	for(int i = 1;i <= cnt;i++)
	{
		if(x%a[i]==0)
		{
			return 1;
		}
	}
	for(int i = 1;i <= x;i++)
	{
		if(x%i==0&&check2(i))
		{
			a[++cnt]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int t,x,u;
	cin >> t;
	while(t--)
	{
		scanf("%d",&x);
		u=x+1;
		if(check(x))
		{
			printf("-1\n");
			continue;
		}
		while(1)
		{
			if(check(u))
			{
				u++;
			}
			else
			{
				printf("%d\n",u);
				break;
			}
		}
	}
	return 0;
}


//look at here！ 
/*
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
bool a[9][5];
int main()
{
	int x=22,y=100;
//	cin >> y;
	srand(time(0));
	while(1)
	{
		for(int i = 1;i <= x;i++)
		{
			printf("|  ");
			for(int j = 0;j < 5;j++)
			{
				if(a[i][j]==0)
				{
					printf("   ");
				}
				else
				{
					printf("## ");
				}
			}
			printf("|  \n");
		}
		printf(" ----------------- \n");
		printf("   A  S  D  F  G   \n");
		for(int i = x-1;i >= 0;i--)
		{
			for(int j = 0;j < 5;j++)
			{
				a[i+1][j]=a[i][j];
			}
		}
//		Sleep(y);
		if(rand()%2==1)
		{
			a[1][rand()%5]=1;
		}
		
		system("cls");
	}
	return 0;
}
*/
