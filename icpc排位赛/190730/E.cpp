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

const double PI=3.14159265358979;


char s[sz];
char t[sz];

int par[sz];
int v[sz];
void init(int n){
	rep(i,0,n+1) par[i]=i,v[i]=1;
}
int find(int x){
	if(par[x]==x) return x;
	int root=find(par[x]);
	v[root]+=v[x];
	return par[x]=root;
	// else return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	par[x]=y;
	v[y]+=v[x];
}
struct query{
	int op,x;
	int ans;
}q[sz];
void solve(){
	int n=strlen(s);
	init(n+5);
	memcpy(t,s,n*sizeof(char)+5);
	int m=readll();
	rep(i,0,m){
		q[i].op=readll(),q[i].x=readll();
		if(q[i].op==2){
			t[q[i].x]='#';
		}
	}
	rep(i,1,n){
		if(t[i]==t[i-1]&&t[i]!='#'){
			unite(i,i-1);
		}
	}
	per(i,0,m){
		if(q[i].op==1){
			q[i].ans=v[find(q[i].x)];
		}else{
			int x=q[i].x;
			if(x>0&&s[x]==t[x-1]){
				unite(x,x+1);
			}
			if(x<n-1&&s[x]==t[x+1]){
				unite(x,x+1);
			}
			t[x]=s[x];
		}
	}
	rep(i,0,m){
		if(q[i].op==1) printf("%d\n", q[i].ans);
	}
}

int main(){
	int _=readll(),casei=0;
	while(_--){
		printf("Case %d:\n",++casei);
		scanf("%s",s);
		solve();
	}
	return 0;
}
