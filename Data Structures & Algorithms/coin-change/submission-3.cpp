class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
        {
            return 0; 
        }
        vector<int> nums(amount + 1);
        for(int i = 0; i < coins.size(); i++)
        {
            if(coins[i] <= amount)
            {
                nums[coins[i]] = 1; 
            }
        } 
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                for(int j = 0; j < coins.size(); j++)
                {
                    if(i + coins[j] <= amount && i + coins[j] > 0)
                    {
                        cout << i + coins[j] << " " << amount << endl; 
                        if(nums[i+coins[j]] == 0 || nums[i + coins[j]] > nums[i] + 1)
                        {
                            nums[i + coins[j]] = nums[i] + 1; 
                        }
                    }
                }
            }
        }
        if(nums[amount] == 0)
        {
            return -1; 
        }
        return nums[amount]; 
    }
};
