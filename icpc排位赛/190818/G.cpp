#include <bits/stdc++.h>
using namespace std;
struct hexy
{
    int x, y;
}a[100005];
long long ans[100005];
int n;

int getDis(int x, int y, int midx, int midy)
{
    int dx = x - midx, dy = y - midy;
    if(dx * dy < 0) return max(abs(dx), abs(dy));
    return abs(dx) + abs(dy);
}

int solve(int x, int y)
{
    int ans = 0;
    for(int i = 1; i <= n; i ++)
        ans = max(ans, getDis(a[i].x, a[i].y, x, y));
    return ans;
}

void init()
{
    ans[0] = 1;
    for(long long i = 1; i <= 50000; i ++)
        ans[i] = ans[i - 1] + 6 * i;
}

int main()
{
    int T; scanf("%d", &T); init();
    for(int cas = 1; cas <= T; cas ++)
    {
        scanf("%d", &n);
        int midx, midy;
        for(int i = 1; i <= n; i ++)
            scanf("%d%d", &a[i].x, &a[i].y);
        sort(a + 1, a + n + 1, [](hexy p, hexy q){ return p.x < q.x; });
        midx = (a[1].x * 2 + a[n].x) / 3;
        sort(a + 1, a + n + 1, [](hexy p, hexy q){ return p.y < q.y; });
        midy = (a[1].y + (a[n].y - a[1].y)) / 3;
        int maxdis = 99999;
        for(int i = midx - 50; i <= midx; i ++)
            for(int j = midy - 50; j <= midy; j ++)
                maxdis = min(maxdis, solve(i, j));
        cout << "Case " << cas << ": " << ans[maxdis] << endl;
    }
    return 0;
}

/*
2
1
0 0
3
0 0
-1 0
-2 2

*/
