//question : https://leetcode.com/problems/minimum-window-substring/description/

class Solution {
public:
    string minWindow(string s, string t) {
        // If t is larger than s, no valid window can exist
        if(t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> m;  // Frequency map to count characters in t
        int n = s.size();            // Length of string s

        // Populate the frequency map with characters in t
        for(auto it : t) {
            m[it]++;
        }

        int totaltcount = t.size();  // Total characters to match from t in s
        int startindex = 0;          // Start index of the current window
        pair<int, int> range = {0, INT_MAX};  // Stores the start and end indices of the minimum window
        int endindex = 0;            // End index of the current window

        // Expand the window by extending the end index
        for(; endindex < n; endindex++) {
            // If current character is in t and still needed
            if(m.find(s[endindex]) != m.end() && m[s[endindex]] > 0) {
                totaltcount--;  // Decrease count of characters left to match
            }
            m[s[endindex]]--;  // Decrease frequency of current character in map

            // If all characters are matched
            if(totaltcount == 0) {
                // Contract the window from the start to find the minimum length
                while(m.find(s[startindex]) != m.end() && m[s[startindex]] != 0) {
                    m[s[startindex]]++;  // Restore character count as we contract
                    startindex++;        // Move start index forward
                }

                // Update the minimum range if the current window is smaller
                if((range.second - range.first) > (endindex - startindex)) {
                    range.first = startindex;
                    range.second = endindex;
                }

                // Prepare for the next possible window by restoring character count
                totaltcount++;
                m[s[startindex]]++;
                startindex++;  // Move start index forward
            }
        }

        // Debug output to check the start and end index of the result window
        std::cout << "startindex: " << range.first << " endindex: " << range.second << std::endl;

        // If no valid window was found, return an empty string
        if(range.second > s.size()) {
            return "";
        }

        // Return the minimum window substring
        return s.substr(range.first, range.second - range.first + 1);
    }
};
