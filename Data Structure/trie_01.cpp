#include <bits/stdc++.h>
using namespace std;
const int N = 31;

typedef struct TrieNode{
    TrieNode* ptr[2];
    int cnt=0;
}trie;

trie* root;

void insert(int val){
    trie* cur = root;
    for(int i=N;i>=0;i--){
        int it = (val>>i)&1ll;
        if(!cur->ptr[it])
            cur->ptr[it] = new trie();
        cur = cur->ptr[it];
        cur->cnt++;
    }
}

int query(int val){
    int ans = 0;
    trie* cur = root;
    for(int i=N;i>=0;i--){
        int it = (val>>i)&1ll;
        if(cur->ptr[1-it] != nullptr){
            ans+=(1ll<<i);
            cur = cur->ptr[1-it];
        }
        else if(cur->ptr[it] != nullptr)
            cur = cur -> ptr[it];
        else
            break;
    }
    return ans;
}

int32_t main() { 
     int n;
     cin>>n;
     int a[n];
     root = new trie();
     for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
     }
     int q;
     cin>>q;
     while(q--){
        int x;
        cin>>x;
        int ans = query(x);
        cout<<ans<<endl;
     }
}