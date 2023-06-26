class Solution {
  public:
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int sum=accumulate(arr.begin(),arr.end(),0);
            vector <int> dp(sum+1);
int mod = 1e9+7;
dp[0] = 1;
int count=0;
for(int i = 1;i <=arr.size();i++){
    vector <int> t = dp;
    for(int j = 0;j <=sum;j++)
        if(arr[i-1] <= j) t[j] = (t[j]+dp[j-arr[i-1]])%mod;
    dp = t;
}
for (int i = 0; i <= sum; i++) {
    if (i==(target+sum)/2 and i-(sum-i)==target) {
      count+=dp[i];
    }
  }
  return count;
        
        
    }
};