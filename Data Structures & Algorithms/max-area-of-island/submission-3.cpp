class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0; 
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
                std::cout << "\n";
                if(grid[i][j] == 1 && searched[i][j] == false)
                {
                    int area = 0; 
                    vector<std::pair<int, int>> queue; 
                    std::pair<int, int> val(i, j); 
                    queue.push_back(val); 
                    searched[i][j] = true; 
                    area++; 
                    while(queue.size() != 0)
                    {
                        std::pair<int, int> current = queue[0]; 
                        queue.erase(queue.begin()); 
                        int curr_row = current.first; 
                        int curr_col = current.second; 
                        std::cout << curr_row << " " << curr_col << std::endl; 
                        if(curr_row + 1 < grid.size() && (searched[curr_row + 1][curr_col] == false && grid[curr_row + 1][curr_col] == 1))
                        {
                            std::pair<int, int> val(curr_row + 1, curr_col); 
                            queue.push_back(val); 
                            searched[curr_row + 1][curr_col] = true; 
                            area++; 
                        }
                        if(curr_row - 1 >= 0 && (searched[curr_row - 1][curr_col] == false && grid[curr_row - 1][curr_col] == 1))
                        {
                            std::pair<int, int> val(curr_row - 1, curr_col); 
                            queue.push_back(val); 
                            searched[curr_row -1][curr_col] = true; 
                            area++; 
                        }
                        if(curr_col + 1 < grid[0].size() && (searched[curr_row][curr_col + 1] == false && grid[curr_row][curr_col +1] == 1))
                        {
                            std::pair<int, int> val(curr_row, curr_col + 1); 
                            queue.push_back(val); 
                            searched[curr_row][curr_col + 1] = true; 
                            area++; 
                        }
                        if(curr_col - 1 >= 0 && (searched[curr_row][curr_col -1] == false && grid[curr_row][curr_col -1] == 1))
                        {
                            std::pair<int, int> val(curr_row, curr_col -1); 
                            queue.push_back(val); 
                            searched[curr_row][curr_col-1] = true; 
                            area++; 
                        }
                    }
                    if(area > maxArea)
                    {
                        maxArea = area; 
                    }
                }
            }
        }
        return maxArea; 
    }
};
