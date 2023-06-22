class Solution
{
public: // O(1) extra space solution
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here

        arr[2] = arr[0] + arr[2];

        for (int i = 3; i < n; i++)
        {
            arr[i] += max(arr[i - 2], arr[i - 3]);
        }
        return max(arr[n - 1], arr[n - 2]);
    }
};