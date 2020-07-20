#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
const int N = 100005;
typedef unsigned long long ULL;
const ULL se = 12589;
int read()
{
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
struct data{
    ULL a; int b;
    data(ULL c = 0, int d = 0) : a(c), b(d) {}
    bool operator < (data c) const {return a < c.a;}
}p[N];
ULL q[N], bin[N];
struct Tree {
    int nxt[N<<1], to[N<<1];
    int pre[N],d[N],siz[N],fa[N];
    int top, n;
    ULL v[N],rt[N],f[N],su[N],pr[N];
    void add(int u, int v)
    {
        to[++top] = v;
        nxt[top] = pre[u];
        pre[u] = top;
    }
    void adds(int u, int v)
    {
        add(u, v);
        add(v, u);
        ++ d[u];
        ++ d[v];
    }
    void init()
    {
        top = 0;
        for(int i = 1;i <= n; ++i)
            pre[i] = d[i] = 0;
        fa[1] = 0;
        for(int i = 1;i < n; ++i)
            adds(read(), read());
    }
    void dfs1(int u)
    {
        siz[u] = 1;
        for(int i = pre[u] ; i ; i = nxt[i])
            if(to[i] != fa[u])
            {
                fa[to[i]] = u;
                dfs1(to[i]);
                siz[u] += siz[to[i]];
            }
        int k = 0;
        for(int i = pre[u] ; i; i = nxt[i])
            if(to[i] != fa[u])
                q[++k] = v[to[i]];
        sort(q + 1, q + k + 1);
        v[u] = 0;
        for(int i = 1 ; i <= k; ++ i)
            v[u] = v[u] * se + q[i];
        v[u] = v[u] * se + ULL(siz[u]);
    }
    void dfs2(int u)
    {
        int k = 0;
        if(u > 1)
            p[++k] = data(f[u], fa[u]);
        for(int i = pre[u] ; i ; i = nxt[i])
            if(to[i] != fa[u])
                p[++k] = data(v[to[i]], to[i]);
        sort(p + 1, p + k + 1);
        pr[0] = 0;
        for(int i = 1 ; i <= k ; ++ i)
            pr[i] = pr[i - 1] * se + p[i].a;//pr 对hash值v再一次hash
        su[k + 1] = 0;
        for(int i = k ; i >= 1 ; -- i)
            su[i] = su[i + 1] + p[i].a * bin[k - i];
        for(int i = 1 ; i <= k ; ++ i)
            if(p[i].b != fa[u])
            {
                f[p[i].b] = pr[i - 1] * bin[k - i] + su[i + 1];//f[u]为节点u的父亲方向上的hash值
                f[p[i].b] = f[p[i].b] * se + (ULL)(n - siz[p[i].b]);
            }
        for(int i = pre[u]; i; i = nxt[i])
            if(to[i] != fa[u])
                dfs2(to[i]);
    }
    void calc()
    {
        dfs1(1);
        dfs2(1);
        for(int u = 1 ; u <= n ; ++ u)
        {
            int k = 0;
            for(int i = pre[u] ; i ; i = nxt[i])
                if(to[i] != fa[u])
                    q[++k] = v[to[i]];
            if(fa[u])
                q[++k] = f[u];
            sort(q + 1, q + k + 1);
            rt[u] = 0;
            for(int i = 1 ; i <= k ; ++ i)
                rt[u] = rt[u] * se + q[i];
            rt[u] = rt[u] * se + ULL(n);
        }
    }
}a, b;
set<ULL>s;
int main() {
    int m = read();
    bin[0] = 1;
    for(int i = 1 ; i <= m + 2; ++ i)
        bin[i] = bin[i - 1] * se;
    a.n = m;
    a.init();
    a.calc();
    b.n = m + 1;
    b.init();
    b.calc();
    for(int i = 1 ; i <= m ; ++ i)
        s.insert(a.rt[i]);
    for(int i = 1 ; i <= m + 1 ; ++ i)
        if(b.d[i] == 1 && ((i != 1 && s.find(b.f[i]) != s.end())
                           || (i == 1 && s.find(b.v[b.to[b.pre[1]]]) != s.end())) )
        {
            if(i == 1 && s.find(b.v[b.to[b.pre[1]]]) != s.end())
            {
                printf("## %d\n",b.to[b.pre[1]]);
            }
            return 0 * printf("%d\n", i);
        }
    return 0;
}
/*
10
1 2
1 3
2 4
4 10
3 5
5 7
5 8
3 6
6 9
2 1
1 4
4 10
2 3
3 5
3 6
6 9
5 7
5 8
10 11

5
1 2
2 3
1 4
1 5
1 2
2 3
3 4
4 5
3 6

*/