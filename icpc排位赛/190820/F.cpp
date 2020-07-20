#include <bits/stdc++.h>
using namespace std;
vector<int> prim;
vector<int> cnt[100005];
vector<int> d[1000005];
int b[1000005];
int f[1000005];

int fa(int x)
{
    if(f[x] == x) return x;
    return fa(f[x]);
}

bool merg(int x, int y)
{
    if(fa(x) == fa(y))
        return 0;
    f[fa(x)] = fa(y);
    return 1;
}

void init()
{
    const int n = 1e6;
    for(int i = 2; i <= n; i ++)
        if(b[i] == 0)
        {
            prim.push_back(i);
            for(int j = i * 2; j <= n; j += i)
                b[j] = 1;
        }
    for(int i = 1; i <= n; i ++) b[i] = i;
    for(int i = 0; i < prim.size(); i ++)
        for(int j = prim[i]; j <= n; j += prim[i])
        {
            d[j].push_back(i);
            while(b[j] % prim[i] == 0)
                b[j] /= prim[i];
        }
}

int main()
{
    init();
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++)
    {
        int n, x; scanf("%d", &n);
        for(int i = 0; i <= prim.size(); i ++)
            cnt[i].clear();
        for(int i = 1; i <= 1000000; i ++)
            f[i] = i;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &x);
            for(int j = 0; j < d[x].size(); j ++)
                cnt[d[x][j]].push_back(i);
        }
        int ans = n;
        for(int i = 0; i < prim.size(); i ++)
            for(int j = 0; j < cnt[i].size(); j ++)
            {
                if(j == cnt[i].size() - 1) break ;
                if(merg(cnt[i][j], cnt[i][j + 1]))
                    ans --;
            }
        cout << "Case " << cas << ": " << ans << endl;
    }
    return 0;
}
