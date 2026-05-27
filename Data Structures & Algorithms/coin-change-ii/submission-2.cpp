class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
        {
            return 1; 
        }
        vector<vector<int>> count; 
        for(int i = 0; i < coins.size(); i++)
        {
            vector<int> val(amount); 
            count.push_back(val); 
        } 
        for(int i = 0; i < coins.size(); i++)
        {
            count[i][coins[i] - 1] = 1; 
            for(int j = 0; j < amount; j++)
            {
                for(int k = i; k < coins.size(); k++)
                {
                    if(j + coins[k] < amount)
                    {
                        count[k][j + coins[k]]+=count[i][j]; 
                    }
                }
            }
        }
        for(int i = 0; i < count.size(); i++)
        {
            for(int j = 0; j < count[0].size(); j++)
            {
                cout << count[i][j] << " "; 
            }
            cout << endl; 
        }
        int totalCount = 0; 
        for(int i = 0; i < coins.size(); i++)
        {
            totalCount+=count[i][amount-1]; 
        }
        return totalCount; 
    }
};
