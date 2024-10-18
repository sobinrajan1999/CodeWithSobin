//Question : https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> result;
        int n = security.size();
        vector<int> leftgreater(n, 1), rightgreater(n, 1);
        //getting the count of greater element from left of the array elements
        for(int i = 1; i < n; i++)
        {
            if(security[i] <= security[i-1])
            {
                leftgreater[i] = leftgreater[i-1] + 1;
            } 
        }
        //getting the count of greater element from left of the array elements
        for(int i = n-2; i >=0; i--)
        {
            if(security[i] <= security[i+1])
            {
                rightgreater[i] = rightgreater[i+1] + 1;
            } 
        }
        //elements from left side and right side of the array index 'i' should be greater or equal to the time.
        for(int i = time; i < n - time; i++)
        {
            if(leftgreater[i]-1 >= time and rightgreater[i]-1 >=  time)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};