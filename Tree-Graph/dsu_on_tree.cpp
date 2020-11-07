/*
    author : vivek8420
    problem:https://www.hackerrank.com/contests/101feb14/challenges/coloring-tree
    time: O(N*logN*longN)
    // find number of distinct colors available in subtree of u 
*/
//simillar problem: https://codeforces.com/contest/600/problem/E

#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
#define ff first
#define ss second
#define boost ios::sync_with_stdio(false);cin.tie(nullptr)

const int N = 1e5 + 5;
vector<int>g[N];
set<int>s[N];
int id[N],color[N],ans[N];

void dfs(int u,int p){
    int big = u,maxi = 0;
    for(int v:g[u]){
        if(v == p)
            continue;
        dfs(v,u);
        if(s[id[v]].size()>maxi){
            maxi = s[id[v]].size();
            big = id[v];
        }
    }

    for(int v:g[u]){
        if(v == p or id[v]== big)
            continue;
        for(auto tt:s[id[v]])
            s[big].insert(tt);
        s[id[v]].clear();
    }
    s[big].insert(color[u]);
    ans[u] = s[big].size();
    id[u] = big;
}

int32_t main() {
    boost;
    int n,m,root;
    cin>>n>>m>>root;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        cin>>color[i];
    dfs(root,0);
    while(m--){
        int u;
        cin>>u;
        cout<<ans[u]<<endl;
    }
}    
