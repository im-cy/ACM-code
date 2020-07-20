#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int sz = 2000100;
char s1[sz],s2[sz],s3[sz];
int t1[31],t2[31];
int n,t;
int main()
{
	
	while(scanf("%d%d\n",&n,&t) != EOF)
	{
		scanf("%s%s",s1,s2);
		for(int i = 0 ; i < n ; i ++)
			t1[s1[i]-'a'] ++ , t2[s2[i]-'a'] ++;
		int dif = 0;
		for(int i = 0 ; i < 26 ; i ++)
			dif += abs(t1[i] - t2[i]);
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
			for(int i = 0 ; i < n ; i ++)
				printf("%c",s3[i]);
			puts("");
		}
	}
	return 0;
}


