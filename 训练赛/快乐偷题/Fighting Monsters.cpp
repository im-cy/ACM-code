#include <iostream>
#include <cstdio>
using namespace std;
int fib[100];
int ans[100];
int main()
{
    int n, x;
    fib[1] = fib[2] = 1;
    for(int i = 3; i <= 36; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &x);
        for(int j = 1; j <= 36; j ++)
            if(fib[j] == x && ans[j] == 0)
            {
                ans[j] = i;
                break ;
            }
    }
    for(int i = 1; i <= 35; i ++)
        if(ans[i] && ans[i + 1])
        {
            cout << ans[i] << " " << ans[i + 1];
            return 0;
        }
    cout << "impossible" << endl;
    return 0;
}

