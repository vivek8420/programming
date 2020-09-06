#include<bits/stdc++.h>
using namespace std;

void shift_table(string str,int a[256])
{
    fill_n(&a[0],256,str.size());
    int l=str.size();
    for(int i=0;i<l-1;i++)
        a[str[i]]=l-i-1;
}

int horspool(string txt,string pat)
{
    int ans=0;
    int a[256];
    shift_table(pat,a);
    int l=pat.size()-1;
    while(l<txt.size())
    {
        int i=l;
        int j=pat.size()-1;
        while(txt[i]==pat[j] && j>0)
            i--,j--;
        if(j==0)
            ans++;
        l+=a[txt[i]];
       // cout<<l<<endl;
    }
    return ans;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int ans = horspool(s1,s2);
    cout<<ans<<endl;
}