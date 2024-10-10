// Questions: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store

class Solution {
public:
    //function to check if it possible to divide the quantities till k
    bool isPossible(int k, int mid, vector<int>& arr)
    {
        int index = 0;
        while(index < arr.size())
        {
            int div = (arr[index] + mid-1)/mid;
            if(k >= div)
            {
                k -= div;
            }
            else
            {
                return false;
            }
            index++;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        long long int sum = 0;
        int maxval = INT_MIN;
        for(auto it : quantities)
        {
            sum += it;
        }
        int start = 1;
        int end = *max_element(quantities.begin(), quantities.end());
        while(start < end)
        {
            int mid = start + ( end - start)/2;
            std::cout<<"start: "<<start<<" mid: "<<mid<<" end: "<<end<<std::endl;
            //if possible with the mid value then will try to 
            if(isPossible(n, mid, quantities))
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        return end;
        











        // if(quantities.size() == n)
        // {
        //     return *max_element(quantities.begin(), quantities.end());
        // }
        // float maxProducts = 0;
        // for(auto it : quantities)
        // {
        //     maxProducts += it;
        // }
        // return ceil(maxProducts/n);

    }
};