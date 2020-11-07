/*
	author:vivek8420
	problem:find even and odd length palimdrome substrings of given string S.
	time:O(N)
	link:https://www.codechef.com/FFC32020/problems/FFC320A
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)

int manacher(string s){
	int n=s.size();
	int odd[n],even[n];//odd and even length palimdrome subsrting for middle i
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(odd[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
		    k++;
		}
		odd[i] = k--;
		if (i + k > r) {
		    l = i - k;
		    r = i + k;
		}
	}

	for (int i = 0, l = 0, r = -1; i < n; i++) {
	    int k = (i > r) ? 0 : min(even[l + r - i + 1], r - i + 1);
	    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
	        k++;
	    }
	    even[i] = k--;
	    if (i + k > r) {
	        l = i - k - 1;
	        r = i + k ;
	    }
	}
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=odd[i]-even[i];
	return sum;
}

int32_t main()
{
    boost;
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int d;cin>>d;
    	int id=s.find('_');
    	for(int i=0;i<26;i++){
    		s[id]=i+'a';
    		if(manchar(s)==d)
    			break;
    	}
    	cout<<s[id]<<endl;
    }
}