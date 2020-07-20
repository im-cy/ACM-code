/*
x % 4 == 0  -> sg[x] = x-1;
x % 4 == 1 or 2 -> sg[x] = x;
x % 4 == 3 -> sg[x] = x+1;
*/
#include<bits/stdc++.h>
using namespace std;
int getsg(int num)
{
	if(num % 4 == 0)
		return num - 1;
	if(num % 4 == 3)
		return num + 1;
	return num;
}

int main()
{
	int T;
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
			ans ^= getsg(num);
		}
		if(ans)
			puts("Alice");
		else
			puts("Bob");
	}
	
	return 0;
}

