class Solution {
  public:
  long long int topD(int n,vector<long long int> &td)
  {
      if(n==0||n==1)
      return n;
      if(td[n]!=-1)
      return td[n];
      
      td[n]=(topD(n-1,td)+topD(n-2,td))%1000000007;
      return td[n];
  }
    long long int topDown(int n) {
        // code here
        vector<long long int> td(n+1,-1);
        return topD(n,td);
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        return dp[n];
        
    }
};