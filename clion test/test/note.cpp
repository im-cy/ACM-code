#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l , r;
    while(r - l > 1)
    {
        int mid = l + r >> 1;
        int mmid = r + mid >> 1;
        if(calc(mid) < calc(mmid))
            r = mmid;
        else
            l = mid;
    }
    return 0;
}


