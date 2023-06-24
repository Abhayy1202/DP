class Solution
{
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n)
    {
        vector<vector<int>> ans;
        int buy = 0, sell = -1;
        for (int i = 1; i < n; i++)
        {
            if (A[i] > A[i - 1])
            {
                sell = i;
                if (i == n - 1)
                {
                    ans.push_back({buy, sell});
                }
            }
            else
            {
                if (sell != -1)
                {
                    ans.push_back({buy, sell});
                    sell = -1;
                }
                buy = i;
            }
        }
        return ans;
    }
};