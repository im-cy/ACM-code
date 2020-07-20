#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ins[201];
char a[201],b[201];

bool check(int pos,int len)
{
	for(int i = pos ; i <= pos + len - 1 ; i ++)
	{
		if(ins[i] != a[i-pos])
			return false;
	}
	return true;
}

int main()
{
	scanf("%s",ins);
	int l = strlen(ins);
	int ans = l;
	for(int i = 1 ; i <= l ; i ++)//枚举长度 
	{
		for(int j = 0 ; j < l - i ; j ++)//起点
		{
			int tot = 0;
			for(int k = j ; k < j + i ; k ++)
				a[k-j] = ins[k];
			for(int k = 0 ; k < l ; k ++)
			{
				if(ins[k] == a[0])
				{
					if(check(k,i))
					{
						k += i - 1;
						tot ++;
					}
				}
			}
			ans = min(ans,l-tot*(i-1)+i);
		}
	}
	printf("%d\n",ans);
	return 0;
}

