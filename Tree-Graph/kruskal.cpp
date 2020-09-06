int par[MAX],sz[MAX];
void init()
{
    for(int i=1;i<=MAX;i++)
    {
        par[i]=i;
        sz[i]=1;
    }
}

int root(int a)
{
    while(par[a]!=a)
    {
        par[a]=par[par[a]];
        a=par[a];
    }
    return a;
}

void dsu(int a,int b)
{
    int ra=root(a);
    int rb=root(b);
    if(ra==rb)
        return;
    if(sz[ra]<sz[rb])
    {
        par[ra]=rb;
        sz[rb]+=sz[ra];
    }
    else
    {
        par[rb]=ra;
        sz[ra]+=sz[rb];
    }
}

void kruskal(vector<TP> & edges)
{
    sort(edges.begin(), edges.end());
    init();
    vector<TP>::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int u = it->ft;
        int v = it->st;
        int set_u = root(u);
        int set_v = root(v);
        if (set_u != set_v)
        {
            cout << u << " - " << v << endl;
            dsu(set_u, set_v);
        }
    }
}

