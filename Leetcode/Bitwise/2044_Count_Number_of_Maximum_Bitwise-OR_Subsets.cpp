//Question : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int largestOR = 0;
        int maxval = 0;
        int n = nums.size();
        //finding the largest number by OR ing all the values
        for(int i = 0; i < n; i++)
        {
            largestOR = largestOR | nums[i];
        }
        int finalcount = 0;
        //creating all the subsets and trying to match with the largestOR.
        for(int i = 0; i < pow(2, n); i++)
        {
            int result = 0;
            for(int j = 0; j < n; j++)
            {
                if(i & (1<<j))
                {
                    result = result | nums[j];
                }
            }
            if(result == largestOR)
            {
                finalcount++;
            }
        }
        return finalcount;
    }
};