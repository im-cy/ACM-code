#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 2000100;
ll ans;
int n;
int num[sz];
int temp[sz];
void merge_sort(int l,int r)//½«Çø¼ä l - r ÅÅÐò 
{
    if(l == r)
        return ;
    int mid = l + r >> 1;
    merge_sort(l,mid) , merge_sort(mid+1,r);
    int p = l , pl = l , pr = mid + 1;
    while(pl <= mid || pr <= r)
    {
        if(pr > r || (pl <= mid && num[pl] <= num[pr]))
            temp[p ++] = num[pl ++];
        else
            temp[p ++] = num[pr ++] , ans += mid - pl + 1; 
    }
    for(int i = l ; i <= r ; i ++)
        num[i] = temp[i];
    return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++)
        scanf("%d",&num[i]);
    merge_sort(1,n);
    for(int i = 1 ; i <= n ; i ++)
    	printf("%d ",num[i]);
    return 0;
}
