//question : https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Vector to keep track of the last seen position of each character
        // Initialize with -1, meaning no character has been seen yet
        vector<int> ch(256, -1);

        // If the string is empty or has only one character, return its length
        if (s.size() <= 1) {
            return s.size();
        }

        int n = s.size();     // Length of the string
        int result = 0;       // Variable to store the length of the longest substring without repeating characters
        int start = -1;       // The starting index of the current substring window
        int i;                // Iterator variable for the loop

        // Iterate over each character in the string
        for (i = 0; i < n; i++) {
            // If the current character has been seen and its last seen position is within the current window
            if (ch[s[i]] > start) {
                // Update the start of the window to the last seen position of the current character
                start = ch[s[i]];
            }

            // Update the last seen position of the current character to the current index
            ch[s[i]] = i;

            // Calculate the length of the current substring without repeating characters
            // Update the result if the current length is longer than the previous result
            result = std::max(result, i - start);
        }

        // Return the length of the longest substring without repeating characters
        return result;
    }
};
