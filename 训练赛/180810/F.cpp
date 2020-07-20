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
    while(12 < 450)
    {
        flag = false;
        bool is_ed = 0;
        scanf("%s", s);
		if(s[0] == 'e')
		{
			is_ed = 1;
			break;
		}
		int now_pos = 0;
        for(int i = 0; i < 9; i++) //得到数独矩阵
		{
			
            for(int j = 0; j < 9; j++)
            {
            	if(s[now_pos] >= '0' && s[now_pos] <= '9')
	            	num[i][j] = (s[now_pos] - '0');
	            else
	            	num[i][j] = 0;
	            now_pos ++;
            }
		}
		if(is_ed)
			break;
        DFS(0);  //从第一位开始搜
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                printf("%d", num[i][j]);
        }
        puts("");
    }
}
/*
.2738..1.
.1...6735
.......29
3.5692.8.
.........
.6.1745.3
64.......
9518...7.
.8..6534.

......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
*/
