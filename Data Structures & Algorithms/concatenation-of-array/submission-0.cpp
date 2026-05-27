class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> concat(nums.size() * 2); 
        for(int i = 0; i < nums.size(); i++)
        {
            concat[i] = nums[i]; 
            concat[i + nums.size()] = nums[i]; 
        }
        return concat;
    }
};