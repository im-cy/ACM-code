#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <utility>
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

//const int sz=;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

char s[1000][1000];
int dis[1000][1000];
bool vis[1000][1000];
int n,m,k;
queue<pii> q; 
int getdis(){
	rep(i,0,n+1) rep(j,0,m+1) dis[i][j]=IINF,vis[i][j]=0;
	dis[0][0]=0;
	vis[0][0]=1;
	while(q.size()) q.pop();
	q.push({0,0});
	while(q.size()){
		pii c=q.front();q.pop();
		rep(k,0,4){
			int nx=c.first+dx[k];
			int ny=c.second+dy[k];
			if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]||s[nx][ny]!='.') continue;
			vis[nx][ny]=1;
			dis[nx][ny]=dis[c.first][c.second]+1;
			q.push({nx,ny});
		}
	}
	return dis[n-1][m-1];
}
int main(){
	n=readll(),m=readll(),k=readll();
	rep(i,0,n) scanf("%s",s[i]);
	int a=getdis();
	rep(i,0,k){
		int x=readll(),y=readll();
		s[x][y]='.';
	}
	int b=getdis();
	// LOG(a<<","<<b);
	if(b>=IINF||a<=b){
		puts("NO");
	}else{
		puts("YES");
	}
	return 0;
}
