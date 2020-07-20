#include<iostream>
#include<cstdio>
using namespace std;
const int sz = 200010;
int num[sz];
int main()
{
	int n;
	scanf("%d",&n);
	int ans = 0 , ansnum = 214748364;
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%d",&num[i]);
	}
	int H;
	scanf("%d",&H);
	for(int i = 1 ; i <= n ; i ++)
	{
		if(H % num[i] < ansnum)
		{
			ansnum = H % num[i];
			ans = num[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
