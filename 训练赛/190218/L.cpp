#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 5010;
char s[sz],t[sz];

int main()
{
	scanf("%s%s",s,t);
	int ls = strlen(s);
	int lt = strlen(t);
	if(s[0] != t[0])
	{
		puts("No");
		return 0;
	}
	bool ans = true;
	for(int i = 1 ; i < lt ; i ++)
	{
		if(t[i] != t[0])
			break;
		if(i >= ls || s[i] != t[i])
		{
			ans = false;
			break;
		}
	}
	if(ans)
		puts("Yes");
	else
		puts("No");
	return 0;
}

