/*
����������T3�򵥣�
���ǿ����·ŵ���ö���ӡ�
����4����·��
�����ͨ�����߸�*
�����ͨ���ͰѸõ����ϡ�
���ֱ�У�������һ��/���Ǳ߻�����Щ��
�����ͨ������һ����ͨ�顣

Ŷԭ����̫�򵥣���Ϊ��4�ֵ�·�����ص���
���ǿ�����ֻ�л�ͨ��������ͨ��ֱ���ص���
��ͨ����ͨ����ͨ��ֱ�У�ֱ����ֱ�ж��ǲ������ص��ġ�
�����Գ��ӹ�������
������ɫֻ�����֡�
ֻ�����һ�����ܳ��ӣ���ô���ǰ�����������ͨ����ά�����������ͨ���Ƿ����ߵ����棬����ܾ�������ά����

���Ǽ���ʱ�Ȳ����ǳ��ӣ�������㡣
Ȼ�����ǲ鵽ѯ�����м�����ͨ����ߣ�Ȼ������������е���ͨ��ֱ�в����ӵ�·�������
Ȼ�������ͨ��ֱ�в����ӵ�·����
�ͰѲ����ӵ������ˡ�
Ȼ��������ӡ�
�ȿ���ͨ������Щ����Щ�ܳԡ�
��
��ͨ���������ظ��Ŀ��Ա��Ե��ӡ�
�����߶����ϲ��ͺ��˰�������
������Ҫ����Щ��ͨ��ϳ�һ���ġ�
Ȼ�����Ǽ�����ͨ��ֱ�гԵ��ӡ�
����֮���ټ�����ͨ��ֱ�гԵ��ӡ�
�����ˣ� 

������ôά����Ŷ��

��¼ÿ����ͨ����ж��ٸ���xΪi���ж��ٵ�yΪi���ж���col=1��lv=i���ӿɴ�ж���col=0,lv=i���ӿɴinsidΪi�����Ƿ�ɴ
����ǿ���ά���ˡ�
������ĺ÷��� 
�����顭�� 
�����ԣ�����ά���Ĳ����������ж��ٸ���ɴ�����ȣ����ж��ٸ���ɴ�����ȣ����ж���col=1��lv=i���ӿɴ�ж���col=0,lv=i���ӿɴinsidΪi�����Ƿ�ɴ

1
3 3 5
13
22
23
010
233
0 1 2 3
1 2 2 1
1 3 1 2
0 2 3 2
1 3 2 2

1
3 3 1
13
22
23
010
233
0 1 2 3

ȫ��Ц�����ˡ�
����һ��Сʱ�����Ǵ��T3����Ȼ���������ˡ� 


�Ұ����ˣ������� 
*/
#include<cstdio>
#include<cstring>
int t,n,m,q,heng[200010],shu[200010],final[200010],opx[100010],opy[100010],opc[100010],opv[100010];
int id(int x,int y)
{
	return (x-1)*m+y;
}
void clearing()
{
	memset(final,0,sizeof final);
}
int ans;
int tim,mit;
int used[200010];
void dfs(int x,int y,int c,int v)
{
	if(used[id(x,y)]==mit)	return;
	used[id(x,y)]=mit;
	if(final[id(x,y)])
	{
		if(opc[final[id(x,y)]]!=c&&opv[final[id(x,y)]]<=v)	++ans;
		return;
	}
	++ans;
	if(x>1&&shu[id(x-1,y)]==3)	dfs(x-1,y,c,v);
	if(x<n&&shu[id(x,y)]==3)	dfs(x+1,y,c,v);
	if(y>1&&heng[id(x,y-1)]==3)	dfs(x,y-1,c,v);
	if(y<m&&heng[id(x,y)]==3)	dfs(x,y+1,c,v);
}
void solve()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<m;++j)	scanf("%1d",&heng[id(i,j)]);
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=m;++j)	scanf("%1d",&shu[id(i,j)]);
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d %d %d",&opc[i],&opv[i],&opx[i],&opy[i]);
		ans=0;
		++mit;
		dfs(opx[i],opy[i],opc[i],opv[i]);
		final[id(opx[i],opy[i])]=i;
		printf("%d\n",ans-1);//���ð��ã�����ˡ� 
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d",&t);
	for(tim=1;tim<=t;++tim)
	{
		clearing();
		solve();
	}
	return 0;
}
/*
#include<cstdio>
int t,n,m,q,heng[200010],shu[200010],final[200010],op[100010],opx[100010],opy[100010],opc[100010],opv[100010],sta[100010],top;
int f[200010],siz[200010];
int findfa(int x)
{
	return f[x]==x?f[x]:f[x]=findfa(f[x]);
}
void merge(int x,int y)
{
	int fx=findfa(x),fy=findfa(y);
	if(fx^fy)
	{
		f[fx]=fy;
		siz[fy]+=siz[fx];
	}
}
int id(int x,int y)
{
	return (x-1)*m+y;
}
int di(int x,int y)
{
	return (y-1)*n+x;
}
int used[100010];
struct node
{
	int l,r,num;
}nodes[28000010];
int tot,rootx[200010],rooty[200010],root1lv[200010],root0lv[200010],rootac[200010];
void ins(int l,int r,int &x,int pos,int val)
{
	if(!x)	x=++tot;
	nodes[x].num+=val;
	if(l^r)
	{
		int mid=(l+r)>>1;
		if(pos<=mid)	ins(l,mid,nodes[x].l,pos,val);
		else	ins(mid+1,r,nodes[x].r,pos,val);
	}
}
int merge(int l,int r,int x,int y)
{
	if(!x||!y)	return x|y;
	if(l^r)
	{
		int mid=(l+r)>>1;
		nodes[x].num+=nodes[y].num;
		nodes[x].l=merge(l,mid,nodes[x].l,nodes[y].l);
		nodes[x].r=merge(mid+1,r,nodes[x].r,nodes[y].r);
		return x;
	}
	else
	{
		nodes[x].num+=nodes[y].num;
		return x;
	}
}
int find(int l,int r,int x,int fr,int ba)
{
	if(l>ba||r<fr||!x)	return 0;
	if(l>=fr&&r<=ba)	return nodes[x].num;
	else
	{
		int mid=(l+r)>>1;
		return find(l,mid,x<<1,fr,ba)+find(mid+1,r,x<<1|1,fr,ba);
	}
}
int tim,mit,sued[100010];
void dfs(int x,int y,int bel)
{
	if(final[id(x,y)]&&sued[final[id(x,y)]]!=mit)
	{
		sued[final[id(x,y)]]=mit;
		if(opc[final[id(x,y)]]==1)	ins(1,q,root1lv[bel],opv[final[id(x,y)]],1);
		else	ins(1,q,root0lv[bel],opv[final[id(x,y)]],1);
		ins(1,q,rootac[bel],final[id(x,y)],1);
		return;
	}
	if(used[id(x,y)]==tim)	return;
	used[id(x,y)]=tim;
	ins(1,n*m,rootx[bel],id(x,y),1);
	ins(1,n*m,rooty[bel],di(x,y),1);
	if(y>1&&heng[id(x,y-1)]==3)	dfs(x,y-1,bel);
	if(y<m&&heng[id(x,y)]==3)	dfs(x,y+1,bel);
	if(x>1&&shu[id(x-1,y)]==3)	dfs(x-1,y,bel);
	if(x<n&&shu[id(x,y)]==3)	dfs(x+1,y,bel);
}
#define lowbit(x) ((x)&(-(x)))
int exnodes[200010][2];//0�������ȣ�1�������� 
void exins(int x,int val,int idd)
{
//	printf("      %d %d %d\n",x,val,idd);
	while(x<=n*m)
	{
		exnodes[x][idd]+=val;
		x+=lowbit(x);
	}
}
int exfin(int x,int idd)
{
	int res=0;
	while(x)
	{
		res+=exnodes[x][idd];
		x-=lowbit(x);
	}
	return res;
}
int exfind(int l,int r,int idd)
{
	return exfin(r,idd)-exfin(l-1,idd);
}
void clearing()
{
	
}
void init()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<m;++j)	scanf("%1d",&heng[id(i,j)]);
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=m;++j)	scanf("%1d",&shu[id(i,j)]);
	}
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d %d %d",&opc[i],&opv[i],&opx[i],&opy[i]);
		final[id(opx[i],opy[i])]=i;
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			f[id(i,j)]=id(i,j);
			siz[id(i,j)]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<m;++j)
		{
			if(!final[id(i,j)]&&!final[id(i,j+1)]&&heng[id(i,j)]==3)	merge(id(i,j),id(i,j+1));
		}
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(!final[id(i,j)]&&!final[id(i+1,j)]&&shu[id(i,j)]==3)	merge(id(i,j),id(i+1,j));
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(!final[id(i,j)]&&used[id(i,j)]!=tim)
			{
				++mit;
				dfs(i,j,findfa(id(i,j)));
			}
			else if(final[id(i,j)])
			{
				exins(id(i,j),1,0);
				exins(di(i,j),1,1);
			}
		}
	}
}
struct op
{
	int ty;//0:normal,1:straight,2:free.
	int num;//0:way,1:way,2:id
	int exnum;
}lis[10];
int listot;
const int wax[4]={0,0,-1,1},way[4]={-1,1,0,0};
void solve(int x)
{
	listot=0;
	int px=opx[x],py=opy[x],pc=opc[x],pv=opv[x];
//	printf("  %d %d\n",px,py);
	if(py>1)
	{
		if(heng[id(px,py-1)]==1)
		{
			lis[++listot].num=0;
			lis[listot].ty=0;
		}
		else if(heng[id(px,py-1)]==2)
		{
			lis[++listot].num=0;
			lis[listot].ty=1;
		}
		else if(heng[id(px,py-1)]==3) 
		{
			if(!final[id(px,py-1)])
			{
				int bl=findfa(id(px,py-1));
				lis[++listot].num=bl;
				lis[listot].ty=2;
				for(int i=1;i<listot;++i)
				{
					if(lis[i].ty==2&&lis[i].num==bl)
					{
						--listot;
						break;
					}
				}
			}
			else
			{
				lis[++listot].num=0;
				lis[listot].ty=0;
			}
		}
	}
	if(py<m)
	{
		if(heng[id(px,py)]==1)
		{
			lis[++listot].num=1;
			lis[listot].ty=0;
		}
		else if(heng[id(px,py)]==2)
		{
			lis[++listot].num=1;
			lis[listot].ty=1;
		}
		else if(heng[id(px,py)]==3) 
		{
			if(!final[id(px,py+1)])
			{
				int bl=findfa(id(px,py+1));
				lis[++listot].num=bl;
				lis[listot].ty=2;
				for(int i=1;i<listot;++i)
				{
					if(lis[i].ty==2&&lis[i].num==bl)
					{
						--listot;
						break;
					}
				}
			}
			else
			{
				lis[++listot].num=1;
				lis[listot].ty=0;
			}
		}
	}
	if(px>1)
	{
		if(shu[id(px-1,py)]==1)
		{
			lis[++listot].num=2;
			lis[listot].ty=0;
		}
		else if(shu[id(px-1,py)]==2)
		{
			lis[++listot].num=2;
			lis[listot].ty=1;
		}
		else if(shu[id(px-1,py)]==3) 
		{
			if(!final[id(px-1,py)])
			{
				int bl=findfa(id(px-1,py));
				lis[++listot].num=bl;
				lis[listot].ty=2;
				for(int i=1;i<listot;++i)
				{
					if(lis[i].ty==2&&lis[i].num==bl)
					{
						--listot;
						break;
					}
				}
			}
			else
			{
				lis[++listot].num=2;
				lis[listot].ty=0;
			}
		}
	}
	if(px<n)
	{
		if(shu[id(px,py)]==1)
		{
			lis[++listot].num=3;
			lis[listot].ty=0;
		}
		else if(shu[id(px,py)]==2)
		{
			lis[++listot].num=3;
			lis[listot].ty=1;
		}
		else if(shu[id(px,py)]==3) 
		{
			if(!final[id(px+1,py)])
			{
				int bl=findfa(id(px+1,py));
				lis[++listot].num=bl;
				lis[listot].ty=2;
				for(int i=1;i<listot;++i)
				{
					if(lis[i].ty==2&&lis[i].num==bl)
					{
						--listot;
						break;
					}
				}
			}
			else
			{
				lis[++listot].num=3;
				lis[listot].ty=0;
			}
		}
	}
	//���ԣ���Ҫ��ÿ��ֱ�ߵ���һ�µ�������ô���أ�
	//���Ƕ��֣���Ҳ���ǲ��У����鷳���� 
	for(int i=1;i<=listot;++i)
	{
		if(lis[i].ty==1)
		{
			int l=0,r=0;
			if(lis[i].num==0)	r=py;
			else if(lis[i].num==1)	r=m-py+1;
			else if(lis[i].num==2)	r=px;
			else	r=n-px+1;
			while(l+1<r)
			{
				int mid=(l+r)>>1;
				if(lis[i].num==0)
				{
					if(exfind(id(px,py-mid),id(px,py-1),0))	r=mid;
					else	l=mid;
				}
				else if(lis[i].num==1)
				{
					if(exfind(id(px,py+1),id(px,py+mid),0))	r=mid;
					else	l=mid;
				}
				else if(lis[i].num==2)
				{
					if(exfind(di(px-mid,py),di(px-1,py),1))	r=mid;
					else	l=mid;
				}
				else if(lis[i].num==3)
				{
					if(exfind(di(px+1,py),di(px+mid,py),1))	r=mid;
					else	l=mid;
				}
			}
			lis[i].exnum=l;
//			printf("   %d %d\n",lis[i].num,l);
		}
	}
	int res=0;
	for(int i=1;i<=listot;++i)
	{
		if(lis[i].ty==0)
		{
			if(lis[i].num==0)
			{
				if(!final[id(px,py-1)])	++res;
			}
			else if(lis[i].num==1)
			{
				if(!final[id(px,py+1)])	++res;
			}
			else if(lis[i].num==2)
			{
				if(!final[id(px-1,py)])	++res;
			}
			else
			{
				if(!final[id(px+1,py)])	++res;
			}
		}
		else if(lis[i].ty==1)	res+=lis[i].exnum;
		else
		{
			int bl=lis[i].num;
			res+=siz[bl];
			for(int j=1;j<=listot;++j)
			{
				if(lis[j].ty==0)
				{
					if(lis[i].num==0)
					{
						if(!final[id(px,py-1)])	res-=find(1,n*m,rootx[bl],id(px,py-1),id(px,py-1));
					}
					else if(lis[i].num==1)
					{
						if(!final[id(px,py+1)])	res-=find(1,n*m,rootx[bl],id(px,py+1),id(px,py+1));
					}
					else if(lis[i].num==2)
					{
						if(!final[id(px-1,py)])	res-=find(1,n*m,rootx[bl],id(px-1,py),id(px-1,py));
					}
					else
					{
						if(!final[id(px+1,py)])	res-=find(1,n*m,rootx[bl],id(px+1,py),id(px+1,py));
					}
				}
				else if(lis[j].ty==1)
				{
					if(lis[i].num==0)	res-=find(1,n*m,rootx[bl],id(px,py-lis[j].exnum),id(px,py-1));
					else if(lis[i].num==1)	res-=find(1,n*m,rootx[bl],id(px,py+1),id(px,py+lis[j].exnum));
					else if(lis[i].num==2)	res-=find(1,n*m,rooty[bl],id(px-lis[j].exnum,py),id(px-1,py));
					else	res-=find(1,n*m,rooty[bl],di(px+1,py),di(px+lis[j].exnum,py));
				}
			}
		}
		printf(" %d %d %d %d %d %d\n",lis[i].ty,lis[i].num,lis[i].exnum,res,id(px,py-lis[i].exnum),id(px,py-1));
	}
	printf("%d\n",res);
	//���ӣ�Ҫ��д����Ϊ��ȥ��T3ȥ�ˡ� 
	int las=0;
	for(int i=1;i<=listot;++i)
	{
		if(lis[i].ty==3)
		{
			if(pc==1)	ins(1,q,root1lv[lis[i].num],pv,-1);
			else	ins(1,q,root0lv[lis[i].num],pv,-1);
			ins(1,q,rootac[lis[i].num],x,-1);
			if(!las)	las=lis[i].num;
			else
			{
				f[lis[i].num]=las;
				siz[las]+=siz[lis[i].num];
				rootx[las]=merge(1,n*m,rootx[las],rootx[lis[i].num]);
				rooty[las]=merge(1,n*m,rooty[las],rooty[lis[i].num]);
				root1lv[las]=merge(1,q,root1lv[las],root1lv[lis[i].num]);
				root0lv[las]=merge(1,q,root0lv[las],root0lv[lis[i].num]);
				rootac[las]=merge(1,q,rootac[las],rootac[lis[i].num]);
			}
		}
	}
	if(las)
	{
		if(pc==1)	res+=find(1,q,root0lv[las],1,pv);
		else	res+=find(1,q,root1lv[las],1,pv);
	}
	for(int i=1;i<=listot;++i)
	{
		int thix=-1,thiy=-1;
		if(lis[i].ty==0)
		{
			if(lis[i].num==0)
			{
				if(final[id(px,py-1)]&&opc[final[id(px,py-1)]]!=pc&&opv[final[id(px,py-1)]]<=pv)
				{
					thix=px;
					thiy=py-1;
				}
			}
			else if(lis[i].num==1)
			{
				if(final[id(px,py+1)]&&opc[final[id(px,py+1)]]!=pc&&opv[final[id(px,py+1)]]<=pv)
				{
					thix=px;
					thiy=py+1;
				}
			}
			else if(lis[i].num==2)
			{
				if(final[id(px-1,py)]&&opc[final[id(px-1,py)]]!=pc&&opv[final[id(px-1,py)]]<=pv)
				{
					thix=px-1;
					thiy=py;
				}
			}
			else
			{
				if(final[id(px+1,py)]&&opc[final[id(px+1,py)]]!=pc&&opv[final[id(px+1,py)]]<=pv)
				{
					thix=px+1;
					thiy=py;
				}
			}
		}
		else if(lis[i].ty==1)
		{
			if(lis[i].num==0)
			{
				if(py>lis[i].exnum+1&&opc[final[id(px,py-lis[i].exnum-1)]]!=pc&&opv[final[id(px,py-lis[i].exnum-1)]]<=pv)
				{
					thix=px;
					thiy=py-lis[i].exnum-1;
				}
			}
			else if(lis[i].num==1)
			{
				if(py+lis[i].exnum+1<=m&&opc[final[id(px,py+lis[i].exnum+1)]]!=pc&&opv[final[id(px,py+lis[i].exnum+1)]]<=pv)
				{
					thix=px;
					thiy=py+lis[i].exnum+1;
				}
			}
			else if(lis[i].num==2)
			{
				if(px>lis[i].exnum+1&&opc[final[id(px-lis[i].exnum-1,py)]]!=pc&&opv[final[id(px-lis[i].exnum-1,py)]]<=pv)
				{
					thix=px-lis[i].exnum-1;
					thiy=py;
				}
			}
			else
			{
				if(px+lis[i].exnum+1<=n&&opc[final[id(px+lis[i].exnum+1,py)]]!=pc&&opv[final[id(px+lis[i].exnum+1,py)]]<=pv)
				{
					thix=px+lis[i].exnum+1;
					thiy=py;
				}
			}
		}
		if(thix<0)	continue;
		if(!las||!find(1,q,rootac[las],final[id(thix,thiy)],final[id(thix,thiy)]))	++res;
	}
	if(las)	merge(id(px,py),las);
	else	las=id(px,py);
	ins(1,n*m,rootx[las],id(px,py),1);
	ins(1,n*m,rooty[las],di(px,py),1);
	exins(id(px,py),-1,0);
	exins(di(px,py),-1,1);
	final[id(px,py)]=0;
	sta[++top]=res;
}
int main()
{
	scanf("%d",&t);
	for(tim=1;tim<=t;++tim)
	{
		clearing();
		init();
		for(int i=q;i>=1;--i)	solve(i); 
		while(top)	printf("%d\n",sta[top--]);
	}
	return 0;
}
*/
