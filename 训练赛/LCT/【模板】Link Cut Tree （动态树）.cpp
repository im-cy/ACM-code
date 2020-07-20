#include <stdio.h>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
//#include <unordered_map>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
#define LOG(a) cout<<'#'<<a<<endl
void print_array(int *a,int n){printf("#");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');}
typedef long long ll;
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int IINF=0x3f3f3f3f;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}

const int sz=300009;
int v[sz];//��Ȩ���޸ĵ�Ȩʱ��Ҫ�������splay�����ڵ����޸ģ������Ӱ����ȷ��
int maxx[sz];//����ά������Ϣ:����
int add[sz];

int xr[sz];
int n;
struct LCT{
	#define ls c[x][0]
	#define rs c[x][1]
	int f[sz],c[sz][2];
	int size[sz];
	bool rev[sz];//��ת���
	void init(int n){
		rep(i,0,n+1) f[i]=c[i][0]=c[i][1]=rev[i]=0,size[i] = 1;
	}
	bool son(int x){return c[f[x]][1]==x;}//0����ӣ�1�Ҷ���
	bool nroot(int x){return c[f[x]][0]==x||c[f[x]][1]==x;}//�жϽڵ��Ƿ�Ϊһ��Splay�ĸ�
	void reverse(int x){swap(ls,rs);rev[x]^=1;}//��ת����
	void pushup(int x){//�ϴ���Ϣ
		size[x] = 1;
		if(ls) size[x] += size[ls];
		if(rs) size[x] += size[rs];
		xr[x]=xr[ls]^xr[rs]^v[x];
	}
	void pushdown(int x){//�жϲ��ͷ������
		if(rev[x]){if(ls)reverse(ls);if(rs)reverse(rs);rev[x]=0;}
		if(add[x]){
			if(ls)v[ls]+=add[x],maxx[ls]+=add[x],add[ls]+=add[x];
			if(rs)v[rs]+=add[x],maxx[rs]+=add[x],add[rs]+=add[x];
			add[x]=0;
		}
	}
	void rotate(int x){//һ����ת
		int y=f[x],z=f[y],k=son(x),w=c[x][!k];
		if(nroot(y)) c[z][son(y)]=x; //ע��if(nroot(y))��䣬�˴����жϻ�������������
		c[x][!k]=y;c[y][k]=w; if(w)f[w]=y;
		f[y]=x;f[x]=z;pushup(y);
	}
	void splay(int x){//ֻ����һ����������Ϊ���в�����Ŀ�궼�Ǹ�Splay�ĸ�������ͨSplay������3��
		static int st[sz];
		int y=x,z=0;
		st[++z]=y;//stΪջ���ݴ浱ǰ�㵽��������·����pushdownʱһ��Ҫ�������·ű�ǣ�����ͨSplay������4��
		while(nroot(y)) st[++z]=y=f[y];
		while(z) pushdown(st[z--]);
		while(nroot(x)){
			y=f[x];z=f[y];
			if(nroot(y)) rotate((c[y][0]==x)^(c[z][0]==y)?x:y);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x){for(int y=0;x;x=f[y=x]) splay(x),rs=y,pushup(x);}//����
	void makeroot(int x){access(x);splay(x);reverse(x);}//����
	int findroot(int x){access(x);splay(x);while(ls)pushdown(x),x=ls;splay(x);return x;}//�Ҹ�������ʵ�����еģ�
	int get_fa(int x){access(x),splay(x);if(!ls)return -1;pushdown(x);x=ls;while(rs)pushdown(x),x=rs;splay(x);return x;}
	void split(int x,int y){makeroot(x);access(y);splay(y);}//��ȡ·�����õ�һ�ö�����[x,y]·����splay��splay���ڵ�Ϊy
	void link(int x,int y){makeroot(x);if(findroot(y)!=x)f[x]=y;}//����
	void cut(int x,int y){makeroot(x);if(findroot(y)==x&&f[y]==x&&!c[y][0]){f[y]=c[x][1]=0;pushup(x);}}//�ϱ�
}lct;
int query(int x,int y)
{
	lct.makeroot(x);
	lct.access(y);
	lct.splay(y);
	return lct.size[y] - 1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	lct.init(n);
	for(int i = 1 ; i <= n ; i ++)
	{
		lct.splay(i);
		scanf("%d",&v[i]);
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op == 0)
		{//ѯ��x��y������ 
			lct.split(x,y);
			printf("%d\n",xr[y]);
		}
		else if(op == 1)
		{//����x��y 
			if(lct.findroot(x) == lct.findroot(y))
				continue;
			lct.link(x,y);
		}
		else if(op == 2)
		{//ɾ����xy 
			if(lct.findroot(x) != lct.findroot(y))
				continue;
			lct.cut(x,y);
		}
		else
		{//��x��Ȩֵ���y 
			lct.splay(x);
			v[x] = y;
		}
	}
	return 0;
}
