//Question : https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    long long isPalindrome(std::string str, long long left, long long right)
    {
        while(left >=0 && right < str.size() && str[left] == str[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        //if empty then answer is empty
        if(s.empty())
        {
            return "";
        }
        //if only one char then answer is that one char
        else if(s.size() == 1)
        {
            return s;
        }

        long long maxString = 0;
        std::string finalString = "";
        
        for(auto i = 0; i< s.size(); i++)
        {
            //we will be taking i as the center of the string 
            long long first = isPalindrome(s, i, i);
            //first will have the length of the palindrome, then we will take that substring as our answer if it is the largest palindrome
            if(first > maxString)
            {
                maxString = first;
                long long half = maxString/2;
                finalString = s.substr(i - half, maxString);
            }
            //this is when palindrome is an even length substring. performing the same operation.
            long long second = isPalindrome(s, i, i+1);
            if(second > maxString)
            {
                maxString = second;
                long long half = maxString/2;
                finalString = s.substr(i - half + 1, maxString);
            }
        }
        //returning the final substring
        return finalString;
    }
};