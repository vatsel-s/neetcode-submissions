class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets; 
        vector<int> val; 
        subsets.push_back(val); 
        for(int i = 0; i < nums.size(); i++)
        {
            findSubsets(subsets, val, nums, i);
        } 
        return subsets; 
    }

    void findSubsets(vector<vector<int>>& results, vector<int> curr, vector<int> nums, int index)
    {
        curr.push_back(nums[index]);
        results.push_back(curr); 
        for(int i = index + 1; i < nums.size(); i++)
        {
            findSubsets(results, curr, nums, i); 
        }
    }
};
