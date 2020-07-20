#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int b[100000];

int main()
{
//    freopen("defense.in", "r", stdin);
//    freopen("defense.out", "w", stdout);
    int n, h, w;
    scanf("%d%d%d", &h, &w, &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d%d", &a[i], &b[i]);
    a[n + 1] = 0;
    a[n + 2] = h + 1;
    b[n + 1] = 0;
    b[n + 2] = w + 1;
    n += 2;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ansX = 0, ansY = 0;
    for(int i = 1; i < n; i ++)
    {
        if(a[i + 1] - a[i] > 1)
            ansX ++;
        if(b[i + 1] - b[i] > 1)
            ansY ++;
    }
    cout << ansX * ansY << endl;
}
