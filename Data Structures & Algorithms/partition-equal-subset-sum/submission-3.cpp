class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() == 2)
        {
            return (nums[0] == nums[1]); 
        }
        
        int sum = 0; 
        for(int i = 0; i < nums.size(); i++)
        {
            sum+=nums[i]; 
        }
        if(sum%2 == 1)
        {
            return false; 
        }
        int half = sum/2; 
        vector<vector<int>> count; 
        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> val(half); 
            count.push_back(val); 
        }
        count[0][nums[0] - 1] = 1; 
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < half; j++)
            {
                for(int k = i + 1; k < nums.size(); k++)
                {
                    if(count[i][j] == 1 && j + nums[k] == half - 1)
                    {
                        return true; 
                    }
                    else if(count[i][j] == 1 && j + nums[k] < half - 1)
                    {
                        count[k][j + nums[k]] = 1; 
                    }
                }
            }
        }
        return false; 

    }
};
