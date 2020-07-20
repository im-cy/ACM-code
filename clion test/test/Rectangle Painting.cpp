#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 57;

int f[N][N][N][N];
char s[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    memset(f, INF, sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j][i][j] = (s[i][j] == '#');
    for (int i = n; i >= 1; i--)
        for (int j = n; j >= 1; j--)
            for (int i1 = i; i1 <= n; i1++)
                for (int j1 = j; j1 <= n; j1++)
                {
                    f[i][j][i1][j1] = min(f[i][j][i1][j1], max(i1 - i + 1, j1 - j + 1));
                    for (int k = i + 1; k <= i1; k++)
                        f[i][j][i1][j1] = min(f[i][j][i1][j1], f[i][j][k - 1][j1] + f[k][j][i1][j1]);
                    for (int k = j + 1; k <= j1; k++)
                        f[i][j][i1][j1] = min(f[i][j][i1][j1], f[i][j][i1][k - 1] + f[i][k][i1][j1]);
                }
    printf("%d", f[1][1][n][n]);
    return 0;
}