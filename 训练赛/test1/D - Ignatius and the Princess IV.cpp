#include<iostream>
#include<cstdio>
using namespace std;
int n;
int now,now_time;

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		scanf("%d",&now);
		now_time = 1;
		for(int i = 2 ; i <= n ; i ++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp == now)
				now_time ++;
			else
				now_time --;
			if(!now_time)
				now = temp , now_time = 1;
		}
		printf("%d\n",now);	
	}
	return 0;
}

