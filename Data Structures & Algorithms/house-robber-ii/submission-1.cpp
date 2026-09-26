class Solution {
public:
    int rob(vector<int>& nums) {
        //what if we calculate 2 values, if we use the first value, we can't use the last value
        //and if we don't use the first value, we can't use the last value
        //does that solve the whole constraint?
        if(nums.size() == 1)
        {
            return nums[0]; 
        }
        if(nums.size() == 2)
        {
            return max(nums[0], nums[1]); 
        }

        vector<int> dp(nums.size() - 1); 
        //let's initialize the base cases
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]); 
        for(int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); 
        }
        int max_dp = dp[dp.size() - 1]; 

        dp = vector<int>(nums.size() - 1); 
        dp[0] = nums[1]; 
        dp[1] = max(nums[1], nums[2]); 
        for(int i = 2; i < nums.size() - 1; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i + 1], dp[i - 1]); 
        }
        if(dp[dp.size() - 1] > max_dp)
        {
            return dp[dp.size() - 1]; 
        }
        else
        {
            return max_dp; 
        }
    }
};
