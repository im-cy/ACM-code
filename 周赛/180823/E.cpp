#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod = 1e8 + 7;
const int sz = 200010;
int num[sz];
int cut[sz];
char str[sz];
int main()
{
	int T;
	cin >> T;
	getchar();
	while(T --)
	{
		memset(cut,0,sizeof(cut));
		memset(num,0,sizeof(num));
		memset(str,0,sizeof(str));
		gets(str);
		int n = strlen(str);
		long long sum = 0;
		for(int i = 1 ; i <= n ; i ++)
			num[i] = str[i-1] - '0';
		for(int i = 0 ; i <= num[1] ; i ++)
		{
			long long count = 1;
			if(i > 2)
				break;
			cut[1] = i;
			bool is_true = 1;
			int j = 2;
			for(j = 2 ; j <= n ; j ++)
			{
				cut[j] = num[j-1] - cut[j-1] - cut[j-2];
				if(cut[j] > 2 || cut[j] < 0)
				{
					is_true = 0;
					break;
				}
			}
			if(j == n + 1 && cut[n] + cut[n-1] != num[n])
				is_true = 0;
			if(is_true)
			{
				for(j = 1 ; j <= n ; j ++)
				{
					if(cut[i] == 1)
						count = (2 * count) % mod;
				}
				sum += count;
				sum %= mod;
			}
		}
		cout << sum % mod << endl;
	}
	return 0;
}
