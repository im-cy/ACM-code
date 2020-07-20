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

const int sz=1e6+9;

struct Node{
	int l,r;
	int d; 
	friend bool operator<(const Node &a,const Node &b){
		if(a.d!=b.d) return a.d<b.d;
		return a.r<b.r;
	}
}a[sz];

int getMinPoints(Node *b,int n){
	int curr=-1,ans=0;
	rep(i,0,n){
		if(a[i].l<=curr) {
			
		}else{
			curr=a[i].r;
			ans++;
		}
	}
	return ans;
}

int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		rep(i,0,n) {
			int a,b,d;
			scanf("%d%d%d",&a,&b,&d);
			a[i]={a,a+b,d};
		}
		sort(a,a+n);
		
		rep(i,0,n){
			
		}
	}
	return 0;
}




