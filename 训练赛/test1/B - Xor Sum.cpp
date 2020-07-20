#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int ans;
	scanf("%d",&ans);
	for(int i = 2 ; i <= n ; i ++)
	{
		int temp;
		scanf("%d",&temp);
		ans ^= temp;
	}
	printf("%d\n",ans);
	return 0;
}

