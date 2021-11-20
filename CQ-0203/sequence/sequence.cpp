#include <iostream>
//#define DEBUG_STANDIO
#ifndef DEBUG_STANDIO
#include <fstream>
std::ifstream fin;
std::ofstream fout;
#else
#define fin std::cin
#define fout std::cout
#endif
#include <cstring>
void io_init(std::string path_){
#ifndef DEBUG_STANDIO
	fin.rdbuf()->pubsetbuf(nullptr, 1 << 23);
	fout.rdbuf()->pubsetbuf(nullptr, 1 << 23);
	fin.open(path_ + ".in");
	fout.open(path_ + ".out");
#else
	std::ios::sync_with_stdio(false);
#endif 
}
#include <vector>
typedef long long ll;
const ll MOD = 998244353;
std::vector<ll> v, seldata;
ll result = 0;
int n, m, k;
bool exam_data(){
	ll sum = 0;
	for (auto it : seldata)
		sum += 1 << it;
	int resk = 0;
	while (sum){
		resk += sum & 1;
		sum >>= 1;
	}
	return resk <= k;
}
void dfs(int layer = 0){
	if (layer == n){
		if (!exam_data())
			return;
		ll x = 1;
		for (auto it: seldata)
			(x *= v[it]) %= MOD;
		(result += x) %= MOD;
		return;
	}
	for (int i = 0; i <= m; ++i){
		seldata[layer] = i;
		dfs(layer + 1); 
	}
}
int main(){
	io_init("sequence");
	fin >> n >> m >> k;
	v.resize(m + 1);
	for (auto& it : v)
		fin >> it;
	seldata.resize(n);
	dfs();
	fout << result << std::endl;
	return 0;
}
