//question : https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/description/

class Solution {
public:
    int longestIncreasingSubsequence(vector<int>& arr, int k, int start)
    {
        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[start]);
        for(int i = start+k; i < n; i+= k)
        {
            if(arr[i] >= ans.back())
            {
                ans.push_back(arr[i]);
            }
            else
            {
                auto index = upper_bound(ans.begin(), ans.end(), arr[i]);
                ans[index - ans.begin()] = arr[i];
            }
        }
        return ans.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int result = 0;
        //divide the array into non-overlapping subsequences and simplify the problem
        //We can use this to divide the array into at most k non-overlapping sequences, where arr[i] will belong to the (i%k)th sequence.
        //and perform the LIS on those i%k elements in the array
        for(int i = 0; i < k; i++)
        {
            result += longestIncreasingSubsequence(arr, k, i);
        }
        return arr.size() - result;
    }
};