#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("input.txt","w",stdout);
	srand(time(0));
	puts("1");
	int n = rand() % 5 + 2;
	int m = rand() % 10;
	while(m < n - 1)
		m = rand() % 10;
	printf("%d %d\n",n,m);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f = rand() % n + 1;
		int t = rand() % n + 1;
		while(t == f)
		{
			t = rand() % n + 1;
		}
		int d = rand() % 20;
		printf("%d %d %d\n",f,t,d);
	}
	return 0;
}

