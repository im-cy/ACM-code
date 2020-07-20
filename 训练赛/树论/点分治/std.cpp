#pragma comment(linker,"/STACK:102400000,102400000") 
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<set>
using namespace std;
typedef long long LL;

const int mod = 1e6 + 3;
const int maxn = 1e5 + 20;
inline int read()
{
    int x = 0; char ch = getchar();
    while (ch<'0' || ch>'9')ch = getchar();
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x;
}

LL V[maxn];
struct Edge
{
    int to; int next;
}e[maxn * 2];

int len, mi, Root, num, n, k;
LL inv[mod + 100];
int head[maxn], Size[maxn], m[maxn], vis[maxn];
inline void add(int from, int to)
{
    e[len].to = to;
    e[len].next = head[from];
    head[from] = len++;
}


void initInv() //预处理逆元
{
    inv[0] = inv[1] = 1;
    for (int i = 2; i < mod + 10; i++) {
        inv[i] = ((-mod / i * inv[mod % i]) % mod + mod) % mod;
    }
}



void gaosize(int x, int fa)  
{
    Size[x] = 1; m[x] = 0;
    for (int i = head[x]; i != -1; i = e[i].next) {
        int cc = e[i].to;
        if (cc == fa || vis[cc]) continue;
        gaosize(cc, x);
        Size[x] += Size[cc];
        m[x] = max(m[x], Size[cc]);
    }
}

void gaoroot(int root, int x, int fa)
{
    m[x] = max(m[x], Size[root] - Size[x]);
    if (mi > m[x]) {
        Root = x; mi = m[x];
    }
    for (int i = head[x]; i != -1; i = e[i].next) {
        int cc = e[i].to;
        if (vis[cc] || cc == fa) continue;
        gaoroot(root, cc, x);
    }
}

const int INF = 1e9 + 10;
int minl;
int minr;
void init()
{
    len = 0;
    minl = INF; minr = INF;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
}


void up(int ll, int rr)
{
    if (rr < ll) swap(ll, rr);
    if (ll == minl) {
        if (rr < minr) {
            minl = ll; minr = rr;
        }
    }
    if (ll < minl) {
        minl = ll; minr = rr;
    }
}

int cnt, top;
int S[maxn * 10], S1[maxn * 10], pos[maxn * 10];
int color[mod * 2 + 1];
void gaodis(int x, int val, int fa, int root)  // 处理结点到Root的距离
{
    int  t = val%mod; 
    if (t == k) up(x, root);
    t = t*inv[V[root]] % mod; 
    int t1 = inv[t] * k%mod;
    //if (t==k) up(x, root); t值变了，我还在这用，真是蠢得不行
    S[top] = val; 
    S1[cnt++] = val;//记录方案，最后清空color
    pos[top++] = x;
    if (color[t1]) {
        up(x, color[t1]);
    }
    for (int i = head[x]; i != -1; i = e[i].next) {
        int cc = e[i].to;
        if (cc == fa || vis[cc]) continue;
        gaodis(cc, val*V[cc] % mod, x, root);
    }
}
void gao(int x)
{
    cnt = 0;
    mi = n;
    gaosize(x, 0);
    gaoroot(x, x, 0); //找重心
    vis[Root] = 1;
    for (int i = head[Root]; i != -1; i = e[i].next) {
        int cc = e[i].to;
        top = 0;
        if (vis[cc])continue;
        gaodis(cc, V[Root] % mod*V[cc] % mod, Root, Root);
        for (int j = 0; j < top; j++) {
            int t = S[j];
            if (color[t] == 0) color[t] = pos[j];
            else color[t] = min(color[t], pos[j]);
        }
    }
    for (int i = 0; i < cnt; i++) color[S1[i]] = 0; // 清空hash表
    for (int i = head[Root]; i != -1; i = e[i].next) {
        int cc = e[i].to;
        if (vis[cc]) continue;
        gao(cc);
    }
}


int main()
{
    //freopen("1.in", "r", stdin);
    int a, b;
    initInv();
    memset(color, 0, sizeof(color));
    while (scanf("%d%d", &n, &k) != EOF) {
        k %= mod;
        init();
        for (int i = 1; i <= n; i++) V[i] = read();
        for (int i = 0; i < n - 1; i++) {
            a = read();
            b = read(); add(b, a); add(a, b);
        }
        gao(1);
        if (minl == INF)printf("No solution\n");
        else printf("%d %d\n", minl, minr);
    }
    return 0;
}
