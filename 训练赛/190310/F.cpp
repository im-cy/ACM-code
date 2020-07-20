#include <iostream>
#include <cstring>
using namespace std;
int a[1000];
int d[1000][1000];
const int INF = 99999999;

int gcd(int x, int y)
{
    if(y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        int m = n * 2 + 1;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= 900; i ++)
        {

            for(int j = 1; j <= 900; j ++)
                d[i][j] = INF;
            d[i][i + 1] = 0;
        }
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            a[n + i] = a[i];
        }
        for(int i = 2; i < n; i ++)
        {
            for(int j = 1; j <= m - i; j ++)
            {
                for(int k = j + 1; k <= j + i - 1; k ++)
                {
                    d[j][j + i] = min(d[j][j + i], d[j][k] + d[k][j + i] + gcd(a[j], a[j + i]));
                }
            }
        }
        int ans = INF;
        for(int i = 1; i <= n; i ++)
            ans = min(ans, d[i][i + n - 1] + gcd(a[i], a[i + n - 1]));
        cout << ans << endl;
    }
    return 0;
}

