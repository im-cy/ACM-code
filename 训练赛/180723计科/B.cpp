#include<cstdio>
#include<set>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000200 ;
int p,a[maxn];
set<int>all;
map<int,int>m;
 
void input()
{
    scanf("%d",&p);
    for(int i=0;i<p;i++)
	{
        scanf("%d",&a[i]);
        all.insert(a[i]);
        m[a[i]]=0;
    }
}
 
void solve()
{
    int Start=0,End=0,ans=maxn;
    int n=all.size(),sum=0;
    while(true)
	{
        while(End<p&&sum<n)
		{
            if(m[a[End]]==0)
			{
                sum++;
            }
            m[a[End]]++;
            End++;
        }
        if(sum<n) 
			break;
        ans = min(ans,End-Start);
        if(m[a[Start]]==1)
		{
            sum--;
        }
        m[a[Start]]--;
        Start++;
    }
    printf("%d\n",ans);
}
 
int main()
{
    input();
    solve();
    return 0;
}
