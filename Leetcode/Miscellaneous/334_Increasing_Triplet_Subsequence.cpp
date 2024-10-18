//Question : https://leetcode.com/problems/increasing-triplet-subsequence/description/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if(nums.size() <=2)
        {
            return false;
        }
        int first = std::numeric_limits<int>::max();
        int second = std::numeric_limits<int>::max();
        for(auto& it : nums)
        {
            if(it <= first)
            {
                first = it;
            }
            else if( it <= second)
            {
                second = it;
            }
            else
                return true;
        }
        return false;
    }
};