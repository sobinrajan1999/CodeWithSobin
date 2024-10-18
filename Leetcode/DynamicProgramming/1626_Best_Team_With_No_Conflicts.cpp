//Question : https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> basketball;
        //here we have to calculate LIS based on the age and the scores should be sorted. So, we do the calculations based on the ages.
        for(int i = 0; i< scores.size(); i++)
        {
            basketball.push_back({scores[i], ages[i]});
        }
        std::sort(basketball.begin(), basketball.end());
        int n = scores.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++)
        {
            dp[i] = basketball[i].first;
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            result = std::max(result, basketball[i].first);
            for(int j = 0; j < i; j++)
            {
                if((basketball[i].first + dp[j]) > dp[i] and basketball[i].second >= basketball[j].second)
                {
                    dp[i] = dp[j] + basketball[i].first;
                    result = std::max(result, dp[i]);
                }
            }
        }
        return result;
    }
};