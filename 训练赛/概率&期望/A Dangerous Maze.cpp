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

const int sz=1000;
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
} 
int a[sz],n;
void solve(int I){
	int b=0;
	int sum=0;
	rep(i,0,n){
		if(a[i]<0) b++;
		sum+=abs(a[i]);
	}
	if(b==n) {
		printf("Case %d: inf\n",I);
		return ;
	}
	int x=sum;
	int y=n-b;
	int d=gcd(x,y);
	x/=d,y/=d;
	
	printf("Case %d: %d/%d\n",I,x,y);
}
int main()
{
	int _,I=0;
	cin>>_;
	while(_--){
		scanf("%d",&n);
		rep(i,0,n) scanf("%d",&a[i]);
		solve(++I);
	}
	return 0;
}
