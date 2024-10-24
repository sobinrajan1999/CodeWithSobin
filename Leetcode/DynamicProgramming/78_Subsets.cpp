//question : https://leetcode.com/problems/subsets/description/

class Solution {
public:

    vector<vector<int>> ans;

    void solve(vector<int>& nums, int n, vector<int> arr)
    {
        //if the interation to all array elements completes, then we have our subset. we will push it to the global answer array.
        if(n < 0)
        {
            ans.push_back(arr);
            // for(auto i : arr)
            // {
            //     std::cout<<i<<" ";
            // }
            // std::cout<<std::endl;
            return;
        }
        //based on the pick and no pick
        //nopick
        solve(nums, n-1, arr);
        //pick
        arr.push_back(nums[n]);
        solve(nums, n-1, arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, nums.size()-1, {});
        return ans;
    }
};