#include <iostream>
using namespace std;

long long js(long long x)
{
    float p = (float) x * x;
    p = p / 12.0;
    return p + 0.5;
}

long long bin(long long x)
{
    long long l = 3, r = 1100000000ll;
    while(r - l > 1ll)
    {
        long long mid = (l + r) / 2;
        if(js(mid) >= x)
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main()
{
    long long L, R;
    cin >> L >> R;
    int l = bin(L), r = bin(R);
    for(long long i = min(3, l - 5); i <= (l + 5); i ++)
    {
        if(js(i) >= L)
        {
            l = i;
            break ;
        }
    }
    for(long long i = r + 5; i >= min(3, r - 5); i --)
    {
        if(js(i) <= R)
        {
            r = i;
            break ;
        }
    }
    cout << r - l + 1 << endl;
    return 0;
}

