#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 9223372036854775807ll;
struct Tree
{
    int h, cnt; bool use;
    vector<int> c, p;
}t[100005];
struct fackTree
{
    int h, c, p;
    bool operator < (const fackTree &ft)
    {
        return h < ft.h;
    }
}w[100005];
ll sum[100005];
ll cnt[205];

ll read()
{
    ll x = 0;
    char in = getchar();
    while(in < '0' || in > '9')
    {
        in = getchar();
    }
    while(in >= '0' && in <= '9')
    {
        x = (x << 3) + (x << 1) + in - '0';
        in = getchar();
    }
    return x;
}

int main()
{
    int n, T = 30; ll x, y, z;
    while(T --)
    {
        n = 100000;
        ll treeCnt = 0, ans = INF;
        memset(t, 0, sizeof(t));
        memset(w, 0, sizeof(w));
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= 100000; i ++)
            t[i].c.clear(), t[i].p.clear();
        for(int i = 1; i <= n; i ++)
            w[i].h = i, w[i].c = i / 500, w[i].p = i;
        sort(w + 1, w + n + 1);
        for(int i = 1; i <= n; i ++)
        {
            t[i].h = w[i].h;
            t[i].cnt = t[i].use = 1;
            t[i].c.clear(), t[i].c.push_back(w[i].c);
            t[i].p.clear(), t[i].p.push_back(w[i].p);
        }

        for(int i = 1; i <= n; i)
        {
            for(int j = i + 1; j <= n + 1; j ++)
                if(j == n + 1 || t[j].h != t[i].h)
                {
                    i = j;
                    break;
                }
                else
                {
                    t[j].use = 0; t[i].cnt ++;
                    t[j].c.clear(), t[j].p.clear();
                    t[i].c.push_back(t[j].c[0]);
                    t[i].p.push_back(t[j].p[0]);
                }
        }
        for(int i = n; i >= 1; i --)
        {
            sum[i] = sum[i + 1];
            if(t[i].use == 0) continue ;
            for(int j = 0; j < t[i].cnt; j ++)
                sum[i] += t[i].p[0];
        }
        for(int i = 1; i <= n; i ++)
            if(t[i].use == 1)
            {
                ll value = sum[i + 1], need = treeCnt + 1;
                for(int j = 0; j < t[i].cnt; j ++)
                    need -= t[i].p[j];
                need = max(need, 0ll);
                for(int j = 200; j > 0; j --)
                {
                    value += min(cnt[j], need) * (ll) j;
                    need -= min(cnt[j], need);
                    if(need == 0) break ;
                }
                for(int j = 0; j < t[i].cnt; j ++)
                    cnt[t[i].c[j]] += t[i].p[j],
                            treeCnt += t[i].p[j];
                ans = min(ans, value);
            }
        cout << ans << endl;
    }
    return 0;
}

/*
2
5 1 1
1 10 1
2
5 1 2
3 2 3
3
1 1 5
5 2 2
5 1 2

*/