#include <queue>
#include <map>
#include <cstdio>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;

typedef struct Node_tag {
	int a[407];
	int sum;
	int sqr_sum;
	Node_tag(){}
	Node_tag(int a_[407]){
		sum = sqr_sum = 0;
		memcpy(a, a_, sizeof(a));
		for (int i = 1; i <= n; i++){
			sum += a[i];
			sqr_sum += a[i] * a[i];
		}
	}
} Node;

const int seed = 1e9 + 7;
int a[10007];
priority_queue<Node> q[1007][407], tmp;
map<ull, int> mp;

bool operator <(const Node a, const Node b){
	return (ll)n * a.sqr_sum - (ll)a.sum * a.sum > (ll)n * b.sqr_sum - (ll)b.sum * b.sum;
}

inline ull hashize(int a[407]){
	ull ans = 0;
	for (register int i = 1; i <= n; i++){
		ans = ans * seed + a[i];
	}
	return ans;
}

int main(){
	ll ans;
	Node fuck;
	freopen("variance.in", "r", stdin);
	freopen("variance.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	fuck = Node(a);
	ans = (ll)n * fuck.sqr_sum - (ll)fuck.sum * fuck.sum;
	q[0][2].push(fuck);
	for (register int i = 1; i <= 1000 && 1.0 * clock() / CLOCKS_PER_SEC < 0.95; i++){
		for (register int j = 2; j < n && 1.0 * clock() / CLOCKS_PER_SEC < 0.95; j++){
			for (register int k = 2; k < n && 1.0 * clock() / CLOCKS_PER_SEC < 0.95; k++){
				if (j != k){
					tmp = q[i - 1][k];
					for (register int l = 1; l <= 10 && !tmp.empty(); l++){
						int pre, nxt;
						Node cur = tmp.top();
						tmp.pop();
						pre = cur.a[j];
						nxt = cur.a[j - 1] + cur.a[j + 1] - pre;
						if (pre == nxt) continue;
						cur.a[j] = nxt;
						ull hash_val = hashize(cur.a);
						if (mp.count(hash_val)) continue;
						mp[hash_val] = true;
						cur.sum += nxt - pre;
						cur.sqr_sum += nxt * nxt - pre * pre;
						q[i][j].push(cur);
					}
				}
			}
			if (!q[i][j].empty()){
				Node dick = q[i][j].top();
				ans = min(ans, (ll)n * dick.sqr_sum - (ll)dick.sum * dick.sum);
			}
		}
		for (register int j = 1; j <= n; j++){
			while (!q[i - 1][j].empty()) q[i - 1][j].pop();
		}
	}
	printf("%lld", ans);
	return 0;
}
