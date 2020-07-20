#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int num[200100];


bool check(int mid)
{
	int now = 0;
	for(int i = 1 ; i <= n ; i ++)
		now += (upper_bound(num + i + 1 , num + n + 1 , num[i] + mid) - 1 - (num + i));
	return now >= m;
}

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		m = n * (n - 1) / 2;
		if(m % 2)
			m = m / 2 + 1;
		else
			m /= 2;
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&num[i]);
		sort(num+1,num+n+1);
		int l = 0 , r = num[n] + 1;
		while(r - l > 1)
		{
			int mid = l + r >> 1;
			if(check(mid))
				r = mid;
			else
				l = mid;
		}
		printf("%d\n",r);
	}
	
	return 0;
}

