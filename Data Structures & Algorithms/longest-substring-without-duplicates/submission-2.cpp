#include <unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1)
        {
            return 1; 
        }
        int left = 0; 
        int right = 1; 
        int maxLength = 0; 
        std::unordered_set<char> set; 
        set.insert(s[left]); 
        while(right < s.size())
        {
            if(set.find(s[right]) != set.end())
            {
                if(right - left > maxLength)
                {
                    maxLength = right - left; 
                }
                while(left < right)
                {
                    if(set.find(s[right]) == set.end())
                    {
                        break; 
                    }
                    else 
                    {
                        set.erase(s[left]); 
                        left++; 
                    }
                }
            }
            else 
            {
                set.insert(s[right]); 
                right++; 
                if(right - left > maxLength)
                {
                    maxLength = right - left; 
                }
            }
        }
        return maxLength; 
    }
};
