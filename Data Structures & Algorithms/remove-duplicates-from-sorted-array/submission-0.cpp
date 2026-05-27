class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr_value = nums[0]; 
        int index = 1; 
        while(index < nums.size())
        {
            if(nums[index] == curr_value)
            {
                nums.erase(nums.begin() + index); 
            }
            else
            {
                curr_value = nums[index]; 
                index++; 
            }
        }
        return index; 
    }
};