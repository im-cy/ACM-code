#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
map < string , int > mp;
int T[11];
int main()
{
	mp["red"] = 1;mp["yellow"] = 2;mp["green"] = 3;mp["brown"] = 4;mp["blue"] = 5;mp["pink"] = 6;mp["black"] = 7;
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		string col;
		cin >> col;
		T[mp[col]] ++;
	}
	int sum = 0;
	for(int i = 2 ; i <= 7 ; i ++)
		sum += T[i];
	if(sum != 0)
	{
		int ans = 0;
		int now;
		for(int i = 7 ; i >= 2 ; i --)
			if(T[i])
			{
				now = i;
				break;
			}
		ans += (T[1]) * (1 + now);
		for(int i = 2 ; i <= 7 ; i ++)
			ans += T[i] * i;
		printf("%d\n",ans);
	}
	else
	{
		puts("1");
	}
	return 0;
}
/*
5
red
black
pink
red
red

*/

