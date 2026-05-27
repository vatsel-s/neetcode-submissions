class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //basic idea: go through the all the grid, make a boolean array to 
        //say whether they have been explored already, and then 
        int numIslands = 0; 
        vector<vector<bool>> searched; 
        for(int i = 0; i < grid.size(); i++)
        {
            vector<bool> val; 
            for(int j = 0; j < grid[0].size(); j++)
            {
                val.push_back(false); 
            }
            searched.push_back(val); 
        }
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && searched[i][j] == false)
                {
                    numIslands++; 
                    vector<std::pair<int, int>> queue; 
                    std::pair<int, int> val(i, j); 
                    queue.push_back(val); 
                    cout << i << " " << j << std::endl; 
                    while(queue.size() != 0)
                    {
                        std::pair<int, int> current = queue[0]; 
                        queue.erase(queue.begin()); 
                        searched[current.first][current.second] = true; 
                        int curr_row = current.first; 
                        int curr_col = current.second; 
                        if(curr_row + 1 < grid.size() && (searched[curr_row + 1][curr_col] == false && grid[curr_row + 1][curr_col] == '1'))
                        {
                            std::pair<int, int> val(curr_row + 1, curr_col); 
                            queue.push_back(val); 
                        }
                        if(curr_row - 1 >= 0 && (searched[curr_row - 1][curr_col] == false && grid[curr_row - 1][curr_col] == '1'))
                        {
                            std::pair<int, int> val(curr_row - 1, curr_col); 
                            queue.push_back(val); 
                        }
                        if(curr_col + 1 < grid[0].size() && (searched[curr_row][curr_col + 1] == false && grid[curr_row][curr_col +1] == '1'))
                        {
                            std::pair<int, int> val(curr_row, curr_col + 1); 
                            queue.push_back(val); 
                        }
                        if(curr_col - 1 >= 0 && (searched[curr_row][curr_col -1] == false && grid[curr_row][curr_col -1] == '1'))
                        {
                            std::pair<int, int> val(curr_row, curr_col -1); 
                            queue.push_back(val); 
                        }
                    }
                }
            }
        }
        return numIslands; 
    }
};
