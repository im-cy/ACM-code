#include <iostream>
#include <cstdio>
using namespace std;
int js[50];
int ans[1000][5];
bool b[5000000];
int s[5000000];

void prejs(int x)
{
    js[0] = 1;
    for(int i = 1; i <= x; i ++)
        js[i] = js[i - 1] * 2;
    int cnt = 0;
    for(int i = 2; i <= 4500000; i ++)
    {
        s[++ cnt] = i;
        if(b[i] == 0)
        {
            for(int j = i + i; j <= 4500000; j += i)
                b[j] = 1;
        }
    }
}

int main()
{
    //freopen("dividing.in", "r", stdin);
    //freopen("dividing.out", "w", stdout);
    prejs(25);
    int T;
    cin >> T;
    while(T --)
    {
        int x, y, z, w;
        cin >> x >> y >> z >> w;
        int n = 0;
        n += js[x];
        n += js[y];
        n += js[z];
        n += js[w];
        int cnt = 0;
        while(n != 1)
        {
            cnt ++;
            ans[cnt][1] = n;
            if(b[n] == 0)
            {
                ans[cnt][2] = 1;
                ans[cnt][3] = n - 1;
            }
            else for(int i = 1; i <= 5000000; i ++)
            {
                int k = s[i];
                if(n % k == 0)
                {
                    ans[cnt][2] = n / k;
                    ans[cnt][3] = n / k * (k - 1);
                    break ;
                }
            }
            n = ans[cnt][3];
        }
        printf("%d\n", cnt);
        for(int i = 1; i <= cnt; i ++)
            printf("%d %d %d\n", ans[i][1], ans[i][2], ans[i][3]);
    }
    return 0;
}

