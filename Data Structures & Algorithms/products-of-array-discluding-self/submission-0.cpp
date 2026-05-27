class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixArray; 
        prefixArray.push_back(1); 
        for(int i = 1; i < nums.size(); i++)
        {
            prefixArray.push_back(prefixArray[i-1] * nums[i-1]); 
        }
        vector<int> suffixArray(nums.size()); 
        suffixArray[nums.size() -1] = 1; 
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            suffixArray[i] = suffixArray[i+1] * nums[i+1]; 
        }
        vector<int> finalArr(nums.size()); 
        for(int i = 0; i < nums.size(); i++)
        {
            finalArr[i] = prefixArray[i] * suffixArray[i]; 
        }
        return finalArr; 
    }
};
