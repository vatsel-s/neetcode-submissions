class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1); 
    }
    int binarySearch(vector<int> nums, int target, int lowerBound, int upperBound)
    {
        if(upperBound < lowerBound)
        {
            return -1; 
        }
        int median = (upperBound + lowerBound)/2; 
        if(nums[median] == target)
        {
            return median; 
        }
        else if(nums[median] < target)
        {
            return binarySearch(nums, target, median + 1, upperBound); 
        }
        else 
        {
            return binarySearch(nums, target, lowerBound, median - 1); 
        }
    }
};
