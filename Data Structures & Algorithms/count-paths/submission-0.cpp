class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths; 
        for(int i = 0; i < m; i++)
        {
            if(i == 0)
            {
                vector<int> row(n, 1); 
                paths.push_back(row);
            } 
            else 
            {
                vector<int> row(n); 
                paths.push_back(row);
            }
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0)
                {
                    paths[i][j] = paths[i-1][j]; 
                }
                else 
                {
                    paths[i][j] = paths[i-1][j] + paths[i][j-1]; 
                }
            }
        }
        return paths[m-1][n-1]; 
    }
};
