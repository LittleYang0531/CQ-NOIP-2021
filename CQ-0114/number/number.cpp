#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<int> p;
int T,ans,tail=8;
bool anss;

bool boli(int x){
	while(x>0){
	  if((x%10)!=7) x/=10;
		else return true;
		 		   	    }
	return false;
}
bool beishu(int x){
	for(int i=0;i<p.size();i++)
	 if(x%p[i]==0) return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	p.push_back(7);
	scanf("%d",&T);
	int x;
	for(int i=1;i<=T;i++) {
		scanf("%d",&x);
		for(int j=tail;j<x;j++)
		{   if(boli(j))
		    	p.push_back(j);
		}
		tail=max(x,tail);
		if(boli(x)){
			p.push_back(x);
			printf("-1\n");
			continue;
		}
		if(beishu(x)){
			printf("-1\n");
			continue;
		}
		for(int j=x+1;;j++)
		 {
		 	 tail=max(tail,j);
		 	 if(boli(j)) { p.push_back(j);}
		 	 else if(!beishu(j)){printf("%d\n",j);
		 	  break;
			  }
		 }
        }
	return 0;
}

