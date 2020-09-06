/** LCA using sparce table
*   time:O(NlogN)
*   space:O(NlogN)
*   author:savaliya_vivek
*   problem:LCA(SPOJ)
*   link:https://www.spoj.com/problems/LCA/
**/

#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long int
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define PI pair<int,int>
#define MIN LONG_MIN
#define MAX 11111
#define level 18


vector <int> tree[MAX];
int depth[MAX];
int parent[MAX][level];

void flush()
{
    for(int i=0;i<MAX;i++)
        tree[i].clear();
    memset(parent,-1,sizeof parent);
    memset(depth,0,sizeof depth);
}

void dfs(int cur, int prev)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (int i=0; i<tree[cur].size(); i++)
	{
		if (tree[cur][i] != prev)
			dfs(tree[cur][i], cur);
	}
}

void sparse(int n)
{
	for (int i=1; i<level; i++)
	{
		for (int node = 1; node <= n; node++)
		{
			if (parent[node][i-1] != -1)
				parent[node][i] =
					parent[parent[node][i-1]][i-1];
		}
	}
}

int lca(int u, int v)
{
	if (depth[v] < depth[u])
		swap(u, v);

	int diff = depth[v] - depth[u];

	// Step 1 of the pseudocode
	for (int i=0; i<level; i++)
		if ((diff>>i)&1)
			v = parent[v][i];

	// now depth[u] == depth[v]
	if (u == v)
		return u;

	// Step 2 of the pseudocode
	for (int i=level-1; i>=0; i--)
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}


int main()
{
    boost;

    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        flush();
        int n,q;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int m;
            cin>>m;
            for(int j=0;j<m;j++)
            {
                int u;
                cin>>u;
                tree[u].push_back(i);
                tree[i].push_back(u);
            }
        }

        dfs(1,0);
        sparse(n);
        cout<<"Case"<<" "<<t<<":"<<endl;
        cin>>q;
        while(q--)
        {
            int u,v;
            cin>>u>>v;
            cout<<lca(u,v)<<endl;
        }

    }
    return 0;
}

