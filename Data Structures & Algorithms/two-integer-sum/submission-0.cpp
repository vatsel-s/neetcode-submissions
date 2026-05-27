#include <unordered_set>
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map; 
        for(unsigned int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i]; 
            if(map.find(difference) != map.end())
            {
                vector<int> solution; 
                solution.push_back(map[difference]); 
                solution.push_back(i);
                return solution;  
            }
            map[nums[i]] = i;  
        }
        vector<int> sol; 
        return sol; 
    }
};
