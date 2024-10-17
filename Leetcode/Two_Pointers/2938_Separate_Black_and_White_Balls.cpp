//Questions : https://leetcode.com/problems/separate-black-and-white-balls

class Solution {
public:
    long long minimumSteps(string s) {
        int start = 0;
        int end = s.size()-1;
        long long totalswaps = 0;
        while(start < end)
        {
            // std::cout<<s[start]<<" "<<s[end]<<std::endl;
            if(s[end] == '1')
            {
                end--;
            }
            else if(s[start] == '1')
            {
                if(s[end] == '0')
                {
                    swap(s[start], s[end]);
                    totalswaps += end - start;
                    start++;
                }
                else
                {
                    end--;
                }
            }
            else if(s[start] == '0')
            {
                start++;
            }
            else if(s[end] == '0' and s[start] == '0')
            {
                end--;
                start++;
            }
        }
        return totalswaps;
    }
};