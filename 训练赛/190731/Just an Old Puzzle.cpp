#include<bits/stdc++.h>
using namespace std;
const int sz = 21;
int x[sz],y[sz];
bool check()
{
	for(int i = 1 ; i <= 3 ; i ++)
		if(y[i] > y[i+1])
			return false;
	for(int i = 5 ; i <= 7 ; i ++)
		if(y[i] > y[i+1])
			return false;
	for(int i = 9 ; i <= 11 ; i ++)
		if(y[i] > y[i+1])
			return false;
	for(int i = 13 ; i <= 14 ; i ++)
		if(y[i] > y[i+1])
			return false;
	return true;
}
int main()
{
	
	int T;
	scanf("%d",&T);
	while(T --)
	{
		for(int i = 1 ; i <= 4 ; i ++)
		{
			for(int j = 1 ; j <= 4 ; j ++)
			{
				int z;
				scanf("%d",&z);
				x[z] = i;
				y[z] = j;
			}
		}
		bool ans = check();
		if(ans)
			puts("Yes");
		else
			puts("No");
	}
}



