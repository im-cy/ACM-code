#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-12;
double r1, r2, h, f, mins;

long double getS(long double tmpr, int x)
{
    long double s = h / f;
    s *= 2.00 * tan(pi / x) * tmpr;
    return s;
}

long double calc(long double tmpr)
{
    int l = 3, r = 1000000000;
    while(l < r)
    {
        int mid = (l + r) / 2 + 1;
        if(getS(tmpr, mid) - mins > eps) l = mid;
        else r = mid - 1;
    }
    // cout << l << endl;
    return getS(tmpr, l) * l;
}

int main()
{
    while(scanf("%lf", &r1) != EOF)
    {
        scanf("%lf%lf%lf%lf", &r2, &h, &f, &mins);
        long double tmpr = r1, ans = 0;
        for(int i = 1; i <= f; i ++)
        {
            tmpr -= (r1 - r2) / (f);
            ans += calc(tmpr);
        }
        double x = ans;
        printf("%.3f\n", x);
    }
    return 0;
}
