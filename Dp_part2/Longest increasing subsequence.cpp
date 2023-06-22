class Solution{
    public :
        // Function to find length of longest increasing subsequence.
        // Binary search approach for O(nlogn)
        int bsearch(vector<int> & v, int l, int h, int val){
            if (val > v[h]) return h + 1;

while (l < h)
{
    int mid = (l + h) / 2;
    if (v[mid] == val)
        return mid;
    else if (v[mid] > val)
        h = mid;
    else
        l = mid + 1;
}
return h;
}

int longestSubsequence(int n, int a[])
{
    // your code here
    int indx = 0;
    vector<int> v(n);
    v[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        int last = bsearch(v, 0, indx, a[i]);
        v[last] = a[i];
        indx = max(indx, last);
    }
    return indx + 1;
}
};