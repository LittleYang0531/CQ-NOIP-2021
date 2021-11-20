#include <fstream>
#include <cstring>
#include <queue>

namespace tkz {
	struct reader {
		std::istream& is;

		template <typename T>
		operator T() { T t; is >> t; return t; }
	};
}

int main() {
	using namespace std;
	using namespace tkz;

	ifstream cin("chess.in");
	ofstream cout("chess.out");
	reader read{cin};

    for (int T = read; T--; ) {
        int n = read, m = read, q = read;
        char a[n + 1][m], b[n][m + 1];
        for (int i = 1; i <= n; ++i)
        	for (int j = 1; j < m; ++j)
        		a[i][j] = read;
        for (int i = 1; i < n; ++i)
        	for (int j = 1; j <= m; ++j)
        		b[i][j] = read;
    	char c[n + 1][m + 1]; memset(c, 0, sizeof(c));
		int l[n + 1][m + 1]; memset(l, 0, sizeof(l));
    	while (q--) {
    		int col = read, lv = read, i = read, j = read;
    		c[i][j] = col;
    		l[i][j] = lv;
    		bool v[n + 1][m + 1]; memset(v, 0, sizeof(v));
    		#define emp(i, j) (!c[i][j])
    		#define eat(i, j) (col != c[i][j] && lv >= l[i][j])
    		{
    			queue<pair<int, int>> q;
	    		q.emplace(i, j);
	    		while (!q.empty()) {
	    			int i = q.front().first, j = q.front().second; q.pop();
		    		if (j > 1 && !v[i][j - 1] && a[i][j - 1] == '3' && eat(i, j - 1)) {
		    			v[i][j - 1] = true;
		    			if (emp(i, j - 1)) q.emplace(i, j - 1);
					}
		    		if (j < m && !v[i][j + 1] && a[i][j] == '3' && eat(i, j + 1)) {
		    			v[i][j + 1] = true;
		    			if (emp(i, j + 1)) q.emplace(i, j + 1);
					}
		    		if (i > 1 && !v[i - 1][j] && b[i - 1][j] == '3' && eat(i - 1, j)) {
		    			v[i - 1][j] = true;
		    			if (emp(i - 1, j)) q.emplace(i - 1, j);
					}
		    		if (i < n && !v[i + 1][j] && b[i][j] == '3' && eat(i + 1, j)) {
		    			v[i + 1][j] = true;
		    			if (emp(i + 1, j)) q.emplace(i + 1, j);
					}
				}
			}
			for (int y = j; y > 1 && a[i][y - 1] == '2' && eat(i, y - 1); --y) {
				v[i][y - 1] = true;
				if (!emp(i, y - 1)) break;
			}
			for (int y = j; y < m && a[i][y] == '2' && eat(i, y + 1); ++y) {
				v[i][y + 1] = true;
				if (!emp(i, y + 1)) break;
			}
			for (int x = i; x > 1 && a[x - 1][j] == '2' && eat(x - 1, j); --x) {
				v[x - 1][j] = true;
				if (!emp(x - 1, j)) break;
			}
			for (int x = i; x < n && a[x + 1][j] == '2' && eat(x + 1, j); ++x) {
				v[x + 1][j] = true;
				if (!emp(x + 1, j)) break;
			}
    		if (j > 1 && a[i][j - 1] == '1' && eat(i, j - 1)) v[i][j - 1] = true;
    		if (j < m && a[i][j] == '1' && eat(i, j + 1)) v[i][j + 1] = true;
    		if (i > 1 && b[i - 1][j] == '1' && eat(i - 1, j)) v[i - 1][j] = true;
    		if (i < n && b[i][j] == '1' && eat(i + 1, j)) v[i + 1][j] = true;
			int c = 0;
			for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= m; ++j)
					if (v[i][j]) ++c;
			cout << c << '\n';
		}
    }

	return 0;
}
