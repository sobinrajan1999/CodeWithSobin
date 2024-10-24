//question : https://leetcode.com/problems/predict-the-winner/description/

class Solution {
public:

    vector<vector<int>> dp;
    //here we will only calculate the maximum points collected by player 1.
    int rec(vector<int>& nums, int i, int j)
    {
        if(i > j)
        {
            return 0;
        }
        if(i == j)
        {
            return nums[i];
        }

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        //if player 1 has picked left element from array then player 2 will pick the maximum from either of the left or the right side of the array other than the element picked by player 1. if player 2 is picking the maximum then minimum will be picked by player1. so, the below logic works in this way.
        //vice versa for right element as well.
        int leftpick = nums[i] + std::min(rec(nums, i+2, j), rec(nums, i+1, j-1));
        int rightpick = nums[j] + std::min(rec(nums, i, j-2), rec(nums, i+1, j-1));
        return dp[i][j] = std::max(leftpick, rightpick); 
    }

    bool predictTheWinner(vector<int>& nums) {
        dp = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int totalplayer1 = rec(nums, 0, nums.size()-1);
        int totalplayer2 = total - totalplayer1;
        return  totalplayer1 >= totalplayer2;
    }
};