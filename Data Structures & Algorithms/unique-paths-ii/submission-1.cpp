class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> arr(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        arr[0][0] = 1; 
        for(int i = 0; i < obstacleGrid.size(); i++)
        {
            for(int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    arr[i][j] = 0; 
                }                 
                else 
                {
                    if(i - 1 >= 0 && obstacleGrid[i - 1][j] == 0)
                    {
                        arr[i][j] += arr[i-1][j]; 
                    }
                    if(j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                    {
                        arr[i][j] += arr[i][j-1]; 
                    }
                }
                //cout << arr[i][j] << " " << i << " " << j << endl; 
            }
        }
        return arr[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1]; 
    }
};