#include <stdio.h>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define LOG(a) cout<<'#'<<a<<endl;
using namespace std;
typedef long long ll;
typedef vector<int> vec;

ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

ll a,b,c,d;
bool solve(){
/*	if(a<b) return false;
	if(d<b) return false;
	if(c>=b) return true;
	if(d%b==0){
		ll k=(a-c)/b;
		if(a<c) k=0;
		if(a-(k+1)*b<0) return false;
		else return true;
	}*/
	// int x=ceil(((double)c-a%b)/(d%b));
	// int y=floor(((double)b-a%b)/(d%b));
	// printf("# %d %d\n",x,y);
	// if(x<=y) return false;
	// return true;
	// d=d%b;
	if(gcd(a%c,d)==1)
		return 0;
	return 1;
	// if(gcd(d%b,c)==1) return false;
	// return true;
	// return true;
	// if(b%(d%b)==0) return true;
	// return false;
}

int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		printf(solve()?"Yes\n":"No\n");
	}
}

