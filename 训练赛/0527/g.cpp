#include<iostream>
#include<cstdio>
using namespace std;
int num[400100];
int t[400100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]) , t[num[i]] = i;
	int ans = 1;
	int temp = 1;
	for(int i = 2 ; i <= n ; i ++)
	{
		if(t[i] > t[i-1])
			temp ++;
		else
		{
			ans = max(ans,temp);
			temp = 1;
		}
	}
	ans = max(ans,temp); 
	printf("%d\n",n-ans);
	return 0;
}




