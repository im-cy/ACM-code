#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
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

const int sz=2e5+9;

struct P{
    long double x,y;
    void read(){x=readll(),y=readll();}
    P operator+(P p){return {x+p.x,y+p.y};}
    P operator-(P p){return {x-p.x,y-p.y};}
    P operator*(long double k){return {x*k,y*k};}
    P operator/(long double k){return {x/k,y/k};}
    long double dot(P p) {return x*p.x+y*p.y;}
    long double det(P p) {return x*p.y-y*p.x;}
};
int cmp(double x){
    if(abs(x)<0) return 0;
    if(x>0) return 1;
    else return -1;
}
int containOn(vector<P> &a,P b){
    int n=a.size();
    P g=(a[0]+a[n/3]+a[2*n/3])/3.0;
    int l=0,r=n;
    while(l+1<r){
        int mid=(l+r)/2;
        if(cmp((a[l]-g).det(a[mid]-g))>0){
            if(cmp((a[l]-g).det(b-g))>=0 && cmp( (a[mid]-g).det(b-g) )<0) r=mid;
            else l=mid;
        }else{
            if(cmp((a[l]-g).det(b-g))<0 && cmp( (a[mid]-g).det(b-g) )>=0) l=mid;
            else r=mid;
        }
    }
    r%=n;
    int z=cmp((a[r]-b).det(a[l]-b))-1;
    if(z==-2) return 1;
    else return z;
}

int n;
// vector<P> c[sz];

struct Convexhull{
    vector<P> c;
    long double areasum;
    friend bool operator<(const Convexhull &a,const Convexhull &b){
        return a.areasum<b.areasum;
    }
}c[sz];
long double areasum[sz];
long double area[sz];
int vis[sz];

long double calcarea(vector<P> &a){
    long double sum=0;
    int n=a.size();
    rep(i,0,n){
        sum+=(a[(i+1)%n].det(a[i]));
    }
    return abs(sum)/2;
}

bool onseg(P p,P a,P b){
    return abs((p-a).det(p-b)<EPS&&(p-a).dot(p-b)<=EPS);
}

//TODO 按凸包从小到大排序
double solve(){
    rep(i,0,n+1){
        c[i].areasum=calcarea(c[i].c);
    }
    sort(c,c+n);
    area[0]=c[0].areasum;
    rep(i,1,n+1){
        area[i]=c[i].areasum-c[i-1].areasum;
    }
    // rep(i,0,n){
    // 	LOG("area"<<i<<":"<<area[i]);
    // }
    int M=readll();
    rep(_,0,M){
        P p;p.read();
        // if(abs(p.x)<=EPS&&abs(p.y)<=EPS) continue;
        int l=-1,r=n+1;//r:satisfy
        while(r-l>1){
            int mid=(l+r)/2;
            bool cur=containOn(c[mid].c,p);
            // LOG("check"<<mid<<":"<<(cur?"true":"false"));
            if(cur) r=mid;
            else l=mid;
        }
        // bool ok=true;
        // rep(i,0,c[r].c.size()){
        // 	if(onseg(p,c[r].c[i],c[r].c[(i+1)%c[r].c.size()])){
        // 		ok=false;
        // 		break;
        // 	}
        // }
        // if(ok)
        vis[r]++;
        // LOG("in"<<r);
    }
    long double ans=0;
    rep(i,0,n){
        if(vis[i]) {
            ans+=area[i];
            // LOG("vis[]"<<i);
        }
    }
    return ans;
}

int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    n=readll();
    rep(i,0,n){
        int k=readll();
        rep(_,0,k){
            P p;p.read();
            // c[i].inser(p);
            c[i].c.push_back(p);
        }
    }
    c[n].c.push_back({-1e7,1e7});
    c[n].c.push_back({-1e7,-1e7});
    c[n].c.push_back({1e7,-1e7});
    c[n].c.push_back({1e7,1e7});
    double ans=solve();
    printf("%.10f\n",ans);
    return 0;
}
/*


3
4
-10 -10
10 -10
10 10
-10 10

4
30 -30
30 30
-30 30
-30 -30
4
20 20
-20 20
-20 -20
20 -20

5
1 1
1 1
1 1
1 1
1 1
1 1
11 11
111 123
22 23


*/
