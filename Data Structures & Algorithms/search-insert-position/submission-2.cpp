class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1; 
        while(left < right)
        {
            int med = (left + right)/2; 
            if(nums[med] == target)
            {
                return med; 
            }
            else if(nums[med] > target)
            {
                right = med - 1; 
            }
            else
            {
                left = med + 1; 
            }
        }
        if(target <= nums[left])
        {
            return left; 
        } 
        return left + 1; 
        
    }
};