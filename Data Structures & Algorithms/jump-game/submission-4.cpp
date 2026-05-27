class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = nums[0]; 
        for(int i = 1; i <= index; i++)
        {
            if(index >= nums.size())
            {
                return true; 
            }
            index = max(index, i + nums[i]); 
        }
        return (index >= nums.size() - 1);
    }
};
