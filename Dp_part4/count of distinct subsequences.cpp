class Solution{
  public:
  
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int mod=1e9+7;
	    int n=s.size();
	    vector<int> dp(n+1,0);
	    vector<int>visited(256,-1);
	    dp[0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        dp[i]=(2*(dp[i-1]))%mod;
	        if(visited[s[i-1]]!=-1)dp[i]-=dp[visited[s[i-1]]];
	        dp[i]%=mod;
	        visited[s[i-1]]=i-1;
	    }
	    if(dp[n]<0)dp[n]+=mod;
	    return dp[n]%mod;
	    
	}

};