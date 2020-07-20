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
int v[sz];//点权，修改点权时需要把这个点splay到根节点再修改，否则会影响正确性
int maxx[sz];//子树维护的信息:异或和
int add[sz];

struct LCT{
	#define ls c[x][0]
	#define rs c[x][1]
	int f[sz],c[sz][2];
	bool rev[sz];//反转标记
	void init(int n){
		rep(i,0,n+1) f[i]=c[i][0]=c[i][1]=rev[i]=0;
	}
	bool son(int x){return c[f[x]][1]==x;}//0左儿子，1右儿子
	bool nroot(int x){return c[f[x]][0]==x||c[f[x]][1]==x;}//判断节点是否为一个Splay的根
	void reverse(int x){swap(ls,rs);rev[x]^=1;}//翻转操作
	inline void pushup(int x){//上传信息
	//	maxx[x]=v[x];
	//	if(ls) maxx[x]=max(maxx[x],maxx[ls]);
	//	if(rs) maxx[x]=max(maxx[x],maxx[rs]);
		// sum[x]=sum[ls]^sum[rs]^v[x];
	}
	inline void pushdown(int x){//判断并释放懒标记
		if(rev[x]){if(ls)reverse(ls);if(rs)reverse(rs);rev[x]=0;}
	/*	if(add[x]){
			if(ls)v[ls]+=add[x],maxx[ls]+=add[x],add[ls]+=add[x];
			if(rs)v[rs]+=add[x],maxx[rs]+=add[x],add[rs]+=add[x];
			add[x]=0;
		}*/
	}
	void rotate(int x){//一次旋转
		int y=f[x],z=f[y],k=son(x),w=c[x][!k];
		if(nroot(y)) c[z][son(y)]=x; //注意if(nroot(y))语句，此处不判断会引起致命错误
		c[x][!k]=y;c[y][k]=w; if(w)f[w]=y;
		f[y]=x;f[x]=z;pushup(y);
	}
	void splay(int x){//只传了一个参数，因为所有操作的目标都是该Splay的根（与普通Splay的区别3）
		static int st[sz];
		int y=x,z=0;
		st[++z]=y;//st为栈，暂存当前点到根的整条路径，pushdown时一定要从上往下放标记（与普通Splay的区别4）
		while(nroot(y)) st[++z]=y=f[y];
		while(z) pushdown(st[z--]);
		while(nroot(x)){
			y=f[x];z=f[y];
			if(nroot(y)) rotate((c[y][0]==x)^(c[z][0]==y)?x:y);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x){for(int y=0;x;x=f[y=x]) splay(x),rs=y,pushup(x);}//访问
	void makeroot(int x){access(x);splay(x);reverse(x);}//换根
	int findroot(int x){access(x);splay(x);while(ls)pushdown(x),x=ls;splay(x);return x;}//找根（在真实的树中的）
	int get_fa(int x){access(x),splay(x);if(!ls)return -1;pushdown(x);x=ls;while(rs)pushdown(x),x=rs;splay(x);return x;}
	void split(int x,int y){makeroot(x);access(y);splay(y);}//提取路径，得到一棵独立的[x,y]路径的splay，splay根节点为y
	void link(int x,int y){makeroot(x);if(findroot(y)!=x)f[x]=y;}//连边
	void cut(int x,int y){makeroot(x);if(findroot(y)==x&&f[y]==x&&!c[y][0]){f[y]=c[x][1]=0;pushup(x);}}//断边
}lct;
char ins[11];
struct node
{
	int l,r;
}war[sz];
int cnt = 0;
int n;
inline int read()
{
	int x = 0;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x;
}
int main()
{
	int n = read(),m = read();
	for(int i = 1 ; i < n ; i ++)
	{
		int p = read(),q = read();
		lct.link(p,q);
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		int ff,tt;
		scanf("%s",ins);
		if(ins[0] == 'Q')
		{
			ff = read(),tt = read();
			if(lct.findroot(ff) == lct.findroot(tt))
				puts("Yes");
			else
				puts("No");
		}
		else if(ins[0] == 'C')
		{
			ff = read(),tt = read();
			lct.cut(ff,tt);
			war[++cnt].l = ff;
			war[cnt].r = tt;
		}
		else
		{
			int x = read();
			lct.link(war[x].l,war[x].r);
		}
	} 
	return 0;
}
