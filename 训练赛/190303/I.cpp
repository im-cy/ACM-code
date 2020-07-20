#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;
const int sz = 5010;
bool mp[sz][sz];
char path[sz];
char q[sz];
int n,m;
int T = 0;
int get_numb(int number,int x)
{
	return (number - 1) * 9 + x;
}
pair<int,int> find_next(int number,int x,pair<int,int> last)
{
	for(int i = 1 ; i <= n*m ; i ++)
	{
		for(int j = 1 ; j <= 8 ; j ++)
			if(mp[get_numb(number,x)][get_numb(i,j)] && last != make_pair(i,j))
				return make_pair(i,j);
	}
	return make_pair(-1,-1);
}
void find(int number,int x)
{
	pair<int,int> fa = make_pair(0,0);
	pair<int,int> cur = find_next(number,x,fa);
	while(cur.first != -1)
	{
		fa.first = number;
		fa.second = x;
		number = cur.first;
		x = cur.second;
	//	printf("##%d%c\n",number,x+'A'-1);
		cur = find_next(number,x,fa);
	}
	printf("%d%c\n",number,x+'A'-1);
}


int main()
{
	while(scanf("%d%d",&n,&m) && (n || m))
	{
		memset(mp,0,sizeof(mp));
		T ++;
		printf("Board %d:\n",T);
		int number;
		while(scanf("%d",&number) && number)
		{
			getchar();
			gets(path);
			int len = strlen(path);
			for(int i = 0 ; i < len ; i += 3)
			{
				path[i] -= 'A' - 1;
				path[i+1] -= 'A' - 1;
				mp[get_numb(number,path[i])][get_numb(number,path[i+1])] = 1;
				mp[get_numb(number,path[i+1])][get_numb(number,path[i])] = 1;
			}
		}
		for(int i = 1 ; i <= n * m ; i ++)
		{
			if(i % m != 0)
			{
				mp[get_numb(i,3)][get_numb(i+1,8)] = 1;
				mp[get_numb(i+1,8)][get_numb(i,3)] = 1;
				mp[get_numb(i,4)][get_numb(i+1,7)] = 1;
				mp[get_numb(i+1,7)][get_numb(i,4)] = 1;
			}
		}
		for(int i = 1 ; i <= (n-1)*m ; i ++)
		{
			mp[get_numb(i,6)][get_numb(i+m,1)] = 1;
			mp[get_numb(i+m,1)][get_numb(i,6)] = 1;
			mp[get_numb(i,5)][get_numb(i+m,2)] = 1;
			mp[get_numb(i+m,2)][get_numb(i,5)] = 1;
		}
		getchar();
		gets(q);
		int l = strlen(q);
		for(int i = 0 ; i < l ; i += 2)
		{
			int x = 0;
			while(q[i] >= '0' && q[i] <= '9')
			{
				x = x * 10 + q[i] - '0';
				i ++;
			}
			printf("%d%c is connected to ",x,q[i]);
			find(x,q[i]-'A'+1);
		}
		puts("");
	}
	return 0;
}
/*
2 3
4 AG BF
3 AF EH
6 AC BF
1 AH CE DF
2 AG CH
0
1A 2A 3A 4F
*/
