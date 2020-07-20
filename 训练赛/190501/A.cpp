#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long ans[1000];
int main()
{
    string n;
    while(cin >> n)
    {
        if(n.length() == 1 && n[0] == '0')
            return 0;
        memset(ans, 0, sizeof(ans));
        ans[0] = ans[1] = 1;
        int l = n.length();
        for(int i = 1; i < l; i ++)
        {
            ans[i + 1] += ans[i];
            int tmp = (n[i - 1] - '0') * 10 + n[i] - '0';
            if(tmp <= 26) ans[i + 1] += ans[i - 1];
        }
        cout << ans[l] << endl;
    }
    return 0;
}
