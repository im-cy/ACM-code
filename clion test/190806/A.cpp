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
typedef vector<int> vec;

const int sz=2e5+9;

struct Node{
    string name;
    int score;
    vec p;
    void read(){

        while(cin.peek()==' '||cin.peek()=='\n') cin.get();
        while(true){
            if(cin.peek()>='0'&&cin.peek()<='9'){
                name.pop_back();
                break;
            }
            char c=cin.get();
            name.push_back(c);
        }
        score=readll();
        int n=readll();
        p.resize(n);
        rep(i,0,n){
            p[i]=(readll());
        }
    }
    bool operator<(const Node &b){
        return make_tuple(-score,p.size())<make_tuple(-b.score,b.p.size());
    }
}a[sz];

struct Arm{
    vector<string*> v;
    int n;
}b[sz];
int n,m;
char tolower(char c){
    if(c>='A'&&c<='Z') return c-'A'+'a';
    return c;
}
bool cmp(const string *pa,const string *pb){
    const string &a=*pa, &b=*pb;
    int len=min(a.size(),b.size());
    rep(i,0,len){
        if(tolower(a[i])<tolower(b[i])) return true;
        else if(tolower(a[i])>tolower(b[i])) return false;
        if(a[i]<b[i]) return true;
        else if(a[i]>b[i]) return false;
    }
    return a.size()<b.size();
}
void solve(){
    sort(a,a+n);
    rep(i,0,n){
        for(int t:a[i].p){
            if(b[t].v.size()<b[t].n){
                b[t].v.push_back(&a[i].name);
                break;
            }
        }
    }
    rep(i,1,m+1){
        sort(b[i].v.begin(), b[i].v.end(),cmp);
    }
    // bool need=false;
    rep(i,1,m+1){
        // if(b[i].v.size()==0) continue;
        // if(need) puts("");
        for(string *s:b[i].v) printf("%s\n",s->c_str());
        // need=true;
        if(i<m) puts("");
    }
}


int main(){
    freopen("army.in","r",stdin);
    freopen("army.out","w",stdout);
    n=readll(),m=readll();int k=readll();
    rep(i,1,m+1) b[i].n=readll();
    // rep(i,1)
    rep(i,0,n){
        a[i].read();
    }
    solve();
    return 0;
}
/*


4 2 2
2 2
Grom Hellscream 1200 2 1 2
Thrzll 1500 2 1 2
Orgrim Doomhammer 1450 2 2 1
ttrgath Bladefist 1400 2 1 2

*/