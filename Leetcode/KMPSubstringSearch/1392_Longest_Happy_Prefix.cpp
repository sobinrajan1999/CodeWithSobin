//question : https://leetcode.com/problems/longest-happy-prefix/description/

//Prerequisite : KMP substring search

class Solution {
public:
    //array to store the Longest Prefix and Suffix
    vector<int> arr;

    std::string prefixsuffixarray(std::string s)
    {
        int i = 1;
        int j = 0;
        arr[0] = 0;
        //loop to iterate over all the string characters
        while(i < s.size())
        {
            //if i and j are equal
            if(s[i] == s[j])
            {
                arr[i] = j + 1;
                i++;
                j++;
                
            }
            else
            {
                if(j == 0)
                {
                    arr[i] = 0;
                    i++;
                }
                else
                {
                    j = arr[j-1];
                }
                
            }
        }

        return s.substr(0,j);
    }

    string longestPrefix(string s) {
        int n = s.size();
        arr = vector<int>(n, 0);
        return prefixsuffixarray(s);
    }
};