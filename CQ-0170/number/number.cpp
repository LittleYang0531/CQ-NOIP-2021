// �ݡ�лл����

// ����Ц������� laoer һֱ��Ϊ�ݹ��д��
// printf ���ܶࡣֱ���������Լ����˿�д��
// ������ 4 �� 1.69s ����� 0.69s��û������
// �������Լ������Ǹ�ɵ�ơ� 
 
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
ι������������� T1 Ҳû�����÷ֵ�����
����Ҫ��Ҫ�ɵ����������飬���縴ϰһ����ѧ�����ܿ����� 140��
���Ͱ���
����ʽ����������Ž�������ĸ����������ʽ�� 
��ʽ������ʽ�����ʽ�ĺϳ�
����ʽ��������ĸ�ĳ˻���ע�� (a+b)/2 �Ƕ���ʽ��һ����д��ʽ 
����ʽ�����ɸ�����ʽ֮��
���᣺��ԭ�㡢�����򡢵�λ���ȵ�ֱ��
�����û��ʲô��Ŀ��Ա��� ��
�＾�磨�������񵤺���Ҫ������ʷ �� 
��ô Ԫı�������ھ�� �� ����
�����ˣ������� 
T1 �������ķ�����յĻ�Ӧ������ȫ�� O2 ���ҹ��� 
�Ҳݣ�T2 ��ʲô������������ϣ������ƣ�����һ��������ѧ�ϲ��� 
140 �� SB ˵��Щ�� 
Ϊʲô��Щ n �� m ���Ƕ�ֵ������ʲô�������������Ʋ������� 
T3 ����������ʺ���������Ҳ�������û������ �������Ǹ�ɶ����
DP������
Ȼ��ͻ��� 1.5h ���� T4 �� 8 �ֱ����ֲ���Ӧ�ÿ�����Ԥ����һ
��Ȼ�� O(nmq) �� ����� ���� n, m <= 1e5 ��������ô���밡 
���ˣ�
����״�����Բ飬������ʹҪ���衣
�������̱���ʦ���������������
*/
