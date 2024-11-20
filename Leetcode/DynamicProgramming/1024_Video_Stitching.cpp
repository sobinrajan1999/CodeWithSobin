//question ; https://leetcode.com/problems/video-stitching/description/

class Solution {
public:
    int dp[104][104];  // DP array to store minimum clips needed for a specific state (i, mx)

    // Helper function to find the minimum number of clips needed
    int solve(int i, vector<vector<int>>& clips, int mx, int time) {
        // Base case: If we've covered the entire required time, no more clips are needed
        if(mx >= time) return 0;

        // If we've checked all clips and still can't cover the required time, return an infinite value
        if(i >= clips.size()) {
            return 1e9;
        }

        // If we already computed the result for this state, return the cached value
        if(dp[i][mx] != -1) return dp[i][mx];

        // If the current clip starts within the current maximum range `mx`
        if(clips[i][0] <= mx) {
            // Option 1: Take this clip and extend `mx` to cover up to `clips[i][1]`
            int temp = 1 + solve(i + 1, clips, max(mx, clips[i][1]), time);

            // Option 2: Skip this clip and try the next one with the same `mx`
            return dp[i][mx] = min(temp, solve(i + 1, clips, mx, time));
        }

        // If the current clip cannot be used (starts after `mx`), return an infinite value for this path
        return dp[i][mx] = 1e9;
    }

    // Main function to determine the minimum number of clips needed to cover the range [0, time]
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n = clips.size();  // Number of clips

        // Sort clips by their starting times for easier processing in the `solve` function
        sort(clips.begin(), clips.end());

        // If the earliest clip doesn't start at 0, we cannot cover the range from the beginning
        if(clips[0][0] != 0) return -1;

        // Initialize DP array with -1 to indicate uncomputed states
        memset(dp, -1, sizeof(dp));

        // Start the recursive DP function with the first clip, an initial coverage of 0, and target `time`
        int ans = solve(0, clips, 0, time);

        // If the answer is still an infinite value, it means the range cannot be covered with the given clips
        return ans == 1e9 ? -1 : ans;
    }
};
