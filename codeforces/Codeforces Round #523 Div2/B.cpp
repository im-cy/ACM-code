#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll num[200010];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int now = 1;
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		scanf("%I64d",&num[i]);
	sort(num+1,num+n+1);
	for(int i = 1 ; i < n ; i ++)
		ans += num[i] - 1;
	for(int i = 1 ; i < n ; i ++)
	{
		if(num[i] >= now && now < num[n])
		{
			ans ++;
			now ++;
		}
	}
	cout << ans << endl;
	return 0;
}
 
