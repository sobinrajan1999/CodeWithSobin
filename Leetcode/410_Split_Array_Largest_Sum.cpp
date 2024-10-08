//Question: https://leetcode.com/problems/split-array-largest-sum/

class Solution {
public:
    //adding the numbers based on the mid element and checking possible k sums.
    //if possible then return true
    //else return false;
    bool isPossible(vector<int>& arr, int k, int mid)
    {
        int sum = 0;
        for(auto it : arr)
        {
            if(sum + it <= mid)
            {
                sum += it;
            }
            else
            {
                if(it <= mid)
                {
                    sum = it;
                }
                else
                {
                    return false;
                }
                k--;
            }
            if(k < 0)
            {
                return false;
            }
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        //binary search will be based on the  largestPossibleSum from the array
        long long largestPossibleSum= 0;
        for(auto it : nums)
        {
            largestPossibleSum += it;
        }
        int start = 0; 
        int end = largestPossibleSum;
        int mid = 0;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            std::cout<<"start: "<<start<<" mid: "<<mid<<" end: "<<end<<std::endl;
            //check if the mid element is the minimum largest sum
            //if yes then we will look for minimum number from the mid;
            //else we will look for the bigger number.
            if(isPossible(nums, k-1, mid))
            {
                std::cout<<"possible"<<std::endl;
                end = mid-1;
            }
            else
            {
                std::cout<<"not possible"<<std::endl;
                start = mid+1;
            }
        }
        return start;
    }
};
