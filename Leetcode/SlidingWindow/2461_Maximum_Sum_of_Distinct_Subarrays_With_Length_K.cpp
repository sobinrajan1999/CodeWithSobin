//Question: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        if(n < k)
        {
            return 0;
        }
        //using unordered set to keep the unique elements
        unordered_set<int> us;
        long long currsum = 0;
        long long maxsum = 0;
        long long left = 0;
        for(long long i = 0; i< n; i++)
        {
            //if the element is already present in the set. we have to eliminate the all the elements till the duplicate element.
            while(us.find(nums[i]) != us.end())
            {
                us.erase(nums[left]);
                currsum -= nums[left];
                left++;
            }
            //adding the new element
            currsum += nums[i];
            us.insert(nums[i]);
            //if we have the k element inside our set
            if((i - left + 1) == k)
            {
                maxsum = std::max(currsum, maxsum);
                us.erase(nums[left]);
                currsum -= nums[left];
                left++;
            }

        }
        return maxsum;
    }
};