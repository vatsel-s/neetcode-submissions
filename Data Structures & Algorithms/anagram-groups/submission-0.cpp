#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> result; 
        std::unordered_map<string, vector<string>> map; 
        for(unsigned int i = 0; i < strs.size(); i++)
        {
            string key; 
            string current = strs[i]; 
            std::map<char, int> frequency; 
            for(unsigned int j = 0; j < current.size(); j++)
            {
                frequency[current[j]]++; 
            }
            for(auto it = frequency.begin(); it != frequency.end(); it++)
            {
                key += it->first; 
                key += to_string(it->second); 
            }
            map[key].push_back(current); 
        }
        for(auto iter = map.begin(); iter != map.end(); iter++)
        {
            result.push_back(iter->second); 
        }
        return result; 
    }
};
