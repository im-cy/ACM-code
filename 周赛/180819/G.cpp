#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 245;
int f[sz][sz];
char s[200100];
char t[200100];
int main()
{
	int n = 126;
	scanf("%s%s",s,t);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			f[i][j] = 214748364;
	for(int i = 1 ; i <= n ; i ++)
		f[i][i] = 0;
	int m;
	scanf("%d",&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		char a,b;
		int d;
		cin >> a >> b >> d;
		int aa = a , bb = b;
		f[aa][bb] = min(d,f[aa][bb]);
	}
	for(int k = 1 ; k <= n ; k ++)
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= n ; j ++)
                f[i][j] = min(f[i][j],f[i][k] + f[k][j]);
    long long ans = 0;
    int l = strlen(s);
	for(int i = 0 ; i < l ; i ++)
	{
			 
		ans += f[s[i]][t[i]];
	}
	if(ans >= 214748364)
		puts("-1");
	else
		cout << ans << endl;
   	return 0;
}

 
