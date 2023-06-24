class Solution
{
public:
    long long maximumProfit(vector<long long> &prices, int n)
    {
        // Code here
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        }
        return profit;
    }
};