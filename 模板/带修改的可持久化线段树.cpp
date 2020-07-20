/*
可持久化线段树，主席树
PersistentSegTree

带修改
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<utility>
#include<sstream>
#include<iostream>
#include<algorithm>
#define lowbit(x) ((x)&(-x))
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
#define LOG(a) cout<<'#'<<a<<endl
void print_array(int *a,int n){printf("#");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');}
typedef long long ll;
using namespace std;
typedef vector < int > vec;
typedef vector < vec > mat;
typedef pair < int , int > pii;
const double EPS = 1e-8;
const ll INF = 0x3f3f3f3f3f3f3f3f;

const int sz = 6e4+9;

struct PSegTree
{
	int l,r;
	int sum;
}tree[sz*40];
int cnt;
int build(int l,int r)
{
	int p = ++cnt;
	tree[p].sum = 0;
	int mid = (l+r)/2;
	if(r - l > 1)
	{
		tree[p].l = build(l,mid);
		tree[p].r = build(mid,r);
	}
	return p;
}
int update(int last,int l,int r,int x,int val)
{
	int p = ++cnt;
	tree[p] = tree[last];
	tree[p].sum += val;
	int mid = (l + r) / 2;
	if(r - l > 1)
	{
		if(x < mid)
			tree[p].l = update(tree[p].l,l,mid,x,val);
		else
			tree[p].r = update(tree[p].r,mid,r,x,val);
	}
	return p;
}

int S[sz],T[sz];
int n,m;
int a[sz];
int dis[sz],disn;
int disc(int x)
{
	return lower_bound(dis+1,dis+1+disn,x) - dis;
}
void add(int s,int x,int val)
{//s及之后为x单点加val
	while(s <= disn)
	{
		S[s] = update(S[s],1,disn+1,x,val);
		s += lowbit(s);
	}
}
vec usel,user;
int query(int tl,int tr,int k)
{//左闭右开
	// int u=T[l-1],v=T[r-1];
	usel = {T[tl-1]};
	user = {T[tr-1]};
	// LOG(tl-1<<","<<tr-1);
	for(int i = tl-1 ; i ; i -= lowbit(i))
		usel.push_back(S[i]);
	for(int i = tr-1 ; i ; i -= lowbit(i))
		user.push_back(S[i]);
	// LOG("usesize"<<usel.size()<<','<<user.size());
	int l = 1 , r = disn + 1;
	while(r - l > 1)
	{
		int mid = (l + r) / 2;
		int x = 0;
		for(int i:usel)
			x -= tree[tree[i].l].sum;
		for(int i:user)
			x += tree[tree[i].l].sum;
		// LOG("x"<<x);
		if(k <= x)
		{
			r = mid;
			for(int &i:usel)
				i = tree[i].l;
			for(int &i:user)
				i = tree[i].l;
		}
		else
		{
			l = mid;
			k -= x;
			for(int &i:usel)
				i = tree[i].r;
			for(int &i:user)
				i = tree[i].r;
		}
	}
	return l;
}
struct {
	char cmd[4];
	int x,y,z;
}q[sz];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		cnt=0;//别忘了清零，否则RE
		scanf("%d%d",&n,&m);
		rep(i,1,n+1) scanf("%d",&a[i]),dis[i]=a[i];
		disn=n;
		rep(i,0,m){
			scanf("%s",q[i].cmd);
			if(*q[i].cmd=='Q'){
				scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].z);
			}else{
				scanf("%d%d",&q[i].x,&q[i].y);
				dis[++disn]=q[i].y;
			}
		}
		sort(dis+1,dis+1+disn);
		disn=unique(dis+1,dis+1+disn)-(dis+1);
		// LOG("disn"<<disn);
		rep(i,1,n+1) a[i]=disc(a[i]);
		rep(i,0,m) if(q[i].cmd[0]=='C') q[i].y=disc(q[i].y);
		T[0]=build(1,disn+1);
		rep(i,0,n+1) S[i]=T[0];
		rep(i,1,n+1){
			T[i]=update(T[i-1],1,disn+1,a[i],1);
		}
		rep(i,0,m){
			if(*q[i].cmd=='Q'){
				// LOG("q"<<q[i].x<<','<<q[i].y<<","<<q[i].z);
				int ans=query(q[i].x,q[i].y+1,q[i].z);
				// LOG(ans);
				printf("%d\n",dis[ans]);
			}else{
				add(q[i].x,a[q[i].x],-1);
				add(q[i].x,q[i].y,1);
				a[q[i].x]=q[i].y;
			}
		}
	}
	return 0;
}

