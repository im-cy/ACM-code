#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define mem(x,v) memset(x,v,sizeof(x)) 
#define rep(i,a,b)  for (int i = a; i < b; i++)
#define per(i,a,b)  
for (int i = a; i > b; i--)
using namespace std;
typedef long long LL;
const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;
const int N = 3000+10;
int sum[N],w[N];
int vs[N],id[N];
int dp[N][32];
bool ans[100100];
int n;
int dep[N];
int Head[N],cnt,l[N],Next[N];
void Add(int u, int v){
	cnt++;
	Next[cnt] = Head[u];
	Head[u] = cnt;
	l[cnt] = v;
	return;
}
int dfs_clock = 1; 
void init()
{
	memset(sum,0,sizeof(sum));
	memset(w,0,sizeof(w));
	memset(vs,0,sizeof(vs));
	memset(id,0,sizeof(id));
	memset(dp,0,sizeof(dp));
	memset(ans,0,sizeof(ans));
	memset(dep,0,sizeof(dep));
	memset(Head,0,sizeof(Head));
	memset(l,0,sizeof(l));
	cnt = 0;
	dfs_clock = 1;
}
void dfs(int u,int fa,int d,int dist)
{
	id[u] = dfs_clock;
	vs[dfs_clock] = u;
	sum[u] = dist;
	dep[dfs_clock++] = d;
	for(int i = Head[u] ; i ; i = Next[i])
	{
		int t = l[i];
		if(t != fa)
		{
			dfs(t,u,d+1,dist+w[t]);
			vs[dfs_clock] = u;
			dep[dfs_clock++] = d;
		}
	}
}
void RMQ_init(int NN)//预处理 区间最小值  
{  
    for(int i = 1; i <= NN; i++)  
        dp[i][0] = i;  
    for(int j = 1; (1<<j) <= NN; j++)  
    {  
        for(int i = 1; i + (1<<j) - 1 <= NN; i++)  
        {  
            int a = dp[i][j-1];  
            int b = dp[i + (1<<(j-1))][j-1];  
            if(dep[a] <= dep[b])  
                dp[i][j] = a;  
            else  
                dp[i][j] = b;  
        }  
    }  
}  
int query(int L, int R)  
{ 
    int k = 0;
    while((1<<(k+1)) <= R-L+1) k++;
    int a = dp[L][k];
    int b = dp[R - (1<<k) + 1][k];
    if(dep[a] <= dep[b])
        return a;
    else
        return b;
}  
int lca(int u, int v)
{
    int x = id[u];
    int y = id[v];
    if(x > y)
        return vs[query(y, x)];
    else
        return vs[query(x, y)];
}
int read()
{
	int x = 0 ;
	char ins = getchar();
	while(ins < '0' || ins > '9')
		ins = getchar();
	while(ins >= '0' && ins <= '9')
	{
		x = x * 10 + ins - '0';
		ins = getchar();
	}
	return x;
}
int main(){
	int T = read();
	while(T--)
	{
		int m;
		init();
		n = read() , m = read();
		rep(i,1,n)
		{
			int x = read() , y = read();
		    Add(x,y);
		}
		for(int i = 1 ; i <= n ; i ++)
			w[i] = read();
		dfs(1,-1,0,w[1]);
		RMQ_init(dfs_clock-1);
		
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = i ; j <= n ; j ++)
			{
				int lca_i_j;
				if(i == j)
					lca_i_j = i;
				else
					lca_i_j = lca(i,j);
				int temp = sum[i]+sum[j]-2*sum[lca_i_j]+w[lca_i_j];
				if(temp >= 1 && temp <= m)
					ans[temp] = 1;
			}
		}
		for(int i = 1 ; i <= m ; i ++)
			printf("%d",ans[i]);
		puts("");
	}
	return 0;
}

