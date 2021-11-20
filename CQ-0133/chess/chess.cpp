#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	srand(time(NULL));
	printf("%d",rand()%998244353+1);
}
