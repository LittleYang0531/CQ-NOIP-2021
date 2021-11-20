#include<bits/stdc++.h>
#define int long long
using namespace std ;
const int M = 110 , mod = 998244353 ;
int n , m , k , v[M] , a[M] , ans = 0 ;
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
int two(int a){
	int sum = 0 ;
	while(a) sum += a % 2 , a /= 2 ;
	return sum ;
}
void doit(int num , int id , int sum2 , int sum3){
	if(sum2 > num) return ;
	if(id == n){
		if(sum2 == num){
			ans += sum3 / v[0] ;
		} 
		return ;
	}
	for(int i = 0 ; i <= m ; i ++) a[id] = i , doit(num , id + 1 , sum2 + (1 << i) , sum3 + v[i]) ;
}
signed main(){
	freopen("sequence.in" , "r" , stdin) ;
	freopen("sequence.out" , "w" , stdout) ;
	n = read_int() , m = read_int() , k = read_int() ;
	for(int i = 0 ; i <= m ; i ++) v[i] = read_int() ;
	for(int i = n ; i <= n * (1 << m) ; i ++){
		if(two(i) <= k){
			doit(i , 0 , 0 , 1) ;
		}
	} 
	write_int(ans) , putchar('\n') ;
	return 0 ;
}
