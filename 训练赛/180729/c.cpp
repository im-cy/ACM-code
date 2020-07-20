#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int sz = 2001000;
int n,m;
int num[sz];
int sum[sz];
bool check(int k,int l,int r)
{
	while(r - l > 1)
	{
		int mid = l + r >> 1;
		if(sum[mid] <= k)
			l = mid;
		else
			r = mid;
	}
	if(sum[l] == k || sum[r] == k)
		return true;
	return false;
}
void work()
{
	for(int i = n ; i >= 1 ; i --)//d
		for(int j = n ; j >= 1 ; j --)//c
			if(i != j)
			{
				int l = 1, r = j;
           		while(r - l > 1)
				{
                	if(num[l] + num[r] == num[i] - num[j])
					{
                    	printf("%d\n",num[i]);
                    	return ;
                	}
					else if(num[l] + num[r] <= num[i] - num[j])
                    	l ++;
					else
	                    r --;
          		}
			}
	puts("no solution");
	return ;
}
int main()
{
	while(scanf("%d",&n) != EOF && n)
	{
		for(int i = 1 ; i <= n ; i ++)
			scanf("%d",&num[i]);
		sort(num+1,num+n+1);
		work();
	}
	return 0;
}
