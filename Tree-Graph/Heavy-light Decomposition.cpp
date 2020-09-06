/*
*   heavy-light decomposition
*   problem: QTREE(SPOJ)
*   author:savaliya_vivek
*   resources: anudeep's blogs
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 11111
#define MOD 1000000007
#define lv 20

int ptr,chainNo=0,baseArray[MAX],chainHead[MAX],posInBase[MAX],chainInd[MAX];
int tree[4*MAX],sparce[MAX][lv],level[MAX],subsize[MAX],otherEnd[MAX];
bool visit[MAX];
vector<PI>adj[MAX];
vector<int>index[MAX];

void flush()
{
	ptr=0;
	chainNo=0;
	memset(baseArray,-1,sizeof baseArray);
	memset(visit,false,sizeof visit);
	memset(chainHead,-1,sizeof chainHead);
	memset(sparce,-1,sizeof sparce);
	memset(subsize,0,sizeof subsize);
	memset(posInBase,0,sizeof posInBase);
	for(int i=0;i<MAX;i++)
	{
		adj[i].clear();
		index[i].clear();
	}
}

void built(int x,int ss,int ee,int arr[])
{
	if(ss==ee-1)
	{
		tree[x]=arr[ss];
	}
	else
	{
	  int mid=(ee+ss)/2;
	  built(2*x,ss,mid,arr);
	  built(2*x+1,mid,ee,arr);
	  tree[x]=max(tree[2*x],tree[2*x+1]);
	}
	return;
}

void update(int node,int ss,int ee,int pos,int val)
{
	if(ss>pos || ee<=pos)
		return;
	if(ss==pos&& ss==ee-1)
	{
		tree[node]=val;
		return;
	}
	int m=(ee+ss)/2;
	update(2*node,ss,m,pos,val);
	update(2*node+1,m,ee,pos,val);
	tree[node]=max(tree[2*node],tree[2*node+1]);
	return;
}

int query_tree(int node,int ss,int ee,int l,int r)
{
	if(ss>=r || ee<=l)
		return 0;
	if(l<=ss && ee<=r)
		return tree[node];
	int m=(ee+ss)/2;
	int p1=query_tree(2*node,ss,m,l,r);
	int p2=query_tree(2*node+1,m,ee,l,r);
	return max(p1,p2);
}

int query_up(int u, int v)
{
	if(u == v)
		return 0;
	int uchain, vchain = chainInd[v], ans = -1;
	while(1)
	{
		uchain = chainInd[u];
		if(uchain == vchain)
		{
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			if(u==v)
			 break;
			int tmp=query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			if(tmp > ans)
			 ans = tmp;
			break;
		}
		int tmp=query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		if(tmp > ans)
		 ans = tmp;
		u = chainHead[uchain]; // move u to u's chainHead
		u = sparce[u][0]; //Then move to its parent, that means we changed chains
	}
	return ans;
}


void hld(int curNode, int cost, int prev)
 {
	if(chainHead[chainNo] == -1)
		chainHead[chainNo] = curNode; // Assign chain head

	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;
	//cout<<curNode<<" "<<ptr<<" "<<chainNo<<endl;
	int sc = -1, ncost;
	// Loop to find special child
	for(int i=0; i<adj[curNode].size(); i++)
	{
		if(adj[curNode][i].ff != prev)
		{
			if(sc == -1 || subsize[sc] < subsize[adj[curNode][i].ff])
			 {
				sc = adj[curNode][i].ff;
				ncost =adj[curNode][i].ss;
			 }
		}
	}

	if(sc != -1) {
		// Expand the chain
		hld(sc, ncost, curNode);
	}

	for(int i=0;i<adj[curNode].size(); i++)
	{
		if(adj[curNode][i].ff != prev)
		{
			if(sc != adj[curNode][i].ff)
			 {
				chainNo++;
				hld(adj[curNode][i].ff,adj[curNode][i].ss, curNode);
			 }
		}
	}
}

void sparceTable(ll n)
{
	for(int i=1;i<lv;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(sparce[j][i-1]!=-1)
			{
				sparce[j][i]=sparce[sparce[j][i-1]][i-1];
			}
		}
	}
}

int lca(int u, int v)
{
	if (level[v] < level[u])
		swap(u, v);
	ll diff = level[v] - level[u];
	for (ll i=0; i<lv; i++)
		if ((diff>>i)&1)
			v = sparce[v][i];
	if (u == v)
		return u;
	for (ll i=lv-1; i>=0; i--)
		if (sparce[u][i] != sparce[v][i])
		{
			u = sparce[u][i];
			v = sparce[v][i];
		}
	return sparce[u][0];
}

void EulorTour(int x,int prev)
{
	level[x]=level[prev]+1;
	sparce[x][0]=prev;
	visit[x]=true;
	subsize[x]=1;
	for(int i=0;i<adj[x].size();i++)
	{
		if(!visit[adj[x][i].ff])
		{
			otherEnd[index[x][i]] = adj[x][i].ff;
			EulorTour(adj[x][i].ff,x);
			subsize[x] += subsize[adj[x][i].ff];
		}
	}
}

void query(int u, int v)
{
	int la = lca(u, v);
	int ans1 = query_up(u, la);
	int ans2= query_up(v, la);
	//cout<<la<<" "<<ans1<<" "<<ans2<<endl;
	cout<<max(ans1,ans2)<<endl;
}

void change(int x,int val)
{
	int u = otherEnd[x];
	update(1, 0, ptr, posInBase[u], val);
}

int main()
{
	boost;
	#ifndef ONLINE_JUDGE
	 freopen("input.c","r",stdin);
	 freopen("output.c","w",stdout);
	#endif // ONLINE_JUDGE

	int t;
	cin>>t;
	while(t--)
	{
		flush();
		int n;
		cin>>n;
		for(int i=1;i<n;i++)
		{
			ll u,v,w;
			cin>>u>>v>>w;
			u--;v--;
			adj[u].push_back({v,w});
			adj[v].push_back({u,w});
			index[u].push_back(i-1);
			index[v].push_back(i-1);
		}

		EulorTour(0,-1);
		sparceTable(n);
		hld(0,-1,-1);
		built(1,0,ptr,baseArray);
		while(1)
		{
			string str;
			cin>>str;
			if(str=="DONE")
				break;
			int u,v;
			cin>>u>>v;
			if(str=="QUERY")
				query(u-1,v-1);
			else
				change(u-1,v);
		}
	}
}
