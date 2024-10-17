//Question : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto it : intervals)
        {
            int starttime = it[0], endtime = it[1];
            if(!pq.empty() and pq.top() < starttime)
            {
                pq.pop();
            }
            pq.push(endtime);
        }
        return pq.size();
    }
};