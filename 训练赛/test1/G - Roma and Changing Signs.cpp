#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int num[200100];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
//	sort(num+1,num+1+n);
	int pos = 0;
	for(int i = 1 ; i <= k ; i ++)
		if(num[i] > 0)
		{
			pos = i;
			break;
		}
	if(!pos || ((pos - 1) >= k))
		for(int i = 1 ; i <= k ; i ++)
			num[i] *= -1;
	else
	{
		if(pos == 1 && k % 2)
			num[1] *= -1;
		else if(pos == 1 && k % 2)
			;
		else
		{
			for(int i = 1 ; i < pos ; i ++)
				num[i] *= -1;
			k -= pos - 1;
			if(!k % 2)
				;
			else
			{
				if(num[pos-1] *-1 > num[pos])
					num[pos-1] *= -1 , num[pos] *= -1;
			}
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans += num[i];
	printf("%d\n",ans);
	return 0;
}

