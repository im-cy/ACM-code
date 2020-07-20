#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int sz = 200010;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int read()
{
	int x = 0;
	int f = 1;
	char in = getchar();
	while(in < '0' || in > '9')
	{
		if(in == '-')
			f = -1;
		in = getchar();
	}
	while(in >= '0' && in <= '9')
	{
		x = (x << 3) + (x << 1) + in - '0';
		in = getchar();
	}
	return x * f;
}
bool room[11];
char ins[200100];
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",ins);
	for(int i = 0 ; i < n ; i ++)
	{
		if(ins[i] == 'L')
		{
			for(int j = 0 ; j <= 9 ; j ++)
				if(!room[j])
				{
					room[j] = 1;
					break;
				}
		}
		else if(ins[i] == 'R')
		{
			for(int j = 9 ; j >= 0 ; j --)
				if(!room[j])
				{
					room[j] = 1;
					break;
				}
		}
		else
		{
			int x = ins[i] - '0';
			room[x] = 0;
		}
	}
	for(int i = 0 ; i <= 9 ; i ++)
		printf("%d",room[i]);
	puts("");
	return 0;
}

