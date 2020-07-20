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
#define rep(i,a,n) for(int i=(a);i<(n);++i)
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

const int sz=1e3+9;

struct Rect{
	ll l,r,t,b;
	Rect move(ll dx,ll dy){
		return {l+dx,r+dx,t+dy,b+dy};
	}
} x,y;
ll w,h;
int getx(){
	if(x.l>=y.l&&x.l<=y.r) return 0;
	if(x.r>=y.l&&x.r<=y.r) return 0;
	if(y.l>=x.l&&y.l<=x.r) return 0;
	if(y.r>=x.l&&y.r<=x.r) return 0;
	if(x.l<y.l){
		return max(0LL,(y.l-x.r)/w-1);
	}else{
		return max(0LL,(x.l-y.r)/w-1);
	}
}
int gety(){
	if(x.b>=y.b&&x.b<=y.t) return 0;
	if(x.t>=y.b&&x.t<=y.t) return 0;
	if(y.b>=x.b&&y.b<=x.t) return 0;
	if(y.t>=x.b&&y.t<=x.t) return 0;
	if(x.b<y.b){
		return max(0LL,(y.b-x.t)/h-1);
	}else{
		return max(0LL,(x.b-y.t)/h-1);
	}
}
ll getarea(Rect x,Rect y){
	ll minr=min(x.r,y.r);
	ll maxl=max(x.l,y.l);
	ll mint=min(x.t,y.t);
	ll maxb=max(x.b,y.b);
	ll ww=minr-maxl;
	ll hh=mint-maxb;
	// LOG(ww<<','<<hh);
	if(ww<=0||hh<=0) return 0;
	return ww*hh;
}
int k;
ll solve(){
	int dx=getx();
	int dy=gety();
	ll ans=0;
	rep(i,dx-5,dx+5){
		rep(j,dy-5,dy+5){
			if(abs(i)+abs(j)>k) continue;
			Rect z=x.move(i*w,j*h);
			ll cur=getarea(z,y);
			// LOG("d"<<i<<","<<j<<":"<<cur);
			ans=max(ans,cur);
		}
	}
	return ans;
}
int main(){
	int _;
	cin>>_;
	while(_--){
		scanf("%I64d%I64d%I64d%I64d",&x.l,&x.b,&x.r,&x.t);
		scanf("%I64d%I64d%I64d%I64d",&y.l,&y.b,&y.r,&y.t);
		scanf("%d",&k);
		w=x.r, h=x.t;
		x.r+=x.l;x.t+=x.b;
		y.r+=y.l;y.t+=y.b;
		// if(x.l>x.r) swap(x.l,x.r);if(x.b>x.t) swap(x.b,x.t);
		// if(y.l>y.r) swap(y.l,y.r);if(y.b>y.t) swap(y.b,y.t);
		ll ans=solve();
		cout<<ans<<endl;
	}
	return 0;
}
/*
1
0 0 10 10
5 10 15 10
2

*/

