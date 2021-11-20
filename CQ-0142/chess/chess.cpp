//Nerver gOnna gIve you uP
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
using namespace std;
const int N=4e5,nx[10]={0,1,0,-1},ny[10]={1,0,-1,0};
int t,n,m,Q,colo,lev,X[N],Y[N],col[N],lv[N],ans,con[N];//经过的点，待删除 
bool r[N],poi[N];//r:路程(以点为单位) poi:该处是否存在该组数据下的点 
struct State{
	int x;
	int y;
	int v;//方向 
	int ro;//路的性质 
};
queue<State>q;
inline int pos(int x,int y){
	return y+m*(x-1);
}
inline bool go(int x,int y){
	return x&&y&&x<=n&&y<=m;
}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch^48);
		ch=getchar();
	}
	x*=f;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	read(t);
	while(t--){
		read(n);read(m);read(Q);
		memset(poi,false,sizeof poi);
		int cnt_x=1,cnt_y=1;char ch=getchar();
		while(cnt_x<=n){
			while(!isdigit(ch))ch=getchar();
			while(isdigit(ch)){
				Y[pos(cnt_x,cnt_y)]=ch^48;
				++cnt_y;
				ch=getchar();
			}
			++cnt_x;
			cnt_y=1;
		}
		cnt_x=1;cnt_y=1;
		while(cnt_x<n){
			while(!isdigit(ch))ch=getchar();
			while(isdigit(ch)){
				X[pos(cnt_x,cnt_y)]=ch^48;
				++cnt_y;
				ch=getchar();
			}
			++cnt_x;
			cnt_y=1;
		}
		while(Q--){
			map<pair<int,int>,int>ma;
			int x,y,tp;
			read(colo);read(lev);read(x);read(y);
			con[++ans]=pos(x,y);
			r[pos(x,y)]=true;
//			cout<<x<<' '<<y<<' '; 
			tp=pos(x,y);
//			cout<<endl;
			poi[tp]=true;
			col[tp]=colo;
			lv[tp]=lev;
			State S;
			for(int vec=0;vec<4;++vec){
				int mx=x+nx[vec],my=y+ny[vec],_tp=pos(mx,my);
				if(!go(mx,my))continue;//越界 
//				cout<<' '<<mx<<' '<<my<<endl;
				S.v=vec;//第一步的方向是确定的 
				if(!vec)S.ro=Y[tp];
				else if(vec==1)S.ro=X[tp];
				else if(vec==2)S.ro=Y[_tp];
				else S.ro=X[_tp];
//				cout<<' '<<S.ro<<endl;
				if(!S.ro)continue;//此路不通 
				if(poi[_tp]){//开  幕  雷  击 
					if(col[_tp]!=colo&&lv[_tp]<lev){
						r[_tp]=true;
						++ans;
						con[ans]=_tp;
					}
					continue;//这个方向不能再走了 
				}
				S.x=mx;S.y=my;
				if(!ma[make_pair(mx,my)]){
					r[_tp]=true;
					++ans;
					con[ans]=_tp;
				}
				if(S.ro!=1)q.push(S);//初始状态确定 
//				cout<<' '<<mx<<' '<<my<<' '<<S.v<<endl;
				while(!q.empty()){
					S=q.front();q.pop();
//					cout<<S.x<<' '<<S.y<<' '<<S.v<<' '<<S.ro<<endl;
					for(int i=0;i<4;++i){
						if(S.ro!=3&&i!=S.v)continue;//不该换方向 
						State _S;
						_S.x=S.x+nx[i],_S.y=S.y+ny[i],tp=pos(S.x,S.y),_tp=pos(_S.x,_S.y);
						if(!go(_S.x,_S.y)||r[_tp])continue;//越界或已走过 
						_S.v=i;//方向传递 
						if(!i)_S.ro=Y[tp];
						else if(i==1)_S.ro=X[tp];
						else if(i==2)_S.ro=Y[_tp];
						else _S.ro=X[_tp];
						if(_S.ro!=S.ro)continue;//保持性质一致 
//						cout<<' '<<_S.x<<' '<<_S.y<<endl;
						if(poi[_tp]){//此处有子 
							if(col[_tp]!=colo&&lv[_tp]<lev){
								r[_tp]=true;
								++ans;
								con[ans]=_tp;
							}
							continue;
						}
						r[_tp]=true;
						++ans;
						con[ans]=_tp;
						ma[make_pair(_S.x,_S.y)]=true;
						q.push(_S);
					}
				}
			}
			printf("%d\n",ans-1);
			while(ans){
//				cout<<con[ans]<<endl;
				r[con[ans]]=false;
				--ans;
			}//没有真的走子 
		}
	}
//	cout<<X[pos(1,3)]<<endl;
	return 0;
}
//never gonna get you down
