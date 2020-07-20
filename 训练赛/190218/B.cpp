#include <stdio.h>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <iostream>
#include <algorithm>
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

const int sz_n=2e5+9;
const int sz_m=sz_n*6;
struct P{
	ll x,y,id;
	P(ll x=0,ll y=0):x(x),y(y),id(0){}
	void read(){scanf("%I64d%I64d",&x,&y);}
};
bool cmp1(P &a,P &b){
	return a.x+a.y<b.x+b.y;
}
bool cmp2(P &a,P &b){
	return a.x-a.y<b.x-b.y;
}
P p[sz_n],tmp[sz_n];

struct edge{
	int f,t;
	ll d;
	int nxt;
} l[sz_m];
bool cmp3(edge &a,edge &b){
	return a.d>b.d;
}
int head[sz_n],tot;
int n,m;
void init(int n){
	rep(i,0,n+1) head[i]=-1;
	tot=0;
}
void insert(int f,int t,ll d){
	l[tot]={f,t,d,head[f]};
	head[f]=tot++;
}
ll man(int a,int b){
	return abs(p[a].x-p[b].x)+abs(p[a].y-p[b].y);
}
int par[sz_n];
int find(int x){
	if(x==par[x]) return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	par[x]=y;
}
ll kruskal(){
	rep(i,0,n+5) par[i]=i;
	sort(l,l+tot,cmp3);
	int cnt=0;
	rep(i,0,tot){
		int f=l[i].f,t=l[i].t;
		if(find(f)!=find(t)){
			cnt++;
			unite(f,t);
			if(cnt==n-1) return l[i].d;
		}
	}
	return -1;
}
ll solve(){
	// LOG(1);
	sort(tmp+1,tmp+n+1,cmp1);
	insert(tmp[1].id,tmp[n].id,man(tmp[1].id,tmp[n].id));
	rep(i,2,n){
		insert(tmp[i].id,tmp[1].id,man(tmp[i].id,tmp[1].id));
		insert(tmp[i].id,tmp[n].id,man(tmp[i].id,tmp[n].id));
	}
	// LOG(2);
	sort(tmp+1,tmp+n+1,cmp2);
	insert(tmp[1].id,tmp[n].id,man(tmp[1].id,tmp[n].id));
	rep(i,2,n){
		insert(tmp[i].id,tmp[1].id,man(tmp[i].id,tmp[1].id));
		insert(tmp[i].id,tmp[n].id,man(tmp[i].id,tmp[n].id));
	}
	// LOG(3);
	return kruskal();
}
int main(){
	scanf("%d",&n);
	rep(i,1,n+1){
		p[i].read();
		tmp[i]=p[i];
		tmp[i].id=p[i].id=i;
	}
	// if(n==2){
	// 	printf("%d\n", man(0,1));
	// 	return 0;
	// }
	init(n+5);
	int ans=solve();
	// cout<<ans<<endl;
	printf("%I64d\n",ans);
	return 0;
}
