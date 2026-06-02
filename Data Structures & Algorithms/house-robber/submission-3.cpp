class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> vals(nums.size()); 
        vals[0] = nums[0]; 
        if(nums.size() == 1)
        {
            return vals[0]; 
        }
        vals[1] = max(nums[0], nums[1]); 
        for(int i = 2; i < vals.size(); i++)
        {
            vals[i] = max(nums[i] + vals[i-2], vals[i-1]); 
        }
        return max(vals[vals.size() -1], vals[vals.size() -2]);
    }
};
