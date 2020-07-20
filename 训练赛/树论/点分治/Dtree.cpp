#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200100;
const int INF = 2e9;
const int mod = 1e6+3;
int n,m;
vector <int> l[sz];
int root,maxx[sz],size[sz],sum,value[sz],inv[sz];
bool vis[sz];
ll ksm(ll x,ll p)
{
	if(p == 0)
		return 1 % mod;
	if(p == 1)
		return x % mod;
	if(p == 2)
		return ((x % mod) * ( x % mod))%mod;
	ll temp = ksm(x,p<<1) % mod;
	if(p % 2)
		return ((temp * temp)%mod * (x%mod))%mod;
	return (temp * temp) % mod;
}
ll get_inv(ll x)
{
	return ksm(x,mod-2)%mod;
}
void build(int f,int t)
{
    l[t].push_back(f);
    l[f].push_back(t);
}
void calcsiz(int u,int fa)
{
    size[u] = 1;
    maxx[u] = 0;
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i];
        if(v == fa || vis[v])
            continue;
        calcsiz(v,u);
        maxx[u] = max(maxx[u],size[v]);
        size[u] += size[v];
    }
    maxx[u] = max(maxx[u],sum-size[u]);
    if(maxx[u] < maxx[root])
        root = u;
}
struct node
{
	int u,dis;
}dd[sz];
int cnt;
int ansl = 214748364,ansr = 214748364;
int tf[2000010];
void upans(int l,int r)
{
	if(l > r)
		swap(l,r);
	if(l < ansl || (l == ansl && r < ansr))
	{
		ansl = l , ansr = r;
	}
}
void calcdis(int u,int fa,int dist,int rt)
{
	int t = dist % mod;
	if(t == m)
		upans(u,rt);
	t = t * get_inv(value[rt]) % mod;
	int t1 = get_inv(t)*m %mod;
	if(tf[t1])
		upans(u,tf[t1]);
    dd[++cnt].dis = dist % mod;
    dd[cnt].u = u;
    printf("\nu %d dist %d:\n",u,dist);
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i];
        int w = value[v] %mod;
        printf("v %d value %d\n",v,w);
        if(vis[v] || v == fa)
            continue;
        calcdis(v,u,dist*w,rt);
    }
}
queue < int > tag;
void dfz(int u)
{
//	printf("%d\n",u);
	cnt = 0;
    vis[u] = true;
    printf("dfs %d\n",u);
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i];
        int w = value[v] % mod;
        if(vis[v])
            continue;
        calcdis(v,u,(w * value[u])%mod,u);
        printf("l %d r %d\n",ansl,ansr);
//            ans[k] |= tf[mod - dd[j]];
        for(int j = 1 ; j <= cnt ; j ++)
        {
        	if(tf[dd[j].dis] == 0)
	            tf[dd[j].dis] = dd[j].u;
	        else
	        	tf[dd[j].dis] = min(tf[dd[j].dis],dd[j].u);
            tag.push(dd[j].dis);
        }
        cnt = 0;
    }
    while(!tag.empty())
    {
        tf[tag.front()] = 0;
        tag.pop();
    }
    for(int i = 0 ; i < l[u].size() ; i ++)
    {
        int v = l[u][i];
        if(vis[v])
            continue;
        sum = size[v];
        root = 0;
        maxx[root] = INF;
        calcsiz(v,u);
        calcsiz(root,-1);
        dfz(root);
    }
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
    {
    	for(int i = 1 ; i <= n ; i ++)
    		scanf("%d",&value[i]);
	    for(int i = 1 ; i < n ; i ++)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        build(a,b);
	    }
	    root = 0;
	    maxx[root] = INF;
	    sum = n;
	    calcsiz(1, -1);
	    calcsiz(root, -1);
	    dfz(root);
	    printf("%d %d\n",ansl,ansr);
    }
    return 0;
}
//

