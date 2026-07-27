class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> minSums(grid.size(), vector<int>(grid[0].size(), 0)); 
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {

                if(i == 0 && j == 0)
                {
                    minSums[i][j] = grid[i][j];
                }
                else if(i == 0)
                {
                    minSums[i][j] = minSums[i][j - 1] + grid[i][j]; 
                }
                else if(j == 0)
                {
                    minSums[i][j] = minSums[i - 1][j] + grid[i][j];
                }
                else
                {
                    minSums[i][j] = min(minSums[i - 1][j] + grid[i][j], minSums[i][j - 1] + grid[i][j]); 
                }
                cout << minSums[i][j] << endl; 
            }
        }
        
        return minSums[grid.size() - 1][grid[0].size() - 1]; 
    }
};