//Question : https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //using priority queue as min heap to keep three value. 1. value, 2. kth Index, 3. index of the value from kth array
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int k = nums.size();
        int currmax = INT_MIN;
        //pushing the first values from the k arrays as they all are the minimums.
        for(int i = 0; i< k; i++)
        {
            pq.push({nums[i][0], {i, 0}});
            //keeping the max value from the priority queue
            currmax = std::max(currmax, nums[i][0]);
        }
        //this will keep the minimum range that we have to return
        int minRange = 0;
        int maxRange = INT_MAX;

        while(!pq.empty())
        {
            auto [curr_val, indexes] = pq.top();
            auto [k_idx, idx] = indexes;
            pq.pop();
            //if the new range is less than the minRange and maxRange
            if(currmax - curr_val < maxRange - minRange)
            {
                maxRange = currmax;
                minRange = curr_val;
            }
            //update the queue with new value from the same kth array
            if(idx+1 < nums[k_idx].size())
            {
                int nextval = nums[k_idx][idx+1];
                pq.push({nextval, {k_idx, idx+1}});
                currmax = std::max(currmax, nextval);
            }
            //if any of the array got empty then not need for iterations
            else
            {
                break;
            }
        }
        return {minRange, maxRange};
    }
};