/*Fin*/

#include <iostream>
#include <cstdio>

using namespace std;

int readInt()
{
	bool neg = 0;
	int num = 0;
	
	char c = getchar();
	
	while(c==' ' || c=='\n')	c = getchar();
	while(c == '-')	neg = !neg,	c = getchar();
	while(c>='0' && c<='9')	num = (num<<1) + (num<<3) + c - '0',	c = getchar();
	
	return neg ? -num : num;
}

const int N = 1e7 + 4;

bool wrong[N];

bool notR(int num)
{
	if(num % 7 == 0)
		return 1;
	
	while(num > 0){
		if(num % 10 == 7)
			return 1;
		num /= 10;
	}
	
	return 0;
}

void solve()
{
	for(int i=1; i<=N; ++i){
		if(wrong[i])
			continue;
		if(notR(i)){
			for(int j=i; j<=N; j+=i)
				wrong[j] = 1;
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	solve();
	
	int T = readInt();
	
	while(T--){
		int now = readInt();
		
		if(wrong[now]){
			printf("-1\n");
			continue;
		}
		
		for(int i=now+1; i<=N; ++i){
			if(!wrong[i]){
				printf("%d\n", i);
				break;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
