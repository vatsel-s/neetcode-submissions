class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vals(nums.size(), 1); 

        for(int i = nums.size() - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] < nums[j])
                {
                    vals[i] = max(vals[i], 1 + vals[j]); 
                }
            }
        }
        int max = 0; 
        for(int i = 0; i < vals.size(); i++)
        {
            if(vals[i] > max)
            {
                max = vals[i]; 
            }
        }
        return max; 
    }
};
