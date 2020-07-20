#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    long long a, b, c, d;
    cin >> T;
    while(T --)
    {
        cin >> a >> b >> c >> d;
        if(a < b || d < b)
        {
            puts("No");
            continue ;
        }
        if(d >= b && c >= b)
        {
            puts("Yes");
            continue ;
        }
        int fuck = 0;
        while(233)
        {
            fuck ++;
            if(a < b)
            {
                break ;
            }
            a %= b;
            if(a > c)
                break ;
            a += d;
            if(fuck == 10000000)
            {
                break ;
            }
        }
        if(fuck == 10000000)
            puts("Yes");
        else
            puts("No");
    }
}

