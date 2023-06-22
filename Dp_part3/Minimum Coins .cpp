class Solution
{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> c{1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        vector<int> ans;

        for (int i = 9; i >= 0;)
        {
            if (N == 0)
                break;
            if (c[i] <= N)
            {
                ans.push_back(c[i]);
                N -= c[i];
            }

            else
                i--;
        }
        return ans;
    }
};