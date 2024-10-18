//Question : https://leetcode.com/problems/longest-mountain-in-array/description/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> uphill(n, 1), downhill(n, 1);
        int result = 0;
        for(int i = 1; i< n; i++)
        {
            if(arr[i] > arr[i-1])
            {
                uphill[i] = uphill[i-1] + 1;
            }
        }
        for(int j = n-2 ; j >=0; j--)
        {
            if(arr[j+1] < arr[j])
            {
                downhill[j] = downhill[j+1] + 1;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(uphill[i] > 1 and downhill[i] > 1)
            {
                result = std::max(uphill[i] + downhill[i] -1, result);
            }
            
        }
        return result;
    }
};