#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	int k = 1;
	scanf("%d",&T);
	while(T --)
	{
		int n;
		scanf("%d",&n);
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			int num;
			scanf("%d",&num);
			if(((i%3) == 0 && (i%2) == 0) || ((i%3) == 2))
				ans ^= num;
		}
		printf("Case %d: ",k ++);
		if(ans)
			puts("Alice");
		else
			puts("Bob");
	}
	return 0;
}

