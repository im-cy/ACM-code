#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int sz = 200100;
deque < int > q; // slf
int n,m;
int head[sz],nxt[sz],dist[sz];
struct gtnd
{
    int t,d;
}l[sz];
int tot = 1;
bool use[sz];
int pre[sz];//��¼·��
int tim[sz];//�и��� 
void build(int f,int t,int d)
{
    l[tot].t = t;
    l[tot].d = d;
    nxt[tot] = head[f];
    head[f] = tot ++;
}
int spfa(int s,int e)//�� s ��ĵ�Դ���· �� ����ֵ�� s �� e �����· 
{
    for(int i = 1 ; i <= n ; i ++)
        dist[i] = 2147483641;
    dist[s] = 0;
    use[s] = 1;
    q.push_front(s);
    while(!q.empty())
    {
        int f = q.front();
        q.pop_front();
        use[f] = 0;
        for(int i = head[f] ; i ; i = nxt[i])
        {
            int t = l[i].t;
            if(dist[t] > dist[f] + l[i].d)
            {
                dist[t] = dist[f] + l[i].d;
                tim[t] = tim[f] + 1;
                if(tim[t] > n)
                    return -1;
                pre[t] = f;
                if(!use[t])
                {
                    use[t] = 1;
                    if(!q.empty())
                    {
                        if(dist[t] < dist[q.front()])
                            q.push_front(t);
                        else
                            q.push_back(t);
                    }
                    else
                        q.push_back(t);
                }
            }
        }
    }
    return dist[e];
}
void print_path(int u) // ��ӡ·�� 
{
    printf("%d ",u);
    if(pre[u])
        print_path(pre[u]);
}
int main()
{

    return 0;
}
