#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 1111111
#define MOD 1000000007

int par[MAX],size[MAX];

void init(int n)
{
     for(int i=1;i<=n;i++)
     {
              par[i]=i;
              size[i]=1;
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
         if(size[ra]<size[rb])
         {
                  par[ra]=rb;
                  size[rb]+=size[ra];
         }
         else
         {
                  par[rb]=ra;
                  size[ra]+=size[rb];
         }
}

In this program remove is not completede,how rollback edges its future thinks
for dynamic connectivity problem this is not work

    1. squre root decomposition
    2. link-cut tree
    3.heavy-light decomposition

void remove(int a,int b)
{
    if(par[a])==a && par[b]==a)

}
int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    #endif // ONLINE_JUDGE

    int n,m;
    scanf("%d %d",&n,&m);
    init();
    while(m--)
    {
        string str;
        int l,r;
        scanf("%s %d %d",str,&l,&r);

        if(str=="add")
            dsu(l,r);
        else if(str=="rem")
            remove(l,r);
        else
        {
            if(root(l)==root(r))
                printf("YES");
            else
                printf("NO");
        }

    }
}
