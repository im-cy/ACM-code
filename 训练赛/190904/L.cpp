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
#define SZ(a) ((int)(a.size()))
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
#ifdef LOCAL1231
template<class T>void print_array(T *a,T *end){printf("#[");for(;a<end;++a)cout<<(*a)<<',';cout<<"\b]\n";};
template<class T>ostream &operator<<(ostream&os,vector<T>V){os<<"[";for(auto vv:V)os<<vv<<",";return os<<"\b]";}
void dbg(){cout<<"\b \n";}
template<typename T,typename...A>void dbg(T a,A...x){cout<<(a)<<',';dbg(x...);}
#define LOG(x...) {cout<<'#';dbg(x);}
#else
#define print_array(...)
#define LOG(...)
#endif
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double PI=acos(-1.0);
const double EPS=1e-8;
const int INF=1e9;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}
const int sz=1e6+9;

struct Edge{
    int t;
	ll d;
}l[sz];
vector<Edge> g[sz];
int hed[sz],nxt[sz];
int tot = 0; 
void insert(int f,int t,ll d){
	// LOG("insert",f,t,d);
    g[f].push_back({t,d});
    l[tot].t = t;
    l[tot].d = d;
    nxt[tot] = hed[f];
    hed[f] = tot ++;
}
int n;
int order[sz],in[sz],out[sz],dfs_clk;
void init(int n){
    rep(i,0,n+1) hed[i] = -1;
    dfs_clk=0;
    tot = 0;
}
void dfs(int u,int fa){
    order[++dfs_clk]=u;in[u]=dfs_clk;
    for(int i = hed[u] ; i != -1 ; i = nxt[i])
	{
		int t = l[i].t;
        if(t==fa) continue;
        dfs(t,u);
    }
    out[u]=dfs_clk;
}
struct Node{
    int u,k;
};vector<Node> A,B;


deque<int> q;
ll dis[sz];bool use[sz];
int tim[sz];
bool spfa(int s){
	while(!q.empty()) q.pop_front();
    dis[s]=0;
    q.push_back(s);
    use[s]=true;
    while(!q.empty()){
        int v=q.front();q.pop_front();
        use[v]=false;
        for(int i = hed[v] ; i != -1 ; i = nxt[i]){
            int t=l[i].t;
            int d = l[i].d;
            if(dis[t]>dis[v]+d){
                tim[t]=tim[v]+1;
                if(tim[t]>n+5) return false;
                dis[t]=dis[v]+d;
                if(!use[t]){
                	if(!q.empty())
                	{
                		if(dis[t] < dis[q.front()])
                			q.push_front(t);
                		else
                			q.push_back(t);
                	}
                	else
                		q.push_back(t);
                    use[t]=true;
                }
            }
        }
    }
    return true;
}

bool check(ll sum){
    // LOG("check",sum);
	if(sum>n) return false;
    rep(i,0,n+5) dis[i]=INF,tim[i]=0,use[i]=false;
    init(n+5);
    for(Node &nod:A){
        int u=nod.u;
        insert(out[u],in[u]-1,-nod.k);
    }
    for(Node &nod:B){
        int u=nod.u;
        if(sum-nod.k<0) return false;
        insert(in[u]-1,out[u],sum-nod.k);
    }
    rep(i,1,n+1){
        insert(i-1,i,1);
    }
    rep(i,1,n+1){
        insert(i,i-1,0);
    }
    int S=n+2;
    rep(i,0,n+1) insert(S,i,0);
    bool ok=spfa(S);
    // LOG("ok",ok);
    print_array(dis,dis+1+n);
    return ok;
}
ll solve(){
    ll l=-1,r=n;//r:satisfy
    while(r-l>1){
        ll mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    if(!check(r)) return -1;
    return r;
}


int main(){
    int _=readll();
    while(_--){
        n=readll();
        init(n+5);
        rep(i,1,n){
            int f=readll(),t=readll();
            insert(f,t,0);insert(t,f,0);
        }
        A.clear();B.clear();
        int na=readll();
        while(na--){
            int u=readll(),k=readll();
            A.push_back({u,k});
        }
        int nb=readll();
        while(nb--){
            int u=readll(),k=readll();
            B.push_back({u,k});
        }
        dfs(1,0);
        print_array(order+1,order+1+n);
        ll ans=solve();
        printf("%lld\n",ans);

    }
	return 0;
}
