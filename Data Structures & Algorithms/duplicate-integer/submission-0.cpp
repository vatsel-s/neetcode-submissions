#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> vals; 
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            if(vals.find(nums[i]) != vals.end())
            {
                return true; 
            }
            vals.insert(nums[i]); 
        }
        return false; 
    }
};
