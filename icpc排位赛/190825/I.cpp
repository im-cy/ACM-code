#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000ll + 10 ;
const double eps = 1e-8;
const int maxn = 5e4 + 10;
const double PI = acos(-1);
int dp[maxn][2],head[maxn],val[maxn],ss[maxn],ff[maxn],cnt;
bool sta;
struct st{
    int to,nxt;
}edge[maxn*2];
int n,x,y;
void add(int u,int v)
{
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt;
    cnt++;
}
void dfs(int u,int pre)
{
    if(ss[u])
		sta = !sta;
    if(sta)
		val[u] = -val[u];
    dp[u][0] = val[u];
    dp[u][1] = -val[u];
    for(int i = head[u];i != -1;i = edge[i].nxt)
	{
        int v = edge[i].to;
        if(v == pre)
			continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1] - (ss[v]?y:x));
        dp[u][1] += max(dp[v][1],dp[v][0] - (ss[v]?y:x));
    }
    if(ss[u])
		sta = !sta;
}
void init(){
    cnt = 0;
    memset(dp,0,sizeof(dp));
    memset(head,-1,sizeof(head));
}
int main()
{
    while(~scanf("%d%d%d",&n,&x,&y))
	{
        init();
        int fr;
        for(int i = 1;i <= n;i++)
		{
            scanf("%d%d%d%d",&val[i],&fr,&ss[i],&ff[i]);
            if(ff[i])
				val[i] = -val[i];
            add(fr,i);
        }
        sta = false;
        dfs(0,-1);
        if(dp[0][0] < 0)
			cout<<"HAHAHAOMG"<<endl;
        else
			printf("%d\n",dp[0][0]);
    }
    return 0;
}
