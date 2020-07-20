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
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;

int msg[2000];
int P,K;
int n;
int a[2000];
int sg(int x){
	if(x<=0) return 0;
	if(~msg[x]) return msg[x];
	bool state[25];
	rep(i,0,K){
		int cur=x-i;
		cur-=a[cur];
		state[sg(cur)]=1;
	}
	rep(i,0,25){
		if(!state[i]) return msg[x]=i;
	}
	return 0;
}
int main(){
	scanf("%d%d",&P,&K);
	int ans=0;
	rep(i,0,P){
		mem(msg,-1);
		scanf("%d",&n);
		rep(i,1,n+1){
			scanf("%d",&a[i]);
		}
		int s=sg(n);
		ans^=s;
	}
	// LOG(ans);
	if(ans) puts("Alice can win.");
	else puts("Bob will win.");
	return 0;
}
/*

1 1
3 1 1 2

2 1
2 1 2
2 1 1

*/
