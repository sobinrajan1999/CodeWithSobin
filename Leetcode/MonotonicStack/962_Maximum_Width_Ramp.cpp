//Question : https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        //pushing the next decreasing value in the stack
        for(int i = 0; i< nums.size()-1; i++)
        {
            if(st.empty() or nums[st.top()] > nums[i])
            {
                st.push(i);
            }
        }
        int result = 0;
        //based on the values  in the stack we will calculate the the element which is largere or equal the values on the top of the stack.
        for(int i = nums.size()-1; i>=0; i--)
        {
            while(!st.empty() and nums[st.top()] <= nums[i])
            {
                result = std::max(result, i - st.top());
                st.pop();
            }
        }
        return result;
    }
};