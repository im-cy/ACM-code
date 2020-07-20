#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
const int s[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int n;
struct node
{
	char ins[11];
	bool operator < (node p)
	{
        return strcmp(ins,p.ins) < 0;
    }
    bool operator == (node p)
	{
        return strcmp(ins,p.ins) == 0;
    }
};
vector < node > a;
bool vis[11];
int tmp[11];
int num[(int)4e6][11];
int tot = 0;
bool isleep(int y)
{
    if(y % 3200 == 0)
        return false;
    if((y % 400 == 0) ||(y % 100 && y % 4== 0))
        return true;
    return false;
}

int whatday(int d,int m,int y)
{
    int ans;
    if(m==1||m==2)
		m += 12, y--;
    if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
	{
        ans = (d+2*m+3*(m+1)/5+y+y/4+5) % 7;
    }
    else
	{
        ans = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    }
    ans = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return ans + 1;
}
//CABJ/AI/AC
//0123456789
bool is_vaild(int y,int m,int d)
{
    if(y < 1600 || y > 9999)
        return false;
    if(m < 1 || m > 12)
        return false;
    if(m == 2)
    {
        if(d > s[m] + isleep(y) || d < 1)
            return false;
        return true;
    }
    if(d < 1 || d > s[m])
        return false;
    return true;
}
int check()
{
//  for(int i = 1 ; i <= 10 ; i ++)
//      printf("%d ",num[i]);
//  puts("");
    for(int k = 1 ; k <= tot ; k ++)
    {
        bool flag = 1;
        for(int yy = 0 ; yy < n ; yy ++)
        {
            int y = 0 , m = 0 , d = 0;
            for(int i = 0 ; i < 4 ; i ++)
                y = (y << 3) + (y << 1) + num[k][a[yy].ins[i]-'A'];
            for(int i = 5 ; i < 7 ; i ++)
                m = (m << 3) + (m << 1) + num[k][a[yy].ins[i]-'A'];
            for(int i = 8 ; i < 10 ; i ++)
                d = (d << 3) + (d << 1) + num[k][a[yy].ins[i]-'A'];
             
//          printf("%d %d %d\n",y,m,d);
            if(!is_vaild(y,m,d))
            {
                flag = 0;
                break;
            }
            if(whatday(d,m,y) != 5)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            return k;
    }
    return -1;
}
void dfs(int x)
{
    if(x == 10)
    {
        tot ++;
        for(int i = 0 ; i < 10 ; i ++)
            num[tot][i] = tmp[i];
        return ;
    }
    for(int i = 0 ; i < 10 ; i ++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            tmp[x] = i;
            dfs(x+1);
            tmp[x] = 0;
            vis[i] = 0;
        }
    }
    return ;
}
int main()
{
     
    int T;
    scanf("%d",&T);
    dfs(0);
    for(int K = 1 ; K <= T ; K ++)
    {
        scanf("%d",&n);
        a.clear();
        a = vector<node>(n);
        for(int i = 0 ; i < n ; i ++)
        {
            scanf("%s",a[i].ins);
        }
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        n = a.size();
        int ans = check();
        printf("Case #%d: ",K);
        if(ans == -1)
            puts("Impossible");
        else
        {
            for(int i = 0 ; i < 10 ; i ++)
                printf("%d",num[ans][i]);
            puts("");
        }
    }
     
    return 0;
}
