#include <bits/stdc++.h>
#define N 10000000
using namespace std;
int T,x,fla[N],de,qe,s,e,pe,mv;
bool a[N+2];
bool dd(int q){
	while(q){
		if(q%10==7) return 1;
		q/=10;
	}
	return 0;
}
void pr(){
	for(int i=1;i<=N;++i){
		if(dd(i)){
			for(int j=i;j<=N;j+=i) a[j]=1;
		}
	}
	return;
}
int f(){
	s=x+mv;e=s+120;
	for(int i=s;i<=e;i++){
		if(a[i]==0){
			return i;
		}
	}
	return -1;
}
int find(){
	if(fla[x]) return fla[x];
	mv=1;
	de=f();
	if(de!=-1) return de;
	mv=100;
	pe=f();
	if(pe!=-1) return pe;
	mv=1000;
	return f();
}
void gfla(){
	fla[69999]=80000;
fla[169996]=180001;
fla[269999]=280001;
fla[369998]=380003;
fla[469995]=480003;
fla[569999]=580001;
fla[669995]=680003;
fla[699999]=800000;
fla[869999]=880001;
fla[969999]=980002;
fla[1069993]=1080006;
fla[1169998]=1180009;
fla[1269995]=1280000;
fla[1369993]=1380004;
fla[1469999]=1480001;
fla[1569999]=1580003;
fla[1669999]=1680004;
fla[1699995]=1800002;
fla[1869991]=1880002;
fla[1969998]=1980002;
fla[2069999]=2080000;
fla[2169995]=2180006;
fla[2269991]=2280011;
fla[2369999]=2380003;
fla[2469995]=2480003;
fla[2569993]=2580008;
fla[2669999]=2680003;
fla[2699999]=2800001;
fla[2869982]=2880013;
fla[2969998]=2980001;
fla[3069995]=3080006;
fla[3169995]=3180010;
fla[3269999]=3280000;
fla[3369999]=3380012;
fla[3469999]=3480011;
fla[3569989]=3580001;
fla[3669999]=3680011;
fla[3699996]=3800003;
fla[3869993]=3880003;
fla[3969998]=3980003;
fla[4069993]=4080001;
fla[4169999]=4180006;
fla[4269999]=4280002;
fla[4369993]=4380001;
fla[4469999]=4480001;
fla[4569995]=4580003;
fla[4669999]=4680001;
fla[4699995]=4800002;
fla[4869989]=4880006;
fla[4969995]=4980004;
fla[5069998]=5080003;
fla[5169998]=5180003;
fla[5269993]=5280008;
fla[5369999]=5380003;
fla[5469995]=5480003;
fla[5569981]=5580005;
fla[5669995]=5680001;
fla[5699996]=5800010;
fla[5869999]=5880019;
fla[5969998]=5980012;
fla[6069995]=6080003;
fla[6169998]=6180001;
fla[6269995]=6280003;
fla[6286961]=6288033;
fla[6369999]=6380002;
fla[6469999]=6480003;
fla[6569999]=6580010;
fla[6669998]=6680006;
fla[6699998]=6800002;
fla[6869969]=6880009;
fla[6969995]=6980005;
fla[6999998]=8000000;
fla[8069998]=8080000;
fla[8169998]=8180002;
fla[8269999]=8280001;
fla[8369996]=8380018;
fla[8469998]=8480002;
fla[8569996]=8580013;
fla[8586966]=8588029;
fla[8669998]=8680003;
fla[8699993]=8800009;
fla[8869999]=8880002;
fla[8969993]=8980003;
fla[9069989]=9080003;
fla[9169999]=9180001;
fla[9269993]=9280001;
fla[9369989]=9380002;
fla[9469991]=9480001;
fla[9569995]=9580001;
fla[9669999]=9680003;
fla[9699999]=9800002;
fla[9869999]=9880001;
fla[9969998]=9980006;
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	pr();
	gfla();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&x);
		if(a[x]) puts("-1");
		else printf("%d\n",find());
	}
	return 0;
}
