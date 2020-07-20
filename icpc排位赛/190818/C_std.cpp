#include <bits/stdc++.h>

#define mem(x, v) memset(x, v, sizeof(x))

using namespace std;

typedef long long ll;

const int maxn = 20010;
const int inf = ~0u >> 1u;
//const ll inf = ~0llu >> 1u;

struct gra {
    int mxn;
    int head[maxn], to[maxn << 1], nxt[maxn << 1], cnt;
    int f[maxn << 1];

    void clear(int n = 0) {
        if (n) mxn = n;
        if (cnt != 0) {
            for (int i = 0; i <= mxn; i++) head[i] = 0;
            cnt = 0;
        }
    }

    void add(int a, int b, int c) {
        nxt[++cnt] = head[a];
        head[a] = cnt;
        to[cnt] = b, f[cnt] = c;
    }
} e;

int T, n, m;
int v[maxn], sz[maxn], dep[maxn], fa[maxn], son[maxn], top[maxn], pos[maxn], num[maxn];
int q[maxn], st[maxn];
int tr[maxn << 2][2], lz[maxn << 2][2]; // 0 max, 1 min

#define lch (now << 1)
#define rch ((now << 1)+1)
#define mid ((l+r) >> 1)

inline void up(int now, int tp) {
    if (tp == 0) tr[now][0] = max(tr[lch][0], tr[rch][0]);
    else tr[now][1] = min(tr[lch][1], tr[rch][1]);
}

inline void down(int now) {
    if (lz[now][1] != inf) {
        lz[lch][1] = min(lz[lch][1], lz[now][1]);
        lz[rch][1] = min(lz[rch][1], lz[now][1]);
        tr[lch][1] = min(tr[lch][1], lz[now][1]);
        tr[rch][1] = min(tr[rch][1], lz[now][1]);
        lz[now][1] = inf;
    }
}

void build(int now, int l, int r) {
    lz[now][0] = -inf, lz[now][1] = inf;
    if (l == r) {
        tr[now][0] = v[num[l]], tr[now][1] = inf;
        return;
    }
    build(lch, l, mid);
    build(rch, mid + 1, r);
    up(now, 0), up(now, 1);
}

int ask(int now, int l, int r, int p1, int p2, int tp) {
    if (l == p1 && r == p2) { return tr[now][tp]; }
    if (tp == 1) down(now);
    if (p2 <= mid) return ask(lch, l, mid, p1, p2, tp);
    else if (p1 >= mid + 1) return ask(rch, mid + 1, r, p1, p2, tp);
    else {
        if (tp == 0) return max(ask(lch, l, mid, p1, mid, tp), ask(rch, mid + 1, r, mid + 1, p2, tp));
        else return min(ask(lch, l, mid, p1, mid, tp), ask(rch, mid + 1, r, mid + 1, p2, tp));
    }
}

void mod(int now, int l, int r, int p1, int p2, int v) {
    if (l == p1 && r == p2) {
        tr[now][1] = min(tr[now][1], v);
        lz[now][1] = min(lz[now][1], v);
        return;
    }
    down(now);
    if (p2 <= mid) mod(lch, l, mid, p1, p2, v);
    else if (p1 >= mid + 1) mod(rch, mid + 1, r, p1, p2, v);
    else {
        mod(lch, l, mid, p1, mid, v);
        mod(rch, mid + 1, r, mid + 1, p2, v);
    }
    up(now, 1);
}

void pre() {
    mem(son, 0);
    int l = 1, r = 0, tp = 0, tim = 0;
    q[++r] = 1, dep[1] = 1;
    while (l <= r) {
        int x = q[l++];
        sz[x] = 1;
        for (int i = e.head[x]; i; i = e.nxt[i]) {
            int u = e.to[i];
            if (u == fa[x]) continue;
            v[u] = e.f[i], dep[u] = dep[x] + 1, fa[u] = x, q[++r] = u;
        }
    }
    for (int i = n; i >= 1; i--) {
        int x = q[i];
        if (!fa[x]) continue;
        sz[fa[x]] += sz[x];
        if (sz[son[fa[x]]] < sz[x]) son[fa[x]] = x;
    }
    st[++tp] = 1, top[1] = 1;
    while (tp > 0) {
        int x = st[tp--];
        pos[x] = ++tim, num[tim] = x;
        for (int i = e.head[x]; i; i = e.nxt[i]) {
            int u = e.to[i];
            if (u == fa[x] || u == son[x]) continue;
            st[++tp] = u, top[u] = u;
        }
        if (son[x]) st[++tp] = son[x], top[son[x]] = top[x];
    }
}

int ask(int x, int y, int tp) {
    int res = tp == 0 ? -inf : inf;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        if (tp == 0) res = max(res, ask(1, 1, n, pos[top[x]], pos[x], tp));
        else res = min(res, ask(1, 1, n, pos[top[x]], pos[x], tp));
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    if (pos[y] + 1 > pos[x]) return res;
    if (tp == 0) res = max(res, ask(1, 1, n, pos[y] + 1, pos[x], tp));
    else res = min(res, ask(1, 1, n, pos[y] + 1, pos[x], tp));
    return res;
}

void mod(int x, int y, int v) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        mod(1, 1, n, pos[top[x]], pos[x], v);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    if (pos[y] + 1 > pos[x]) return;
    mod(1, 1, n, pos[y] + 1, pos[x], v);
}

int ra[maxn*10], rb[maxn*10];
int aa[maxn], bb[maxn], cc[maxn];

int read() {
    int f = 1, p = 0;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        p = p * 10 + c - '0';
        c = getchar();
    }
    return f * p;
}

int main() {
	freopen("input.txt","r",stdin);
//	freopen("std.txt","w",stdout);
    scanf("%d", &T);
    for (int C = 1; C <= T; C++) {
        scanf("%d%d", &n, &m);
        e.clear(n);
        for (int i = 1; i < n; i++) {
            aa[i] = read(), bb[i] = read(), cc[i] = read();
            e.add(aa[i], bb[i], cc[i]);
            e.add(bb[i], aa[i], cc[i]);
        }
        pre();
        build(1, 1, n);
        for (int i = n, a, b, c; i <= m; i++) {
            a = read(), b = read(), c = read();
            ra[i] = inf, rb[i] = c - ask(a, b, 0);
            mod(a, b, c);
        }
        for (int i = 1; i < n; i++) {
            if (dep[aa[i]] < dep[bb[i]]) swap(aa[i], bb[i]);
            int tmp = ask(1, 1, n, pos[aa[i]], pos[aa[i]], 1);
            ra[i] = tmp == inf ? inf : tmp - cc[i], rb[i] = inf;
        }
        ll res = 0;
        for (ll i = 1; i <= m; i++)
		{
			res += i * (ra[i] == inf ? -1 : ra[i])
                   + i * i * (rb[i] == inf ? -1 : rb[i]);
            printf("a %d b %d\n",(ra[i] == inf ? -1 : ra[i]), (rb[i] == inf ? -1 : rb[i]));
		}
        printf("Case %d: %lld\n", C, res);
    }
    return 0;
}
