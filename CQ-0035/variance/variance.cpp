#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
bool ppp;
const int N=10010+9;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int sa[30],tp;
void write(int x){
	if(x<0){putchar('-'),x=-x;}
	if(!x){putchar('0');return;}
	while(x)sa[++tp]=x%10,x/=10;
	while(tp){putchar(sa[tp]+'0');tp--;}
	return;
}
int n,k,ans,a[N],b[N];
void dfs(int sum,int cnt,int dep,int res,int last){//n个，和为k; 
	if(sum<=k&&cnt<=n)ans=max(ans,res);
	else return;
	Rof(i,k,last)dfs(sum+i*dep,cnt+i,dep+1,res*i,i);//枚举个数 
}
namespace brute{
	map<vector<int>,int>mp;
	void dfs(vector<int> A){
		if(mp[A])return;
		mp[A]=1;
		for(int i=1;i<(int)A.size()-1;i++){
			A[i]=A[i-1]+A[i+1]-A[i];
			dfs(A);
			A[i]=A[i-1]+A[i+1]-A[i];
		}
	}
	void solve(){
		vector<int>A;rep(i,n)A.push_back(a[i]);
		dfs(A);
		int ans=1e9+7;
		for(map<vector<int>,int>::iterator it=mp.begin();it!=mp.end();it++){
			A=(*it).first;int res=0,S=0;
			rep(i,n)res+=A[i-1]*A[i-1]*n,S+=A[i-1];
			res=res-2*S*S+S*S;
			if(res<ans)ans=res;
		}
		for(map<vector<int>,int>::iterator it=mp.begin();it!=mp.end();it++){
			A=(*it).first;int res=0,S=0;
			rep(i,n)res+=A[i-1]*A[i-1]*n,S+=A[i-1];
			res=res-2*S*S+S*S;
//			if(res==ans){rep(i,n-1)cout<<A[i]-A[i-1]<<" ";puts("");break;}
		}
		cout<<ans<<endl;
		exit(0);
	}
}
struct node{
	int x,cnt;
	node(int xx=0,int vv=0){x=xx,cnt=vv;}
}B[N];int top;
int c[N];
bool cmp(int x,int y){return x>y;}
namespace p100{
	int cho[N],ans=1e17;
	void dfs(){
		while(1){
			int j=1;c[1]=a[1];
			rep(i,top)rep(k,cho[i]){j++;c[j]=c[j-1]+B[i].x;}
			Rof(i,top,1)For(k,cho[i]+1,B[i].cnt){j++;c[j]=c[j-1]+B[i].x;}
			int S=0,res=0;
			rep(i,n)res+=c[i]*c[i]*n,S+=c[i];
			res=res-2*S*S+S*S;
			ans=min(ans,res);
			
			int qwe=1;
			cho[qwe]++;while(cho[qwe]==B[qwe].cnt+1){cho[qwe]=0,cho[++qwe]++;}
			if(qwe==top+1)break;
		}
	}
	void solve(){
		sort(b+1,b+n,cmp);/*递减的*/b[n]=1e9;
		//直接枚举状态然后计算答案
		int len=0; 
		rep(i,n-1){
			len++;
			if(b[i]!=b[i+1]){
				B[++top]=node(b[i],len);
				len=0;
			}
		}
		int res=1;
		rep(i,top)res=res*(B[i].cnt+1);
		B[top+1].cnt=1;
		dfs();
		cout<<ans<<endl;
	}
}
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
//	system("fc variance.out variance3.ans");
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	n=read();rep(i,n)a[i]=read();
	rep(i,n)b[i]=a[i+1]-a[i]; 
	p100::solve();
//	brute::solve();
	return 0;
}

