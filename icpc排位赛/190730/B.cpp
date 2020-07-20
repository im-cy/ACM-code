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
#include <ctime>
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
const int sz=400009;

int n;
ll x;
ll fac[50],cnt[50],tot;
void factor(ll n)
{
	tot=0;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			while(n%i==0) n/=i,cnt[tot]++;
			fac[tot++]=i;
		}
	}
	if(n!=1) fac[tot++]=n,cnt[tot-1]=1;
}
ll a[sz];
int num[sz][50];
int rub[sz];
int e[sz], se[sz];
vector<int> v;

bool init(){
    v.clear();
    memset(e, 0, sizeof(e));
    memset(se, 0, sizeof(se));
    memset(cnt, 0, sizeof(cnt));
	factor(x);
	rep(i,0,n+5) rub[i]=0;
	rep(i,0,n+1) rep(j,0,tot+5) num[i][j]=0;
	rep(i,0,n){
		ll x=a[i];
		rep(j,0,tot){
			if(x%fac[j]==0){
				while(x%fac[j]==0) x/=fac[j],num[i][j]++;
			}
		}
		if(x!=1) rub[i]=1;
		else v.push_back(i);
	}
	bool b[50];
	memset(b, 0, sizeof(b));
	for(int i = 0; i < v.size(); i ++)
    {
        for(int j = 0; j < tot; j ++)
        {
            if(num[i][j] == cnt[j])
                e[i] ++, b[j] = 1;
        }
        e[i] = e[i] * e[i];
        e[i] = max(e[i], 5);
        se[i] = e[i];
        if(i > 0) se[i] += se[i - 1];
    }
    for(int i = 0; i < tot; i ++)
        if(b[i] == 0)
                return 0;
    return 1;
}

int solve()
{
    bool b[50], flag;
    memset(b, 0, sizeof(b));
    int sum = se[v.size() - 1], ans = 0;
    while(233)
    {
        int x = rand() % sum + 1;
        int p = lower_bound(se, se + v.size(), x) - se;
        flag = false;
        for(int i = 0; i < tot; i ++)
            if(num[p][i] == cnt[i])
                b[i] = 1, flag = true;
        if(flag == false)
            continue ;
        else ans ++;
        for(int i = 0; i <= tot; i ++)
        {
            if(i == tot) return ans;
            if(b[i] == 0) break ;
        }
    }
}

int main()
{
    srand(time(0));
	int _=readll(),casei=0;
	while(_--){
		n=readll(),x=readll();
		rep(i,0,n) a[i]=readll();
		if(!init())
        {
            printf("Case %d: %d\n",++casei,-1);
            continue ;
        }
		int ans = 1000;
		for(int i = 1; i <= 500; i ++)
            ans = min(ans, solve());
		printf("Case %d: %d\n",++casei,ans);
	}
	return 0;
}

/*
3
8 60
2 9 12 15 16 21 25 40
8 90
2 36 44 49 50 63 64 81
8 36028797018963968
36028797018963968 2 2 2 2 2 2 2

*/
