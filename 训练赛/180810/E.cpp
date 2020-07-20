#include<cstdio>
#include<iostream>
using namespace std;
char s[10];
int num[9][9];
bool flag;
bool ok(int n, int cur) 
{
    int r = n / 9;		//��ǰ��
	int c = n % 9;		//��ǰ��
    for(int j = 0; j < 9; j++)  //ö����
        if (num[r][j] == cur) 
            return false;
    for(int i = 0; i < 9; i++)  //ö����
        if (num[i][c] == cur) 
            return false;
	//�õ���ǰ���ڵ��Ӿ���ĵ�һ��Ԫ��λ��
    int x = r / 3 * 3;	
    int y = c / 3 * 3;
	//ö���Ӿ����е�Ԫ��
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
	if(num[n / 9][n % 9])//��ǰλ��������ֱ��������һλ
	{
        DFS(n + 1);
		if(flag)
			return;
	}
    else
    {
        for(int cur = 1; cur <= 9; cur++)  //ö������
        {
            if(ok(n, cur)) //��ok�����
            {
                num[n / 9][n % 9] = cur; 
                DFS(n + 1);
                if(flag) 
                    return;
                num[n / 9][n % 9] = 0; //��ԭ
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
        for(int i = 0; i < 9; i++) //�õ���������
		{
			scanf("%s", s);
            for(int j = 0; j < 9; j++)
                num[i][j] = (s[j] - '0');
		}
        DFS(0);  //�ӵ�һλ��ʼ��
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
                printf("%d", num[i][j]);
            printf("\n");      
        }
        puts("");
    }
}
