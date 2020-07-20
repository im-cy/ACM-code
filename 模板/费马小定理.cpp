#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int mod = 1000000007;
ll ksm(ll x,ll p)
{
    if(p == 0)
        return 1;
    if(p == 1)
        return x % mod;
    if(p == 2)
        return ((x%mod) * (x%mod))%mod;
    int temp = ksm(x,p/2) % mod;
    if(p % 2 == 1)
        return (((temp * temp) % mod) * (x%mod));
    if(p % 2 == 0)
        return (temp * temp) % mod;
}
int get(int a)
{
    return ksm(a,mod-2);
}
int main()
{

    return 0;
}
