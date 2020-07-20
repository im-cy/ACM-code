#include<cstdio>
#include<iostream>
using namespace std;
char s[10];
int num[9][9];
bool flag;
bool ok(int n, int cur) 
{
    int r = n / 9;		//当前行
	int c = n % 9;		//当前列
    for(int j = 0; j < 9; j++)  //枚举列
        if (num[r][j] == cur) 
            return false;
    for(int i = 0; i < 9; i++)  //枚举行
        if (num[i][c] == cur) 
            return false;
	//得到当前所在的子矩阵的第一个元素位置
    int x = r / 3 * 3;	
    int y = c / 3 * 3;
	//枚举子矩阵中的元素
    for(int i = x; i < x + 3; i++)
        for(int j = y; j < y + 3; j++)
            if (num[i][j] == cur) 
                return false;
    return true;
}
void DFS(int n)
{
    if(n > 80 || flag) 
    {
        flag = true;
        return;
    }
	if(num[n / 9][n % 9])//当前位置有数字直接搜索下一位
	{
        DFS(n + 1);
		if(flag)
			return;
	}
    else
    {
        for(int cur = 1; cur <= 9; cur++)  //枚举数字
        {
            if(ok(n, cur)) //若ok则插入
            {
                num[n / 9][n % 9] = cur; 
                DFS(n + 1);
                if(flag) 
                    return;
                num[n / 9][n % 9] = 0; //还原
            }
        }
    }
}
int main()
{   
    int T;
    scanf("%d", &T);
    int k = 0;
    while(T--)
    {
    	k ++;
    	printf("Scenario #%d:\n",k);
        flag = false;
        for(int i = 0; i < 9; i++) //得到数独矩阵
		{
			scanf("%s", s);
            for(int j = 0; j < 9; j++)
                num[i][j] = (s[j] - '0');
		}
        DFS(0);  //从第一位开始搜
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                printf("%d", num[i][j]);
            printf("\n");      
        }
        puts("");
    }
}
