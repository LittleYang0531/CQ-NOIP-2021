#include<bits/stdc++.h>
template<class I>
void Read(I& x) {
	x=0;
	char c=getchar();
	bool f=0;
	while(c<'0' || c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0' && c<'9') {
		x=x*10+(c&15);
		c=getchar();
	}
	if(f) x=-x;
}
template<class I,class... Args>
void Read(I& x,Args&... args) {
	Read(x),Read(args...);
}
signed main() {
    std::freopen("fre.in","r",stdin);
	return 0;
}