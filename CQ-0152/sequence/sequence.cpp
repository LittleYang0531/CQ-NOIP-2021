#include <bits/stdc++.h>
#define LL long long
#define kkk 998244353//Ä¤°Ý3k 
using namespace std;
LL v[105], c[105][35]/*Ð¡ÇòÓëºÐ×Ó*/, dp[105][35][35][16];//µ±Ç°Î»£¬aÖÐÔªËØÊý£¬SÖÐ1µÄÊýÁ¿£¬×´Ñ¹;
int f(int x){
	int tot = 0;
	while(x){
		tot++;
		x = (x & (x - 1));
	}
	return tot;
}
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	for(int i = 0; i <= 30; i++){
		c[1][i] = 1;
	}
	for(int i = 1; i <= 100; i++){
		c[i][0] = 1;
	}
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 30; j++){
			for(int k = 0; k <= j; k++){
				c[i][j] = (c[i][j] + c[i - 1][k]) % kkk;
			}
		}
	}
	int n, m, k, t, tt, ttt, tttt, ttttt;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i <= m; i++) scanf("%lld", &v[i]);
	dp[0][0][0][0] = 1;
	tt = 1;
	for(int i = 1; i <= n; i++){
		t = f(i);
		tt = (tt * v[0]) % kkk;
		dp[0][i][t][i / 2] = tt;
	}
	for(int i = 1; i <= m; i++){//°Ñh¡¢j¡¢w¡¢mËã·¨·¢Ñï¹â´ó 
		for(int a = 0; a <= n; a++){
			for(int j = 0; j <= a; j++){
				for(int b = 0; b < 16; b++){
					ttttt = 1;
					for(int rp = 0; rp <= a; rp++){
						t = (b << 1) - rp;
						tt = ((b << 1) ^ 1) - rp;
						ttt = j - f(b << 1) + f(t);
						tttt = j - f((b << 1) ^ 1) + f(tt);
						if(0 <= t && t < 16 && 0 <= ttt && ttt <= 30) dp[i][a][j][b] = (dp[i][a][j][b] + ((c[a - rp + 1][rp] * dp[i - 1][a - rp][ttt][t]) % kkk * ttttt) % kkk) % kkk;
						if(0 <= tt && tt < 16 && 0 <= tttt && tttt <= 30) dp[i][a][j][b] = (dp[i][a][j][b] + ((c[a - rp + 1][rp] * dp[i - 1][a - rp][tttt][tt]) % kkk * ttttt) % kkk) % kkk;
						ttttt = (ttttt * v[i]) % kkk;
						if(tt < 0) break;
					}
//					printf("dp[%d][%d][%d][%d] = %d\n", i, a, j, b, dp[i][a][j][b]);
				}
			}
		}
	}
	LL ans = 0;
	for(int j = 0; j <= k; j++){
		for(int rp = 0; rp < 16; rp++){
			ans = (ans + dp[m][n][j][rp]) % kkk;
		}
	}
	printf("%d", ans);
	return 0;
}
//noip(lxl) AKs me 
//I fuck €€¡ê!
//ÎÒÒªÉÏÃÔ»óÐÐÎª 
//€€¡ê = Alt + 128 Alt +128 Alt + 163 
