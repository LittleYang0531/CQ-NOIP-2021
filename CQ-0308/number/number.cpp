#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int N = 1e7 + 100 ;
bool be_ok[N] ;
string read_string(){
	string s = "" ;
	char c = getchar() ;
	while(c == ' ' || c == '\n') c = getchar() ;
	while(c != ' ' && c != '\n') s = s + c , c = getchar() ;
	return s ;
}
void write_string(string s){
	for(int i = 0 ; i < s . size() ; i ++) putchar(s[i]) ;
}
int read_int(){
	int x = 0 ;
	int k = 1 ;
	char c = getchar() ;
	while(c > '9' || c < '0'){
		if(c == '-') k = -1 ; 
		c = getchar() ;
	}  
	while(c <= '9' && c >= '0') x *= 10 , x += (c - '0') , c = getchar() ;
	return x ;
}
void write_int(int x){
	if(x < 0) putchar('-') , x = -x ;
	if(x >= 10) write_int(x / 10) ;
	putchar(x % 10 + '0') ;
}
void OK(int a){
	if(be_ok[a]) return ;
	int b = a ;
	while(b){
		if(b % 10 == 7){
			for(int i = 1 ; i * a <= N ; i ++) be_ok[i * a] = 1 ;
			return ;
		}
		b /= 10 ;
	}
}
signed main(){
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	for(int i = 1 ; i <= N ; i ++) OK(i) ;
	int T ;
	T = read_int() ;
	while(T --){
		int a ;
		a = read_int() ;
		if(be_ok[a] == 1) write_int(-1) , putchar('\n') ;
		else {
			for(a ++ ; be_ok[a] ; ) a ++ ;
			write_int(a) , putchar('\n') ;
		}
	}
	return 0 ;
}
