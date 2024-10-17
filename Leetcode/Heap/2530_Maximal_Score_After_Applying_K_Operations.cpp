//Questions : https://leetcode.com/problems/maximal-score-after-applying-k-operations

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it : nums)
        {
            pq.push(it);
        }
        long long finalScore = 0;
        int index = 0;
        while(!pq.empty() and k > index)
        {
            auto temp = pq.top();
            std::cout<<temp<<std::endl;
            finalScore += temp;
            if(temp == 1)
            {
                finalScore += (k - 1 - index);
                break;
            }
            pq.pop();
            pq.push(ceil((temp+2)/3));
            index++;
        }
        return finalScore;
    }
};