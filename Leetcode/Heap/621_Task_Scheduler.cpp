//question : https://leetcode.com/problems/task-scheduler/description/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        long long int maxidletime = 0;
        unordered_map<char, int> m;

        for(auto it : tasks)
        {
            m[it]++;
        }
        priority_queue<int> pq;
        for(auto it : m)
        {
            pq.push(it.second);
        }
        int freq = pq.top();
        pq.pop();
        maxidletime = (freq-1)*n;
        while(!pq.empty())
        {
            maxidletime = maxidletime - min((freq-1), pq.top());
            if(maxidletime < 0)
            {
                maxidletime = 0;
            }
            pq.pop();
        }
        return maxidletime + tasks.size();
    }
};