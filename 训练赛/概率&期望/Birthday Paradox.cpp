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
const int mod = 1000000; 

double f[];

bool check(int n,int t){
	
}
int solve(int t){
	int l=1,r=t;//r
	while(r-l>1){
		int mid=(l+r)/2;
		if(check(mid,t)) r=mid;
		else l=mid;
	}
	return r;
}

int main(){
	int _,I=0;
	cin>>_;
	while(_--){
		int t;
		scanf("%d",&t);
		int ans=solve(t);
		printf("Case %d: %d\n",++I,ans); 
	}
	return 0;
}




