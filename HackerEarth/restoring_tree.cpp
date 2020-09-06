#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define PI pair<int,int>
#define ff first
#define ss second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MAX 111111
#define MOD 1000000007


int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n;
    cin>>n;
    PI s[n+1];
    int e[n+1],root[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].ff;
        s[i].ss=i;
    }
    for(int i=1;i<=n;i++)
        cin>>e[i];
    sort(s+1,s+1+n);
    stack<int>st;
    st.push(0);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int tmp=s[i].ss;
        int par=st.top();
        root[tmp]=par;
        //cout<<tmp<<" "<<par<<" "<<cnt<<endl;
        st.push(tmp);
        cnt++;
        while(!st.empty() && cnt==e[st.top()])
            st.pop();
    }

    for(int i=1;i<=n;i++)
        cout<<root[i]<<" ";
    cout<<endl;
}

