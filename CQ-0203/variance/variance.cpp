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
#include <ctime>
#include <cmath>
#include <vector>
typedef long long ll;
int n;
std::vector<int> dataarr;
const ll inf = 1e15;
ll randx(ll l = 0, ll r = inf){
	return (rand() | rand() << 15) % (r - l + 1) + l;
}
ll var(){
	ll sq_ele = 0, sq_all = 0;
	for (auto it: dataarr)
		sq_ele += it * it; 
	sq_ele *= n;
	for (auto it: dataarr)
		sq_all += it;
	return sq_ele - sq_all * sq_all;
}
int main(){
	io_init("variance");
	srand(time(0));
	fin >> n;	
	dataarr.resize(n);
	for (auto& it: dataarr)
		fin >> it;
	ll ans = inf;
	int t = clock();
	for (double T = 1e12; T > 1e-12; T *= 0.99995){
		int position = randx(1, n - 2);
		int value = dataarr[position];
		dataarr[position] = dataarr[position - 1] + dataarr[position + 1] - dataarr[position];
		ll newvar = var();
		if (newvar < ans)
			ans = newvar;
		else if(T * exp(newvar - ans) < randx() / inf)
			dataarr[position] = value;
		if (t - clock() > 950)
			break;
	}
	fout << ans << std::endl;
	return 0;
}
