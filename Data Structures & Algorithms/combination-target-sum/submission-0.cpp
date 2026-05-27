class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result; 
        vector<int> curr; 
        addSum(result, nums, curr, target, 0, 0); 
        return result; 
    }

    void addSum(vector<vector<int>>& result, vector<int> nums, vector<int>& curr, int target, int sum, int index)
    {
        if(sum > target)
        {
            return; 
        }
        else if(sum == target)
        {
            result.push_back(curr);    
            return; 
        }
        else 
        {
            //cout << sum << " " << target << endl; 
            for(int i = index; i < nums.size(); i++)
            {
                vector<int> temp = curr; 
                temp.push_back(nums[i]); 
                addSum(result, nums, temp, target, sum + nums[i], i); 
            }
        }
    }
};
