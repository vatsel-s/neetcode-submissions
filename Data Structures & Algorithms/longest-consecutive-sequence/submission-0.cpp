#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> map; 
        for(int i = 0; i < nums.size(); i++)
        {
            map[nums[i]] = nums[i] + 1; 
        }
        int longestCount = 0; 
        for(int i = 0; i < nums.size(); i++)
        {
            int count = 0; 
            int current = nums[i]; 
            while(map.find(current) != map.end())
            {
                current = map[current]; 
                count++; 
            }
            if(count > longestCount)
            {
                longestCount = count; 
            }
        }
        return longestCount; 
    }
};
