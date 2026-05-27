class Solution {
public:
    int climbStairs(int n) {
        vector<int> nums(n, 0); 
        nums[0] = 1; 
        nums[1] = 2; 
        for(int i = 2; i < nums.size(); i++)
        {
            nums[i] = nums[i-1] + nums[i-2]; 
        }
        return nums[nums.size()-1];
    }
};
