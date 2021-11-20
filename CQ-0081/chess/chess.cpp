#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,q,Num,heng[N],shu[N],ans[N],pos[N],lv[N];
int p2h[N],p2s[N],p3[N],L[N],R[N],toth,tots,tot[2];
int rh[N],rs[N],r[2][N],U[N],D[N],nmh[N],nms[N],cnt;
char s[N];
vector<int>num[N];
pair<int,int>tmp[N];
struct node {
	int col,lv,x,y;
} a[N];
struct SG {
	int num,ls,rs;
} th[N*40],ts[N*40],t[2][N*40];
int read() {
	int s=0,f=0;
	char ch=getchar();
	while(ch<48||ch>57)f|=(ch=='-'),ch=getchar();
	while(ch>47&&ch<58)s=s*10+(ch^48),ch=getchar();
	return f?-s:s;
}
int G2h(int x) {
	return p2h[x]==x?x:p2h[x]=G2h(p2h[x]);
}
int G2s(int x) {
	return p2s[x]==x?x:p2s[x]=G2s(p2s[x]);
}
int G3(int x) {
	return p3[x]==x?x:p3[x]=G3(p3[x]);
}
void M2h(int a,int b) {
	int x=G2h(a),y=G2h(b);
	if(x==y)return;
	p2h[x]=y,L[y]=min(L[x],L[y]),R[y]=max(R[x],R[y]);
}
void M2s(int a,int b) {
	int x=G2s(a),y=G2s(b);
	if(x==y)return;
	p2s[x]=y,U[y]=min(U[x],U[y]),D[y]=max(D[x],D[y]);
}
void Add(SG*t,int&tot,int&rt,int l,int r,int x) {
	if(!rt)rt=++tot;
	if(l==r)return t[rt].num=1,void();
	int mid=(l+r)>>1;
	if(x<=mid)Add(t,tot,t[rt].ls,l,mid,x);
	else Add(t,tot,t[rt].rs,mid+1,r,x);
	t[rt].num=t[t[rt].ls].num+t[t[rt].rs].num;
}
void Erase(SG*t,int&rt,int l,int r,int x) {
	if(!rt||l==r)return rt=0,void();
	int mid=(l+r)>>1;
	if(x<=mid)Erase(t,t[rt].ls,l,mid,x);
	else Erase(t,t[rt].rs,mid+1,r,x);
	t[rt].num=t[t[rt].ls].num+t[t[rt].rs].num;
	if(!t[rt].num)rt=0;
}
int Merge(SG*t,int rl,int rr,int l,int r) {
	if((!rl)||(!rr))return rl|rr;
	if(l==r)return t[rl].num=1,rl;
	int mid=(l+r)>>1;
	t[rl].ls=Merge(t,t[rl].ls,t[rr].ls,l,mid);
	t[rl].rs=Merge(t,t[rl].rs,t[rr].rs,mid+1,r);
	t[rl].num=t[t[rl].ls].num+t[t[rl].rs].num;
	return rl;
}
int Ask(SG*t,int rt,int l,int r,int ql,int qr) {
	if(!rt)return 0;
	if(ql<=l&&r<=qr)return t[rt].num;
	int mid=(l+r)>>1;
	if(qr<=mid)return Ask(t,t[rt].ls,l,mid,ql,qr);
	if(ql>mid)return Ask(t,t[rt].rs,mid+1,r,ql,qr);
	return Ask(t,t[rt].ls,l,mid,ql,qr)+Ask(t,t[rt].rs,mid+1,r,ql,qr);
}
void M3(int a,int b) {
	int x=G3(a),y=G3(b);
	if(x==y)return;
	p3[x]=y;
	rh[y]=Merge(th,rh[x],rh[y],1,Num);
	rs[y]=Merge(ts,rs[x],rs[y],1,Num);
	r[0][y]=Merge(t[0],r[0][x],r[0][y],1,Num);
	r[1][y]=Merge(t[1],r[1][x],r[1][y],1,Num);
}
void Work(int a,int i,int j,int col) {
	Add(th,toth,rh[a],1,Num,nmh[a]);
	Add(ts,tots,rs[a],1,Num,nms[a]);
	int b;
	if((b=num[i-1][j])&&shu[b]==3&&p3[b]==0)
		Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
	if((b=num[i+1][j])&&shu[a]==3&&p3[b]==0)
		Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
	if((b=num[i][j-1])&&heng[b]==3&&p3[b]==0)
		Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
	if((b=num[i][j+1])&&heng[a]==3&&p3[b]==0)
		Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
	if((b=num[i-1][j])&&shu[b]==3&&p3[b])M3(a,b);
	if((b=num[i+1][j])&&shu[a]==3&&p3[b])M3(a,b);
	if((b=num[i][j-1])&&heng[b]==3&&p3[b])M3(a,b);
	if((b=num[i][j+1])&&heng[a]==3&&p3[b])M3(a,b);
	if((b=num[i-1][j])&&shu[b]==3&&p2s[b])M2s(a,b);
	if((b=num[i+1][j])&&shu[a]==3&&p2s[b])M2s(a,b);
	if((b=num[i][j-1])&&heng[b]==3&&p2h[b])M2h(a,b);
	if((b=num[i][j+1])&&heng[a]==3&&p2h[b])M2h(a,b);
	Erase(t[pos[a]],r[pos[a]][G3(a)],1,q,lv[a]);
}
void Check(int&ans,int a,int i,int j) {
	int x=G3(a),b;
	if((b=num[i-1][j])&&shu[b]==1&&p3[b])ans+=1-Ask(th,rh[x],1,Num,nmh[b],nmh[b]);
	if((b=num[i+1][j])&&shu[a]==1&&p3[b])ans+=1-Ask(th,rh[x],1,Num,nmh[b],nmh[b]);
	if((b=num[i][j-1])&&heng[b]==1&&p3[b])ans+=1-Ask(ts,rs[x],1,Num,nms[b],nms[b]);
	if((b=num[i][j+1])&&heng[a]==1&&p3[b])ans+=1-Ask(ts,rs[x],1,Num,nms[b],nms[b]);
	if((b=num[i-1][j])&&shu[b]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[b]);
	if((b=num[i+1][j])&&shu[b]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[b]);
	if((b=num[i][j-1])&&heng[b]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[a]);
	if((b=num[i][j+1])&&heng[a]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[a]);
	int ll=L[G2h(a)],rr=R[G2h(a)],uu=U[G2s(a)],dd=D[G2s(a)];
	ans-=Ask(th,rh[x],1,Num,nmh[num[i][ll]],nmh[num[i][rr]]);
	ans-=Ask(ts,rs[x],1,Num,nms[num[i][uu]],nms[num[i][dd]]);
	if((b=num[i-1][j])&&shu[b]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[b]);
	if((b=num[i+1][j])&&shu[b]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[b]);
	if((b=num[i][j-1])&&heng[b]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[a]);
	if((b=num[i][j+1])&&heng[a]==1&&!p3[b]&&pos[b]!=pos[a]&&lv[b]<=lv[a])
		ans+=1-Ask(t[pos[b]],r[pos[b]][G3(a)],1,q,lv[b],lv[a]);	
}
int main() {
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1; i<=n; ++i)num[i].resize(m+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)num[i][j]=++Num,nmh[Num]=(i-1)*m+j,nms[Num]=(j-1)*n+i;
	for(int i=1; i<=n; ++i) {
		scanf("%s",s+1);
		for(int j=1; j<m; ++j)heng[num[i][j]]=s[i]-'0';
	}
	for(int i=1; i<n; ++i) {
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j)shu[num[i][j]]=s[i]-'0';
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) {
			int k=num[i][j];
			p2h[k]=p2s[k]=p3[k]=k;
			L[k]=R[k]=j,U[k]=D[k]=i;
		}
	for(int i=1; i<=q; ++i) {
		a[i].col=read(),a[i].lv=read();
		a[i].x=read(),a[i].y=read();
		pos[num[a[i].x][a[i].y]]=a[i].col;
		tmp[i]=make_pair(a[i].lv,i);
		p2h[num[a[i].x][a[i].y]]=0;
		p2s[num[a[i].x][a[i].y]]=0;
		p3[num[a[i].x][a[i].y]]=0;
	}
	sort(tmp+1,tmp+q+1);
	for(int i=1; i<=q; ++i)lv[num[a[i].x][a[i].y]]=lower_bound(tmp+1,tmp+q+1,make_pair(a[i].lv,i))-tmp;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(p3[num[i][j]]) {
				int k=num[i][j];
				Add(th,toth,rh[k],1,Num,nmh[k]);
				Add(ts,tots,rs[k],1,Num,nms[k]);
			}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j) {
			int a=num[i][j],b=num[i][j+1];
			if(p2h[a]&&p2h[b]&&heng[a]==2)M2h(a,b);
			if(p3[a]&&p3[b]&&heng[a]==3)M3(a,b);
		}
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j) {
			int a=num[i][j],b=num[i+1][j];
			if(p2s[a]&&p2s[b]&&shu[a]==2)M2s(a,b);
			if(p3[a]&&p3[b]&&shu[a]==3)M3(a,b);
		}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)if(num[i][j]) {
				int a=num[i][j],b;
				if((b=num[i-1][j])&&shu[b]==3&&p3[b]==0)
					Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
				if((b=num[i+1][j])&&shu[a]==3&&p3[b]==0)
					Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
				if((b=num[i][j-1])&&heng[b]==3&&p3[b]==0)
					Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
				if((b=num[i][j+1])&&heng[a]==3&&p3[b]==0)
					Add(t[pos[b]],tot[pos[b]],r[pos[b]][G3(a)],1,q,lv[b]);
			}
	for(int i=q; i; --i) {
		int id=num[a[i].x][a[i].y];
		p2h[id]=p2s[id]=p3[id]=id;
		Work(id,a[i].x,a[i].y,a[i].col);
		ans[i]=th[rh[G3(id)]].num-1+t[pos[id]^1][r[pos[id]^1][G3(id)]].num
				+R[G2h(id)]-L[G2h(id)]+D[G2s(id)]-U[G2s(id)];
		Check(ans[i],id,a[i].x,a[i].y);
	}
	for(int i=1; i<=q; ++i)cout<<ans[i]<<"\n";
	return 0;
}
//Fighting£¡
