class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> curr; 
        addPermutations(result, curr, nums); 
        return result; 
    }

    void addPermutations(vector<vector<int>>& result, vector<int> curr, vector<int> toUse)
    {
        if(toUse.size() == 0)
        {
            result.push_back(curr); 
        }
        else 
        {
            for(int i = 0; i < toUse.size(); i++)
            {
                vector<int> temp_curr = curr;
                vector<int> temp_use = toUse;  
                temp_curr.push_back(toUse[i]); 
                temp_use.erase(temp_use.begin() + i); 
                addPermutations(result, temp_curr, temp_use); 
            }
        }
    }
};
