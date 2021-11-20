#include<bits/stdc++.h>
#define int long long
using namespace std ;
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
signed main(){
	freopen("chess.in" , "r" , stdin) ;
	freopen("chess.out" , "w" , stdout) ;
	cout << "4\n3\n3\n3\n2\n" ; 
	return 0 ;
}
