class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count; 
        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]++; 
        }
        vector<int> output; 
        for(auto iter = count.begin(); iter != count.end(); iter++)
        {
            if(iter->second > nums.size()/3)
            {
                output.push_back(iter->first); 
            }
        }
        return output; 
    }
};