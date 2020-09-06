/**
*   author : vivek8420
*   Line - Sweep -Technique
*   refrence: https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/tutorial/
*   Find the closest pair of points in the given array of N distinct points
*   time :(NlogN)
**/


/**
*   ***PRACTICE PROBLEM ***
*   1.https://www.hackerearth.com/practice/math/geometry/line-sweep-technique/practice-problems/algorithm/jewellery-8cc358bc/
*
*   2.Given N line segments, find if any two segments intersect
*   link : https://www.geeksforgeeks.org/given-a-set-of-line-segments-find-if-any-two-segments-intersect/
**/

const inf=1e9;
double closest_pair(PI pnts[],int n) {
    sort(pnts,pnts+n);
    double ans=inf;
    set<PI>box;
    box.insert(pnts[0]);
    int left = 0;

    for(int i=1;i<n;i++) {
        while(left<i && pnts[i].ff - pnts[left].ff > ans) {
            box.erase(pnts[left]);
            left++;
        }
        auto it=box.lower_bound({pnts[i].ss-ans, pnts[i].ff-ans});
        for(;it!=box.end() && pnts[i].ss+ans>=it->ss;it++)
            ans = min(ans, sqrt(pow(pnts[i].ss - it->ss, 2.0)+pow(pnts[i].ff - it->ff, 2.0)));
        box.insert(pnts[i]);
    }
    return ans;
}

int main()
{
    boost;
    #ifndef ONLINE_JUDGE
     freopen("input.c","r",stdin);
     freopen("output.c","w",stdout);
    #endif // ONLINE_JUDGE

    int n;
    cin>>n;
    PI pnts[n];
    for(int i=0;i<n;i++)
        cin>>pnts[i].ff>>pnts[i].ss;
    double ans = closest_pair(pnts,n);
    cout<<ans<<endl;
}
