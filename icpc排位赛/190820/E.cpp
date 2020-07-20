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
//#include <unordered_map>
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
const double PI=acos(-1.0);
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}

const int sz=1000009;

int f[sz];
int n;
vec lis;
void print(int d){
	// LOG(d);
	rep(i,0,d) putchar('(');
	putchar(')');
	// rep(i,0,d) putchar(')');
}
bool solve(){
	lis.clear();
	ll sum=0;
	ll of0=f[0];
	per(i,1,n){
		// LOG("i"<<i<<","<<f[i]<<"sum"<<sum);
		if(f[i]<sum) return false;
		f[i]-=sum;
		if(f[i]){
			sum+=f[i];
			f[0]-=f[i]*i;
			if(f[0]<0) return false;
			while(f[i]--) lis.push_back(i);
		}
		
	}
	// LOG("f[0]"<<f[0]);
	if(f[0]!=0) return false;
	for(int d:lis) print(d),of0--;
	rep(i,0,of0) putchar(')');
	puts("");
	return true;
}
int main(){
	int _=readll(),casei=0;
	while(_--){
		mem(f,0);
		n=readll();
		bool invalid=false;
		rep(i,0,n) {
			ll x=readll();
			if(x>=n) invalid=true;
			else f[x]++;
		}
		if(invalid) printf("Case %d: invalid\n",++casei);
		else {
			printf("Case %d: ",++casei);
			if(solve()==false){
				puts("invalid");
			}
		}
	}
	return 0;
}
/*
99
5
0 0 0 1 1
6
0 0 0 1 1 1
6
0 0 0 1 1 2
6
0 0 0 1 3 2

12
0 0 0 0 0 0 1 2 1 2 3 4

*/
