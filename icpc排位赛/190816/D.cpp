#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[60];
int nex[60];
ll n, m, mod;

ll mul(ll a, ll b){
    ll c = a*b-(ll)((long double)a*b/mod+0.5)*mod;
    return c<0 ? c+mod : c;  //¾ÍÊÇËãµÄa*b%m;
}

class matrix
{
public:
    ll a[55][55];
    matrix() { memset(a, 0, sizeof(a)); }
    matrix operator * (const matrix &mat)
    {
        matrix ans;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < m; j ++)
                for(int k = 0; k < m; k ++)
                    ans.a[i][k] += mul(a[i][j], mat.a[j][k]),
                    ans.a[i][k] %= mod;
        return ans;
    }
};

void getNext()
{
    nex[0] = -1; int i = 1, j = -1;
    while(i <= m)
    {
        if(j == -1 || s[i] == s[j + 1])
            nex[i ++] = ++ j;
        else j = nex[j];
    }
}

int findx(int i, int x)
{
    while(i != -1 && s[i + 1] != x + 'a')
        i = nex[i];
    return i + 1;
}

matrix quick(matrix A, ll k){
	matrix B;
	for(int i = 0; i < m; i ++)
		B.a[i][i] = 1;
	while(k > 0)
	{
		if(k & 1) B = B * A;
		A = A * A;
		k = (k >> 1);
	}
	return B;
}

ll iquick(ll a, ll x)
{
    if(x == 1) return a;
    ll tmp = iquick(a, x / 2);
    if(x % 2 == 0) return mul(tmp, tmp);
    return mul(tmp, tmp) * a % mod;

}

int main()
{
    int T; cin >> T;
    while(T --)
    {
        cin >> n >> mod;
        cin >> s + 1; getNext();
        matrix tmp; m = strlen(s + 1);
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < 26; j ++)
                tmp.a[i][findx(i, j)] ++;
        tmp = quick(tmp, n);
        ll ans = iquick(26, n);
        for(int i = 0; i < m; i ++)
            ans -= tmp.a[0][i];
        ans %= mod, ans += mod, ans %= mod;
        cout << ans % mod << endl;
    }
}

/*
1
10
1000000000000
a

*/
