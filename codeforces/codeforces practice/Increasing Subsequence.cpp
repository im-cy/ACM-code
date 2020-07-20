#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 200010;
int num[sz];
bool ans[sz];;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
	int l = 1 , r = n;
	int now = 0;
	int cnt = 0;
	while(r - l > 1)
	{
		if(num[l] <= now && num[r] <= now)
			break;
		else
		{
			cnt ++;
			if(num[l] > now && num[r] > now)
			{
				if(num[l] <= num[r])
				{
					now = num[l];
					l ++;
				}
				else
				{
					now = num[r];
					r --;
					ans[cnt] = 1;
				}
			}
			else if(num[l] > now)
			{
				now = num[l];
				l ++;
			}
			else
			{
				now = num[r];
				r --;
				ans[cnt] = 1;
			}
		}
	}
	printf("%d\n",cnt);
	for(int i = 1 ; i <= n ; i ++)
	{
		if(ans[i])
			printf("R");
		else
			printf("L");
	}
	puts("");
	return 0;
}

