#include <bits/stdc++.h>
using namespace std;
char s[1005]; int mod;

struct bigNum
{
    bool isNum;
    int a[1005];
    bigNum()
    {
        isNum = false;
        memset(a, 0, sizeof(a));
    }
}ans;

bigNum solve()
{
    cerr << "solve()" << endl;
    int need = 0, len;
    for(int i = 1; i ; i ++)
    {
        if(s[i] == 0) break ;
        if(s[i] >= '0' && s[i] <= '9')
        {
            need = need * 10 + s[i] - '0';
            need %= mod; len = i;
        }
    }
    need = (mod - need) % mod;
    bigNum dp[1005]; int base = 1;
    dp[0].isNum = true;
    for(int i = len; i > 0; i --)
    {
        if(s[i] == '?')
        {
            for(int j = 0; j < mod; j ++)
                if(dp[j].isNum == true)
                    for(int k = 0; k <= 9; k ++)
                    {
                        int tmp = (base * k + j) % mod;
                        if(dp[tmp].isNum == false)
                        {
                            dp[tmp] = dp[j];
                            dp[tmp].a[i] = k;
                        }
                    }
        }
        if(dp[need].isNum == true) return dp[need];
        base = base * 10 % mod;
    }
    return dp[need];
}

int main()
{
    cin >> s + 1; cin >> mod;
    if(s[1] != '?') ans = solve();
    else
    {
        for(int i = '1'; i <= '9'; i ++)
        {
            s[1] = i; ans = solve();
            if(ans.isNum == true) break;
        }
    }
    if(ans.isNum == false) cout << "*";
    else
    {
        for(int i = 1; i ; i ++)
        {
            if(s[i] == 0) break;
            if(s[i] == '?') cout << s[i];
            else cout << ans.a[i];
        }
    }
    return 0;
}
