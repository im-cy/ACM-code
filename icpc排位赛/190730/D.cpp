#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define mem(a,x) memset(a,x,sizeof(a))
#define LOG(a) cout<<'#'<<a<<endl
void print_array(int *a,int n){printf("#");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');}
typedef long long ll;
using namespace std;
typedef vector<int> vec;
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

const int sz=500;
struct edge{
	int f,t;
	long double d;
};
vector<edge> g[sz];
void init(int n){
	rep(i,0,n+1) g[i].clear();
}
void insert(int f,int t,long double d){
	g[f].push_back({f,t,d});
}

struct node{
	int p;
	long double d;
	bool operator<(const node &x)const {
		return d>x.d;
	}
};
int n,A,B,C,D;
long double dis[sz];
bool use[sz];
priority_queue<node> q;
long double dij(){
	fill(dis,dis+n+5,1e30);
	fill(use,use+n+5,0);
	while(q.size()) q.pop();
	dis[1]=0;
	q.push({1,0});
	while(q.size()){
		node f=q.top();q.pop();
		if(use[f.p]) continue;
		use[f.p]=true;
		for(edge &l:g[f.p]){
			int t=l.t;
			if(use[t]) continue;
			if(dis[t]>dis[f.p]+l.d){
				dis[t]=dis[f.p]+l.d;
				q.push({t,dis[t]});
			}
		}
	}
	return dis[n];
}
struct P{
	long double x,y;
}p[sz];
long double Pow(long double a,ll b){
	long double ans=1;
	while(b){
		if(b&1) ans=ans*a;
		b>>=1,a=a*a;
	}
	return ans;
}
long double getdis(int i,int j){
	ll dis=ceil(sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y)));
	long double F=A*(Pow(1.0+(1.0/(D-1.0)),dis)-1.0);
	long double ans=F * (long double)C + (long double)B;
	return ans;
}
long double solve(){
	init(n+5);
	rep(i,1,n+1){
		p[i].x=readll(),p[i].y=readll();
	}
	rep(i,1,n+1){
		rep(j,i+1,n+1){
			long double dis=getdis(i,j);
			insert(i,j,dis);
			insert(j,i,dis);
		}
	}
	long double ans= dij();
	return ans;
}
int main(){
	int _=readll(),casei=0;
	while(_--){
		n=readll(),A=readll(),B=readll(),C=readll(),D=readll();
		double ans=solve();
		printf("Case %d: %.15f\n",++casei,ans);
	}
	return 0;
}
