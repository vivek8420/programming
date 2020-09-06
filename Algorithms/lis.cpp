const int inf=1e9;
int lis(vector<int> &ve){
   int n=ve.size();
   vector<int>dp(n+1,inf);
   dp[0]=-inf;
   int ans=0;
   for(int i:ve){
      int pos=upper_bound(dp.begin(),dp.end(),i)-dp.begin();
      if(dp[pos-1]< i && i<dp[pos])
         dp[pos]=i;
   }
   for(int i=0;i<=n;i++){
      if(dp[i]<inf)
         ans=i;
   }
   return ans;
}


// stricly incrising lis
int lis(vector<int>&a){
   vector<int>dp;
   for(int &i:a){
      int pos = lower_bound(dp.begin(),dp.end(),i) - dp.begin();
      if(pos != dp.size())
         dp[pos] = i;
      else
         dp.push_back(i);
   }
   return dp.size();
}
