#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 400100;
const int sz0 = 200100;
struct node
{
	short t;
	int d;
};
vector <node> l[sz];
vector <short> pos[sz0];
map <short,short> mp[sz0];
void build(int f,short t,int d)
{
	l[f].push_back({t,d});
}
int n,m;
//bool use[sz];
ll dist[sz];
struct Node
{
	short p;
	ll d;
	bool operator < (const Node &a)const{
		return a.d < d;
	}
};
priority_queue <Node> q;
int tot = 0;
void dij(short s)  
{  
    for(int i = 1 ; i <= tot ; i ++)  
        dist[i] = 21474836411111111ll ;//, use[i] = 0;  
    dist[s] = 0;  
    Node st;  
    st.p = s;  
    st.d = 0;  
    q.push({s,0});  
    while(!q.empty())  
    {  
        Node f = q.top();  
        q.pop();  
        if(f.d>dist[f.p]) continue;
        //if(use[f.p])  
        //    continue;  
        //use[f.p] = 1;  
        for(int i = 0; i < l[f.p].size() ; i ++)  
        {  
            short t = l[f.p][i].t;
            ll d = l[f.p][i].d;
            //if(use[t])
            //    continue;
            if(dist[t] > dist[f.p] + d)  
            {  
                dist[t] = dist[f.p] + d;  
                q.push({t,dist[t]});  
            }  
        }  
    }    
}  

int main()
{
	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m) != EOF)
	{
		tot = 0;
		puts("1111");
		for(int i = 1 ; i <= m ; i ++)
		{
			int a,b,c;ll d;
			scanf("%d%d%d%lld",&a,&b,&c,&d);
			cout << i << " " << a << " " << b << " " << c << " " << d << endl;
			if(!mp[a][c])
				pos[a].push_back(c),mp[a][c] = ++ tot;
			if(!mp[b][c])
				pos[b].push_back(c),mp[b][c] = ++ tot;
			build(mp[a][c],mp[b][c],d);
			build(mp[b][c],mp[a][c],d);
		}
		for(int i = 1 ; i <= n ; i ++)
			sort(pos[i].begin(),pos[i].end());
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 0 ; j < pos[i].size()-1 ; j ++)
			{
				build(mp[i][pos[i][j]],mp[i][pos[i][j+1]],pos[i][j+1]-pos[i][j]);
				build(mp[i][pos[i][j+1]],mp[i][pos[i][j]],pos[i][j+1]-pos[i][j]);
			}
			/*if(pos[i].size())
			{
				build(mp[i][pos[i][pos[i].size()-1]],mp[i][pos[i][0]],pos[i][pos[i].size()-1]-pos[i][0]);
				build(mp[i][pos[i][0]],mp[i][pos[i][pos[i].size()-1]],pos[i][pos[i].size()-1]-pos[i][0]);
			}*/
		}
		int S = ++ tot;
		int E = ++ tot;
		printf("tot %d\n",tot);
		for(int i = 0 ; i < pos[1].size() ; i ++)
			build(S,mp[1][pos[1][i]],0);
		for(int i = 0 ; i < pos[n].size() ; i ++)
			build(mp[n][pos[n][i]],E,0);
		dij(S);
		printf("%lld\n",dist[E]);
        for(int i = 1 ; i <= tot + 5 ; i ++)
			l[i].clear();
        for(int i = 1 ; i <= n + 5 ; i ++)
			mp[i].clear() , pos[i].clear();
	}
	
	return 0;
}
/*
3 3
1 2 1 1
2 3 2 1
1 3 1 1
3 3
1 2 1 1
2 3 2 1
1 3 1 10
3 2
1 2 1 1
2 3 1 1

*/
