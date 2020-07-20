#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<map>
#define ll long long
using namespace std;
const int sz = 200010;
ll a[sz],b[sz],d[sz];
map < ll , bool > mp;
int n;
int main()
{
	srand(time(0));
	scanf("%d",&n);
	int m = 0;
	for(int i = 1 ; i <= n ; i ++)
		scanf("%lld",&a[i]);
	for(int i = 2 ; i <= n ; i ++)
	{
		if(mp[a[i]-a[i-1]] == 0)
			d[++m] = a[i] - a[i-1];
	//	if(mp[a[i-1]-a[i]] == 0)
	//		d[++m] = a[i] - a[i-1];
	}
	for(int i = 3 ; i <= n ; i ++)
	{
		if(mp[(a[i]-a[i-2]) / 2] == 0 && (a[i] - a[i-2]) % 2 == 0)
			d[++m] = (a[i] - a[i-2]) / 2;
	//	if(mp[a[i-2]-a[i]] == 0)
	//		d[++m] = a[i] - a[i-2];
	}
	bool is_find = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		int t = 300000 / n;
		while(t --)
		{
			int cut = 0;
			int pos = (rand() * rand()) % n + 1;
			for(int j = 1 ; j <= n ; j ++)
				b[j] = a[j];
			for(int j = pos - 1 ; j >= 1 ; j --)
				if(b[j+1] - b[j] != d[i])
				{
					b[j] = b[j+1] - d[i];
					cut ++;
				}
			for(int j = pos + 1 ; j <= n ; j ++)
				if(b[j] - b[j-1] != d[i])
				{
					b[j] = b[j-1] + d[i];
					cut ++;
				}
			if(cut <= 3)
			{
				is_find = 1;
				break;
			}
		}
		if(is_find)
			break;
	}
	for(int i = 1 ; i <= n ; i ++)
		printf("%lld ",b[i]);
	return 0;
}
 
