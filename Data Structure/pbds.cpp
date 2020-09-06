/*
*   author:vivek8420
*   problem:ORDERSET - Order statistic set (SPOJ)
*   link:https://www.spoj.com/problems/ORDERSET/
*   all operation take log(n) time
*/

#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
using namespace __gnu_pbds;

typedef tree<
   int, 
   null_type,
   less<int>,
   rb_tree_tag, 
   tree_order_statistics_node_update
>ordered_set; 

int32_t main() {
   ordered_set s;
   int q;
   cin>>q;
   while(q--) {
      char c;
      int x;
      cin>>c>>x;
      if(c=='I') 
         s.insert(x);//insert in set
      else if(c=='C') {
         /* find index of x in sorted order*/
         int ans=s.order_of_key(x);
         cout<<ans<<endl;
      }
      else if(c=='D') 
         s.erase(x);//remove from set
      else if(c=='K') {
         if(s.size()<x)
            cout<<"invalid"<<endl;
         else {
            /* return Xth element */
            int ans=*s.find_by_order(x-1);
            cout<<ans<<endl;
         }
      }
   }
}
