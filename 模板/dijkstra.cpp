int dij(int s,int e)  
{  
    memset(use,0,sizeof(use));  
    for(int i = 1 ; i <= n ; i ++)  
        dist[i] = 2147483641;  
    dist[s] = 0;  
    node st;  
    st.p = s;  
    st.d = 0;  
    q.push({s,0});  
    while(!q.empty())  
    {  
        node f = q.top();  
        q.pop();  
        if(use[f.p])  
            continue;  
        use[f.p] = 1;  
        for(int i = head[f.p] ; i ; i = nxt[i])  
        {  
            int t = l[i].t;
            if(use[t])
                continue;
            if(dist[t] > dist[f.p] + l[i].d)  
            {  
                dist[t] = dist[f.p] + l[i].d;  
                q.push({t,dist[t]});  
            }  
        }  
    }  
    if(dist[e] == 2147483641)  
        return -1;  
    return dist[e];  
}  

