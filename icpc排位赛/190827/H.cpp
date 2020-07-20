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
// #include <unordered_map>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
template<class T>void print_array(T *a,T *end){printf("#[");for(;a<end;++a)cout<<(*a)<<',';cout<<"\b]\n";};
template<class T>ostream &operator<<(ostream&os,vector<T>V){os<<"[";for(auto vv:V)os<<vv<<",";return os<<"\b]";}
void dbg(){cout<<"\b \n";}
template<typename T,typename...A>void dbg(T a,A...x){cout<<(a)<<',';dbg(x...);}
#define LOG(x...) cout<<'#';dbg(x)
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double PI=acos(-1.0);
const double EPS=1e-8;
// const ll INF=0x3f3f3f3f3f3f3f3f;
const int IINF=1e9;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}
const int sz=2e6+9;


vector<pii> cars[200];
vector<pii> lanes[200];
vector<int> spaceid[200];int tot;
pii mycar;int mycarlane,mycarwide;

const int sz_n=1e7+9;
struct Edge{int t,d;};
vector<Edge> g[sz];
void insert(int f,int t,int d){
	// LOG("insert",f,t,d);
	g[f].push_back({t,d});
}
set<pii> sett;
int intersect(pii a,pii b){
	int l=max(a.first,b.first);
	int r=min(a.second,b.second);
	// LOG(l,r);
	return r-l;
}

struct Node{
	int p, d;
	bool operator<(const Node &x)const{
		return d<x.d;
	}
};
int dis[sz];
bool use[sz];
priority_queue<Node> q;
void dij(int s){
	fill(dis,dis+tot+5,0);
	fill(use,use+tot+5,0);
	while(q.size()) q.pop();
	dis[s]=IINF;
	q.push({s,IINF});
	while(q.size()){
		Node f=q.top();q.pop();
		if(use[f.p]) continue;
		use[f.p]=true;
		for(Edge &l:g[f.p]){
			int t=l.t;
			if(use[t]) continue;
			if(dis[t]<min(dis[f.p],l.d)){
				dis[t]=min(dis[f.p],l.d);
				q.push({t,min(dis[f.p],l.d)});
			}
		}
	}
}

int n,m,L;
void solve(){
	rep(i,0,n) sort(cars[i].begin(), cars[i].end());
	rep(i,0,n){
		rep(j,1,cars[i].size()){
			lanes[i].push_back({cars[i][j-1].second,cars[i][j].first});
			spaceid[i].push_back(++tot);
		}
	}
	rep(c,0,n-1){
		rep(i,0,lanes[c].size()){
			rep(j,0,lanes[c+1].size()){
				int wide=intersect(lanes[c][i],lanes[c+1][j]);
				if(wide>=0){
					insert(spaceid[c][i],spaceid[c+1][j],wide);
					insert(spaceid[c+1][j],spaceid[c][i],wide);
				}
			}
		}
	}
	tot++;
	for(int id:spaceid[n-1]){
		insert(id,tot,IINF);
	}
	int s=-1;
	rep(i,0,lanes[0].size()){
		if(intersect(mycar,lanes[0][i])>=0) s=i+1;
	}
	// LOG(s);
	dij(s);
	if(dis[tot]<mycarwide) puts("Impossible");
	else {
		// LOG(dis[tot]);
		printf("%.6f\n",(dis[tot]-mycarwide)/2.0);
	}
}

int main(){
	n=readll(),m=readll(),L=readll();
	mycarlane=readll();
	mycarwide=readll();
	mycar.first=readll();
	mycar.second=mycar.first+mycarwide;
	rep(i,0,n){
		cars[i].push_back({-1,0});
		cars[i].push_back({L,L+1});
	}
	rep(i,1,m){
		int lan=readll();
		pii pos;
		pos.second=readll();
		pos.first=readll(),pos.second=pos.first+pos.second;
		cars[lan].push_back(pos);
	}
	solve();
	return 0;
}
/*
4 6 100
0 10 30
0 10 10
1 10 5
1 20 35
2 2 18
2 40 50


4 4 100
0 1 10
0 60 40
1 20 30
3 10 60
4 70 0


*/
