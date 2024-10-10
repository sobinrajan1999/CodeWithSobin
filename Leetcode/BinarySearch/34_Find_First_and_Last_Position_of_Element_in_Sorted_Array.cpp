//Question : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size()-1;
        int first = -2, second = 0;
        while(start <= end)
        {
            int mid = (start + end)/2;
            //found the target
            if(nums[mid] == target)
            {
                first = mid;
                //searching the left half of array for the same element 
                while(first >=0 && target == nums[first])
                {
                    first--;
                }
                second = mid;
                //searching the right half of array for the same element 
                while(second <= nums.size()-1 && target == nums[second])
                {
                    second++;
                }
                break;
            }
            else if(nums[mid] > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return {first+1, second-1};
    }
};