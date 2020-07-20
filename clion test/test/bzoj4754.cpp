#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 1e5+7;
const ull base = 12589;
int read()
{
    int x = 0 , f = 1;
    char in = getchar();
    while(in < '0' || in >'9')
    {
        if(in == '-')
            f = -1;
        in = getchar();
    }
    while(in >= '0' && in <= '9')
    {
        x = (x << 3) + (x << 1) + in - '0';
        in = getchar();
    }
    if(f == -1)
        return -x;
    return x;
}
struct data
{
    ull hash_;
    int u;
    data(ull a = 0, int u_ = 0) : hash_(a) , u(u_){}
    bool operator < (data c) const { return hash_ < c.hash_;}
}p[N];
ull q[N],bin[N];
struct Tree
{
    vector < int > l[N];
    int d[N],size[N],fa[N];
    int n;
    ull v[N],rt[N],f[N],su[N],pr[N];
    void build(int f,int t)
    {
        l[f].push_back(t);
        l[t].push_back(f);
        d[f] ++ , ++ d[t];
    }
    void init()
    {
        for(int i = 1 ; i <= n ; i ++)
            l[i].clear() , d[i] = 0;
        fa[1] = 0;
        for(int i = 1 ; i < n ; i ++)
            build(read(),read());
    }
    void dfs1(int u,int ff)
    {
        fa[u] = ff;
        size[u] = 1;
        for(int i = 0 ; i < l[u].size() ; i ++)
        {
            int t = l[u][i];
            if(t == ff)
                continue;
            dfs1(t,u);
            size[u] += size[t];
        }
        int k = 0;
        for(int i = 0 ; i < l[u].size() ; i ++)
            if(l[u][i] != fa[u])
                q[++k] = v[l[u][i]];
        sort(q+1,q+k+1);
        v[u] = 0;
        for(int i = 1 ; i <= k ; i ++)
            v[u] = v[u] * base + q[i];
        v[u] = v[u] * base + (ull)size[u];
    }
    void dfs2(int u,int ff)
    {
        int k = 0;
        if(u > 1)
            p[++k] = data(f[u],fa[u]);
        for(int i = 0 ; i < l[u].size() ; i ++)
        {
            if (l[u][i] != ff)
                p[++k] = data(v[l[u][i]], l[u][i]);
        }
        sort(p+1,p+k+1);
        pr[0] = 0;
        for(int i = 1 ; i <= k ; i ++)
            pr[i] = pr[i-1] * base + p[i].hash_;
        su[k+1] = 0;
        for(int i = k ; i >= 1 ; i --)
            su[i] = su[i+1] + p[i].hash_ * bin[k-i];
        for(int i = 1 ; i <= k ; i ++)
            if(p[i].u != fa[u])
            {
                f[p[i].u] = pr[i-1] * bin[k-i] + su[i+1];
                f[p[i].u] = f[p[i].u] * base + (ull)(n-size[p[i].u]);
            }
        for(int i = 0 ; i < l[u].size() ; i ++)
            if(l[u][i] != fa[u])
                dfs2(l[u][i],u);
    }
    void calc()
    {
        dfs1(1,0);
        dfs2(1,0);
        for(int u = 1 ; u <= n ; u ++)
        {
            int k = 0;
            for(int i = 0 ; i < l[u].size() ; i ++)
            {
                if(l[u][i] != fa[u])
                    q[++k] = v[l[u][i]];
            }
            if(fa[u])
                q[++k] = f[u];
            sort(q+1,q+k+1);
            rt[u] = 0;
            for(int i = 1 ; i <= k ; i ++)
                rt[u] = rt[u] * base + q[i];
            rt[u] = rt[u] * base + (ull)n;
        }
    }
}tree1,tree2;
map < ull,bool > mp;
int main()
{
    int n = read();
    bin[0] = 1;
    for(int i = 1 ; i <= n + 2 ; i ++)
        bin[i] = bin[i-1] * base;
    tree1.n = n , tree2.n = n + 1;
    tree1.init();
    tree1.calc();
    tree2.init();
    tree2.calc();
    for(int i = 1 ; i <= n ; i ++)
        mp[tree1.rt[i]] = true;
    for(int i = 1 ; i <= n + 1 ; i ++)
        if(tree2.d[i] == 1 && ((i != 1 && mp[tree2.f[i]]) || (i == 1 && mp[tree2.v[tree2.l[1][0]]])))
        {
            printf("%d\n",i);
            return 0;
        }
    return 0;
}

