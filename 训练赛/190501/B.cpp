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



const int sz=5000;
bool vis0[sz];
ll p[sz],tot=0;
void init_primes(){
	rep(i,2,sz){
		if(!vis0[i]){
			p[tot++]=i;
			for(ll x=ll(i)*i;x<sz;x+=i) vis0[x]=true;
		}
	}
	mem(vis0,0);
	rep(i,0,tot) vis0[p[i]]=true;
}

int n,m,d;
int a[2000];
bool use[2000];
bool dfs(int cur){
	// LOG("dfs"<<cur);
	if(cur==m-n+1) {
		rep(i,0,m-n+1){
			printf("%d%c", a[i],(i==m-n)?'\n':',');
		}
		return true;
	}
	int pre[20]={0};
	int cnt=min(d-1,cur);
	// LOG(cnt);
	rep(i,1,cnt+1){
		pre[i]=a[cur-i]+pre[i-1];
	}
	rep(i,n,m+1){
		if(use[i]) continue;
		bool notok=false;
		rep(j,1,cnt+1){
			if(vis0[pre[j]+i]) {
				notok=true;
				break;
			}
		}
		if(notok) continue;
		a[cur]=i;
		use[i]=true;
		if(dfs(cur+1))return true;
		use[i]=false;
	}
	return false;

}


void solve(){
	rep(i,n,m+1){
		use[i]=0;
	}
	if(dfs(0)==false){
		puts("No anti-prime sequence exists.");
	}

}
int main(){
	init_primes();
	while(scanf("%d%d%d",&n,&m,&d)&&n){
		solve();
	}
	return 0;
}

