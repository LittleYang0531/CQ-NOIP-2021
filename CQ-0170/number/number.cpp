// 草。谢谢您。

// 讲个笑话。这个 laoer 一直以为递归快写比
// printf 慢很多。直到她看到自己用了快写后
// 大样例 4 从 1.69s 变成了 0.69s（没吸氧）
// 她觉得自己可能是个傻逼。 
 
#include<cstdio>
#include<algorithm>
const int Sub1=1e4;
const int lmt=2e5+5;
const int maxt=2e5+5;
const int limit=1e7+5;
const int maxn=1e7+10;
struct _{
	int d,u,ans;
	bool operator<(const _ q)const{
		return u<q.u;
	}
};
int T,x;
_ a[maxt];
bool vis[maxn],vis2[maxn];
inline bool cmp(_ x,_ y){ return x.d<y.d; }
void read(int&x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0', ch=getchar();
	return;
}
void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+'0');
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	for(int i=1;i<=limit;++i){
		if(vis2[i]) continue;
		x=i; while(x){
			if(x%10==7){
				vis[i]=1;
				break;
			}
			x/=10;
		}
		if(vis[i])
		for(int j=i;j<=limit;j+=i)
			vis[j]=vis2[j]=1;
	}
	for(int i=1;i<=T;++i){
		read(a[i].u);
		a[i].d=i;
	}
	std::sort(a+1,a+T+1);
	for(int i=1;i<=T;++i){
		if(vis[a[i].u]) a[i].ans=-1;
		else if(a[i].u==a[i-1].u)
			a[i].ans=a[i-1].ans;
		else {
			for(int j=a[i].u+1;j<=limit;++j){
				if(!vis[j]){
					a[i].ans=j;
					break;
				}
			}
		}
	}
	std::sort(a+1,a+T+1,cmp);
	for(int i=1;i<=T;++i){
		if(a[i].ans==-1) puts("-1");
		else print(a[i].ans), putchar('\n');
	}
	return 0;
}

/*
喂，看起来你除了 T1 也没有能拿分的题了
所以要不要干点其他的事情，比如复习一下数学，别周考又下 140？
阿巴阿巴
代数式：用运算符号将数与字母连接起来的式子 
整式：单项式与多项式的合称
单项式：数与字母的乘积，注意 (a+b)/2 是多项式的一种书写方式 
多项式：若干个单项式之和
数轴：有原点、正方向、单位长度的直线
好像就没有什么别的可以背了 日
秋季风（划掉）邱丹好像还要抽你历史 日 
那么 元谋人生活在距今 草 忘了
不背了！（潇洒 
T1 如果不艾姆艾尔艺的话应该能拿全分 O2 救我狗命 
我草，T2 是什么东西，排列组合？二进制？跟我一个长期数学上不了 
140 的 SB 说这些？ 
为什么这些 n 和 m 都是定值啊，有什么性质吗，我他妈推不出来啊 
T3 这个递增性质好像除了让我不减爆就没卵用了 所以这是个啥啊，
DP？不像。
然后就花了 1.5h 打了 T4 的 8 分暴力分不过应该可以再预处理一
下然后 O(nmq) 罢 不想打 他妈 n, m <= 1e5 我他妈怎么输入啊 
叮咚！
身体状况常自查，咳嗽咽痛要警惕。
不适立刻报老师，发热立即赴门诊。
*/
