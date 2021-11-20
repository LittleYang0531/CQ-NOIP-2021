#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cstdlib>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pc putchar
const int N=1e5+5,INF=0x3f3f3f3f,mod=1e9+7;
int n,a[N],ans;
int read()
{
	int r=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		r=r*10+(ch^48);
		ch=getchar();
	}
	return r*f;
}
using namespace std;
int pf(int a)
{
	return a*a;
}
namespace zhijie
{
	void slove()
	{
		double sum=0,D=0;
		FOR(i,1,n) sum+=a[i]*1.0;
		
		sum/=n;
		FOR(i,1,n) D+=((a[i]*1.0-sum)*(a[i]*1.0-sum));
		cout<<D*n;
	}
}
namespace monituihuo
{
	int ls[N];
	void SA()
	{
		double T=5000;
		while(T>=1e-12)
		{
			int RD=rand()%n+1;
			int bad=ls[RD-1]+ls[RD+1]-ls[RD];
			if(ls[RD-1]>bad||ls[RD+1]<bad||RD==1||RD==n) continue;
			int sum=0,he=0,merami=ls[RD];
			ls[RD]=bad;
			FOR(i,1,n) he+=ls[i];
//		400
//1 1 2 2 3 3 4 4 4 4 4 5 6 6 7 7 8 9 9 9 9 11 12 13 13 13 13 13 13 13 14 14 14 14 14 15 15 16 17 18 19 19 20 20 20 21 21 21 21 21 23 24 25 25 26 26 26 26 26 27 28 28 29 29 29 29 29 29 30 30 31 31 31 31 31 31 32 32 32 32 33 34 34 35 36 43 44 45 46 47 48 49 54 55 55 56 114 356 356 356 357 357 358 359 359 359 360 361 362 362 363 363 363 364 364 364 365 366 366 366 367 367 367 368 369 369 370 370 371 372 373 376 377 377 378 379 380 380 380 380 380 381 381 382 383 383 383 383 384 385 386 386 387 388 388 389 389 390 390 390 390 390 390 391 392 399 399 399 400 401 411 412 413 413 413 413 413 413 414 414 414 414 414 414 414 414 415 416 417 418 418 418 418 419 420 420 424 425 425 426 427 427 428 429 429 429 429 429 429 429 429 429 430 431 432 433 434 434 434 434 435 435 436 436 437 437 437 437 437 437 437 437 438 438 439 439 440 440 441 441 441 442 442 443 444 444 444 447 448 448 449 449 457 457 458 459 460 460 461 462 463 463 463 464 464 464 464 465 465 465 465 466 466 467 468 468 468 469 470 470 471 471 471 471 471 471 471 471 472 472 472 472 473 474 475 476 477 478 478 479 480 481 481 481 482 482 482 482 482 483 484 484 484 484 484 484 484 485 485 485 485 485 486 487 487 487 488 489 489 489 489 490 491 491 492 493 494 494 494 495 495 495 495 496 496 496 496 496 496 497 497 497 498 498 498 499 500 500 500 501 502 502 502 503 504 504 504 507 507 507 508 510 510 510 512 513 513 513 513 514 515 515 515 516 516 517 518 518 518 518 518 518 519 520 534 553 576 580 592 600
			FOR(i,1,n)
			{


				sum+=pf(abs(n*ls[i]))+pf(abs(he))-2*n*he*ls[i];
			}
//		cout<<"!!"<<sum;
			sum/=n;
			if(sum>ans&&(1.0*rand()>exp((sum-ans)/T)*32767.0)) ls[RD]=merami;
			ans=min(sum,ans);
			T*=0.993;
		}
	}
	void solve()
	{
		srand(time(0));
		while(1.0*clock()<850.0)
		{
			FOR(i,1,n) ls[i]=a[i];
			SA();
		}
		cout<<ans;
	}
}


int main()
{
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();
	FOR(i,1,n) a[i]=read();
	ans=INF;
	if(n<=100) monituihuo::solve();
	else zhijie::slove();
	return 0;
}
