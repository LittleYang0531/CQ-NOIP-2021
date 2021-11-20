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
#include <bitset>
#include <vector>
const int MAXN = 1.1e7 + 5;
std::bitset<MAXN> examarr;
int ansarr[MAXN];
bool found_7(int x){
	while (x){
		if (x % 10 == 7)
			return true;
		x /= 10;
	}
	return false;
}
void init(){
	examarr.reset();
	for (int i = 7; i < MAXN; ++i){
		if (examarr[i])
			continue;
		if (found_7(i))
			for (int k = 1; k * i < MAXN; ++k)
				examarr[k * i] = true;
	}
	for (int i = MAXN - 1, memnum = -1; ~i; --i){
		ansarr[i] = memnum;
		if (!examarr[i])
			memnum = i;
	}
}
int t, x;
int main(){
	io_init("number");
	init();
	fin >> t;
	while (t--){
		fin >> x;
		if (examarr[x])
			fout << "-1\n";
		else
			fout << ansarr[x] << '\n';
	}
	return 0;
}
