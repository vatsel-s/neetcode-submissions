#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false; 
        }
        std::unordered_map<char, int> word1; 
        std::unordered_map<char, int> word2; 
        for(unsigned int i = 0; i < s.size(); i++)
        {
            word1[s[i]]++; 
        }
        for(unsigned int i = 0; i < t.size(); i++)
        {
            word2[t[i]]++; 
        }
        for(unsigned int i = 0; i < s.size(); i++)
        {
            if(word1[s[i]] != word2[s[i]])
            {
                return false; 
            }
        }
        return true; 

    }
};
