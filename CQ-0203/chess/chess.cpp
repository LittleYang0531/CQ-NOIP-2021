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
struct edge_str{
	int col = -1, level = -1;
	std::vector<int> edge[4];
};
#define castpos(x, y) ((x) * m + (y))
int t, n, m, q;
std::vector<edge_str> mapdata;
#include <set>
std::set<int> pos_save, bsave;
#include <queue>
void bfs_on(int pos, int col, int lv, int x){
#define pedge(p) (mapdata[p].edge[x])
	std::queue<int> q;
	bsave.clear(); 
	for (auto v : pedge(pos)){
		if (mapdata[v].col == -1){
			q.push(v);
			bsave.insert(v);
			pos_save.insert(v);
		}
		else if(mapdata[v].col != col && lv >= mapdata[v].level)
			pos_save.insert(v);
	}
	while (!q.empty()){
		int tmp = q.front();
		q.pop();
		for (auto v : pedge(tmp)){
			if (bsave.find(v) != bsave.end())
				continue;
				if (mapdata[v].col == -1){
				q.push(v);
			bsave.insert(tmp);
				pos_save.insert(v);
			}
			else if(mapdata[v].col != col && lv >= mapdata[v].level)
				pos_save.insert(v);
		}
	}
#undef pedge
}
int main(){
	io_init("chess");
	fin >> t;
	while (t--){
		fin >> n >> m >> q;
		mapdata.clear();
		mapdata.resize(n * m);
		std::string scandata;
		for (int i = 0; i < n; ++i){
			fin >> scandata;
			for (int j = 0; j < m - 1; ++j){
				if (scandata[j] == '1'){
					mapdata[castpos(i, j)].edge[2].push_back(castpos(i, j + 1));
					mapdata[castpos(i, j + 1)].edge[2].push_back(castpos(i, j));	
				}
				else if (scandata[j] == '2'){
					mapdata[castpos(i, j)].edge[1].push_back(castpos(i, j + 1));
					mapdata[castpos(i, j + 1)].edge[1].push_back(castpos(i, j));
				}
				else if (scandata[j] == '3'){
					mapdata[castpos(i, j)].edge[3].push_back(castpos(i, j + 1));
					mapdata[castpos(i, j + 1)].edge[3].push_back(castpos(i, j));
				}
			}
		}
		for (int i = 0; i < n - 1; ++i){
			fin >> scandata;
			for (int j = 0; j < m; ++j){
				if (scandata[i] == '1'){
					mapdata[castpos(i, j)].edge[2].push_back(castpos(i + 1, j));
					mapdata[castpos(i + 1, j)].edge[2].push_back(castpos(i, j));	
				}
				else if (scandata[i] == '2'){
					mapdata[castpos(i, j)].edge[0].push_back(castpos(i + 1, j));
					mapdata[castpos(i + 1, j)].edge[0].push_back(castpos(i, j));	
				}
				else if (scandata[i] == '3'){
					mapdata[castpos(i, j)].edge[3].push_back(castpos(i + 1, j));
					mapdata[castpos(i + 1, j)].edge[3].push_back(castpos(i, j));
				}
			}
		}
	}
	int col = 0, level = 0, x = 0, y = 0;
	for (int i = 0; i < q; ++i){
		fin >> col >> level >> x >> y;
		--x, --y;
		int pos = castpos(x, y);
		mapdata[pos].col = col;
		mapdata[pos].level = level;
		pos_save.clear();
		for	(auto it: mapdata[pos].edge[2])
			pos_save.insert(it);
		bfs_on(pos, col, level, 0);
		bfs_on(pos, col, level, 1);
		bfs_on(pos, col, level, 3);
		fout << pos_save.size() << std::endl;
	}
	return 0;
}
