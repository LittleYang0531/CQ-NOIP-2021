#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
int n,ans=0x7fffffff,avg,a[10005],b[10005],c[10005];
int abs(int x){return x<0?-x:x;}
void turn(string s) {
	int sum=0,v=1;
	for(int i=0;i<s.length();i++) {
		if(s[i]=='*') {
			b[++b[0]]=sum;
			sum=0,v=1;
		}else {
			sum+=(s[i]-'0')*v;
			v*=10;
		}
	}
	b[0]=0;
}
string turn1(int a[]) {
	string s="";
	for(int i=1;i<=n;i++) {
		int x=a[i];
		while(x) {
			s+=x%10+'0';
			x/=10;
		}
		s+='*';
	}
	return s;
}
int js(int b[]) {
	int avg=0,sum=0;
	for(int i=1;i<=n;i++)avg+=b[i];
	for(int i=1;i<=n;i++)sum+=(b[i]*n-avg)*(b[i]*n-avg);
	return sum/n;
}
void bfs(string s) {
	queue<string>Q;
	map<string,bool>mp;
	Q.push(s);
	mp[s]=1;
	while(!Q.empty()) {
		string s=Q.front(),t;
		Q.pop();
		turn(s);
		ans=min(ans,js(b));
		for(int i=1;i<=n;i++)c[i]=b[i];
		for(int i=2;i<n;i++) {
			c[i]=c[i-1]+c[i+1]-c[i];
			t=turn1(c);
			if(!mp[t]) {
				mp[t]=1;
				Q.push(t);
			}
		}
	}
}
int main() {
	freopen("variance.in","r",stdin);
	freopen("variance.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
//	if(n<=10) {
		string s=turn1(a);
		bfs(s);
		printf("%d\n",ans);
//	}else {
//		for(int i=1;i<=n;i++)avg+=a[i];
//		for(int k=1;k<=n;k++) {
//			for(int i=2;i<n;i++) {
//				if(abs(a[i]*n-avg)>abs((a[i-1]+a[i+1]-a[i])*n-(avg-a[i]+a[i-1]+a[i+1]-a[i]))) {
//					avg-=a[i];
//					avg+=a[i-1]+a[i+1]-a[i];
//					a[i]=a[i-1]+a[i+1]-a[i];
//				} 
//			}
//		}
//		for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//		cout<<endl;
//		printf("%d",js(a));
//	}
	return 0;
}
