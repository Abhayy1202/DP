class Solution
{
public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(int *arr, int n)
    {
        // code here
        int ans = 0;
        arr[2] = arr[0] + arr[2];

        for (int i = 3; i < n; i++)
        {
            arr[i] += max(arr[i - 2], arr[i - 3]);
        }
        return max(arr[n - 1], arr[n - 2]);
    }
};