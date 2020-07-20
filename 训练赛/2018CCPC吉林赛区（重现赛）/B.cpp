#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map < string , int > mp;
int main()
{
	int T;
	scanf("%d",&T);
	mp["Beijing"] = 8;
	mp["Washington"] = -5;
	mp["London"] = 0;
	mp["Moscow"] = 3;
	int k = 1;
	while(T --)
	{
		
		int h,m;
		string t,s1,s2;
		scanf("%d:%d",&h,&m);
		cin >> t >> s1 >> s2;
		if(t[0] == 'P' && h != 12)
			h += 12;
		else if(t[0] == 'A' && h == 12)
			h -= 12;
		h += mp[s2] - mp[s1];
		printf("Case %d: ",k ++);
		if(h < 0)
		{
			h += 24;
			printf("Yesterday ");
		}
		else if(h >= 24)
		{
			h -= 24;
			printf("Tomorrow ");
		}
		else
		{
			printf("Today ");
		}
		if(h >= 12)
		{
			h -= 12;
			if(h == 0)
				h += 12;
			printf("%d:%02d PM\n",h,m);
		}
		else
		{
			if(h == 0)
				h += 12;
			printf("%d:%02d AM\n",h,m);
		}
	}
	
	return 0;
}

