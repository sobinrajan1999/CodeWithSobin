//Question : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:

    int binarySearch(vector<int>& arr, int num, int target, int start, int end)
    {

        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if((arr[mid] + arr[num]) == target)
            {
                return mid+1;
            }
            else if((arr[mid] + arr[num]) > target)
            {
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0;i< numbers.size(); i++)
        {
            int val = binarySearch(numbers, i, target, i+1, numbers.size()-1);
            if(val != -1)
            {
                return {i+1, val};
            }
        }
        return {-1, -1};
    }
};