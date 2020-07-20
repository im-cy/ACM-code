#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 2000100;
char s1[sz],s2[sz],s3[sz];
int n,t;
int f(const char *str1,const char * str2)
{
	int ans = 0;
	for(int i = 0 ; i < n ; i ++)
		if(str1[i] != str2[i])
			ans ++;
	return ans;
}
int main()
{	
	scanf("%d%d\n",&n,&t);
	scanf("%s%s",s1,s2);
	int dif = f(s1,s2);
	int temp = t;
	if(dif > t)
		puts("-1");
	else
	{
		t -= dif;
		for(int i = 0 ; i < n ; i ++)
		{
			if(s1[i] != s2[i])
			{
				for(int j = 0 ; j < 26 ; j ++)
				{
					char ans = j + 'a';
					if(ans != s1[i] && ans != s2[i])
					{
						s3[i] = ans;
						break;
					}
				}
			}
			else if(t > 0)
			{
				for(int j = 0 ; j < 26 ; j ++)
				{
					char ans = j + 'a';
					if(ans != s1[i])
					{
						s3[i] = ans;
						break;
					}
				}
				t --;
			}
			else
				s3[i] = s1[i];
		}
		if(f(s1,s3) == temp && f(s2,s3) == temp)
		{
			for(int i = 0 ; i < n ; i ++)
				printf("%c",s3[i]);
			puts("");
		}
		else
			puts("-1");			
	}
	return 0;
}


